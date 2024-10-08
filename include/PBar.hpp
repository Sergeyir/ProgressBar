// $HEADER$
//------------------------------------------------------------------------------------------------
//                                  ProgressBar class declaration
//------------------------------------------------------------------------------------------------
// PBar: progress bar
//
// ** Free and open code for anyone to use **
//
// Author: Sergei Antsupov
// Email: antsupov0124@gmail.com
//
/**
 * Basic fast customizable graphic terminal display of a process progress in a form of an ascii bar
 **/
//------------------------------------------------------------------------------------------------

#ifndef PROGRESS_BAR_HPP
#define PROGRESS_BAR_HPP

#include <iostream>
#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <array>

#include "PBarStyle.hpp"

class ProgressBar
{
   public:
   
   ProgressBar(std::string style = "DEFAULT", const std::string& customText = "", 
               const std::string& color = "");
   ProgressBar(const std::string& customLeftBorder, const char customCompleteSymbol, 
               const char customNextCompleteSymbol, const char customNotCompleteSymbol,
               const std::string& customRightBorder, const std::string& color, 
               const std::string& customText = "");
   
   void SetColor(const std::string& color);
   void SetStyle(std::string style, const std::string& color);
   void SetCustomStyle(const std::string& customLeftBorder, const char customCompleteSymbol, 
                       const char customNextCompleteSymbol, const char customNotCompleteSymbol,
                       const std::string& customRightBorder, const std::string& color);
   void SetWidth(const short customWidth);
   void SetText(const std::string& customText);
   void Print(const double progress);
   void Clear();
   void RePrint();
   void Fill(); 
   void Reset();
   void SetBarStep(const double step);
   void SetPrecision(const short precision);
   
   template <typename... T>
   void HandleOutput(T... args)
   {
      if (printedProgress < 1.) Clear();
      
      ((std::cout << args << " "), ...);
      std::cout << std::endl;
      
      if (printedProgress > 1.) return;
      RePrint();
   }
   
   virtual ~ProgressBar();
   
   protected:

   const short EMPTY_SPACE_WIDTH = 4; //number of empty spaces in columns in a progress bar
      
   std::string barText;

   std::string barColor;
   std::string leftBorder, rightBorder;
   std::string completeSymbol, nextCompleteSymbol, notCompleteSymbol;
   
   //number of columns in the terminal window or the maximum length in columns the progress bar
   //(including text) can take if specified by the user with SetWidth method
   short fullWidth;
   //keeping the length of the body of the bar (borders + body symbols) for simpler calculations
   short barBodyWidth;
   
   double barStep = 0.01;
   double printedProgress = -0.01;
   short barPrecision = 0;

   struct winsize terminalWindow;

   short utf8_strlen (const std::string& str);
   short GetTerminalWidth();
   std::string DtoStr (const double val, const short precision = 2);
};

#endif /*PROGRESS_BAR_HPP*/
