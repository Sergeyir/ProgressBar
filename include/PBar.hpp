/** 
 *  @file PBar.hpp 
 *  @brief Contains declaration of class ProgressBar
 *
 *  This file is a part of a project ProgressBar (https://github.com/Sergeyir/ProgressBar).
 *
 *  @author Sergei Antsupov (antsupov0124@gmail.com)
 **/
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

/*! @class ProgressBar
 * @brief Class ProgressBar can be used used to print the progress in an ascii horizontal bar. See example on it's implementation below
 *
 * @example test.cpp Simpest usage of ProgressBar
 * @example possibilities.cpp Example that shows different ways to use ProgressBar
 * @example style.cpp When executed this example allows to test different styles of ProgressBar
 * @example handle_output.cpp Example on usage of ProgressBar showing how to handle output in terminal while ProgressBar is in progress
 * @example mt.cpp Example on simplest usage of ProgressBar in multithreaded applications
 * @example speed.cpp When executed this examples shows how much time it takes for calling ProgressBar::Print(progress) 1 billion times
 */
class ProgressBar
{
   public:
   
   /*! @brief Constructor that creates ProgressBar instance with predefined style
    * @param[in] style predefined style of the bar. Currently there are 9 predefined styles ("DEFAULT", "IMPROVED", "FANCY", "FANCY1", "FANCY2", "WAVE", "BLOCK", "BLOCK1", "BLOCK2" (for more info see examples) and can be passed as a string in upper and/or lower case )
    * @param[in] customText text to be printed on the left of the bar
    * @param[in] color color of the bar (see PBColor namespace). By default each predefined style has it's own default color, which will be used if the default arguments is passed
    */
   ProgressBar(std::string style = "DEFAULT", const std::string& customText = "", 
               const std::string& color = "");
   /*! @brief Constructor that creates ProgressBar instance with custom style
    * @param[in] customLeftBorder left border of the bar
    * @param[in] customCompleteSymbol symbol that denotes filled positions in a bar
    * @param[in] customNextCompleteSymbol symbol that denotes current position of a progress in a bar
    * @param[in] customNotCompleteSymbol symbol that denotes positions to be filled in a bar
    * @param[in] customRightBorder right border of the bar
    * @param[in] color color of the bar (see PBColor namespace)
    * @param[in] customText text to be printed on the left of the bar
    */
   ProgressBar(const std::string& customLeftBorder, const char customCompleteSymbol, 
               const char customNextCompleteSymbol, const char customNotCompleteSymbol,
               const std::string& customRightBorder, const std::string& color, 
               const std::string& customText = "");
   /*! @brief Set color of progess bar
    * @param[in] color color of the bar (see PBColor namespace)
    */
   void SetColor(const std::string& color);
   /*! @brief Set predefined style of progess bar
    * @param[in] style predefined style of the bar. Currently there are 9 predefined styles ("DEFAULT", "IMPROVED", "FANCY", "FANCY1", "FANCY2", "WAVE", "BLOCK", "BLOCK1", "BLOCK2" (for more info see examples) and can be passed as a string in upper and/or lower case )
    * @param[in] color color of the bar (see PBColor namespace). By default each predefined style has it's own default color, which will be used if the default arguments is passed
    */
   void SetStyle(std::string style, const std::string& color);
   /*! @brief Set custom style of progress bar
    * @param[in] customLeftBorder left border of the bar
    * @param[in] customCompleteSymbol symbol that denotes filled positions in a bar
    * @param[in] customNextCompleteSymbol symbol that denotes current position of a progress in a bar
    * @param[in] customNotCompleteSymbol symbol that denotes positions to be filled in a bar
    * @param[in] customRightBorder right border of the bar
    * @param[in] color color of the bar (see PBColor namespace)
    * @param[in] customText text to be printed on the left of the bar
    */
   void SetCustomStyle(const std::string& customLeftBorder, const char customCompleteSymbol, 
                       const char customNextCompleteSymbol, const char customNotCompleteSymbol,
                       const std::string& customRightBorder, const std::string& color);
   /*! @brief Set the width of the progress bar
    * @param[in] customWidth width of the progress bar. By defaul the width of the progress bar is the width of terminal  
    */
   void SetWidth(const short customWidth);
   /*! @brief Set text of a bar
    * @param[in] customText text to be printed on the left of the bar
    */
   void SetText(const std::string& customText);
   /*! @brief Prints bar
    * @param[in] progress progress value ranging from 0. to 1. (complete)
    *
    * This functions automaticaly checks if it should be printed so there is no worry that printing the bar will take all resources. The check is also very fast which allows for the ProgressBar to be very fast (see speed.cpp in examples directory)
    */
   void Print(const double progress);
   /*! @brief Clears the printed bar
    *
    * This function should only be used when using ProgressBar::RePrint. It will clear the last line the cursor is on. So if the user is not paying attention data from terminal will be erased.
    */
   void Clear();
   /*! @brief Prints the progress bar without checking if it should be printed
    *
    * This function should not be used to often since no checking means that it can take a lot of resources to print the bar a lot of times in terminal. Use only when you cannot redirect outputs to ProgressBar::HandleOutput (see handle_output.cpp in examples directory) 
    */
   void RePrint();
   /*! @brief Completely fills the progress of the bar (puts it to 1)
    */
   void Fill(); 
   /*! @brief Resets the progress of the bar (puts it to 0)
    */
   void Reset();
   /*! @brief Set the step of the progress the ProgressBar should be printed upon reaching
    *
    * @param[in] step this value determines the frequency of printing the progress bar into the terminal. Do not set the value too low otherwise it will take a lot of resources to print the bar many times. The default value is 0.01 (progress bar will be printed 100 times with this value)
    */
   void SetBarStep(const double step);
   /*! @brief Set the precision of the progress indicator
    *
    * @param[in] precision floating point precision of the progress indicator (default is 0)
    */
   void SetPrecision(const short precision);
   
   /*! @brief Rerouts the output in the terminal so the ProgressBar will not be interrupted.
    *
    * @param[in] args parameter pack which will be printed.
    *
    * Functions similarly to python print function. But current function will also erase the last bar and reprint it after it has printed the passed output. So this function should not be used too often since reprinting the body of the progress bar a lot of times can take significant resources. On how to use see handle_output.cpp in examples directory.
    */
   template <typename... T>
   void HandleOutput(T... args)
   {
      if (printedProgress < 1.) Clear();
      
      ((std::cout << args << " "), ...);
      std::cout << std::endl;
      
      if (printedProgress > 1.) return;
      RePrint();
   }
   
   /// @brief Default destructor
   virtual ~ProgressBar();
   
   protected:

   /// @brief Get the length of the string containing UTF8 symbols
   short utf8_strlen (const std::string& str);
   /// @brief Get the width of the current terminal
   short GetTerminalWidth();
   /// @brief Convert double to std::string with a give precision
   std::string DtoStr (const double val, const short precision = 2);
   
   /// Number of empty spaces in a progress bar line (2 on very the edges, 1 between text and a bar, and 1 between bar and progress indicator)
   const short EMPTY_SPACE_WIDTH = 4; 
      
   /// Text to be printed on the left of the progress bar
   std::string barText;

   /// Color of the progress bar
   std::string barColor;
   /// Left border of a bar
   std::string leftBorder;
   /// Right border of a bar
   std::string rightBorder;
   /// Bar body symbol indicating filled positions in a bar; comes after leftBorder before completeSymbol
   std::string completeSymbol;
   /// Bar body symbol indicating current progress; comes after the last completeSymbol and before first 
   std::string nextCompleteSymbol;
   /// Bar body symbol indicating not yet filled positions in a bar; comes after completeSymbol and before rightBorder
   std::string notCompleteSymbol;
   
   /// The length of the bar
   short fullWidth;
   /// The length of the body of the bar (borders + body symbols)
   short barBodyWidth;
   
   /// Bar step. 1/barStep is the overall number of times ProgressBar will be printed before it is filled
   double barStep = 0.01;
   /// Variable that tracks the progress of a last progress bar printed. Used for progress checks to decrease the number of times ProgressBar is printed
   double printedProgress = -0.01;
   /// Bar precision
   short barPrecision = 0;

   /// Terminal window struct; used to acquire the width of the terminal
   struct winsize terminalWindow;
};

#endif /* PROGRESS_BAR_HPP */
