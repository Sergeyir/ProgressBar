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

   ProgressBar(std::string style = "DEFAULT", std::string left_text = "", 
               std::string color = "", const int default_width = 100);
   ProgressBar(std::string custom_left_border, const char custom_complete, 
               const char custom_next_complete, const char custom_not_complete,
               std::string custom_right_border, std::string color, 
               std::string left_text = "", const int default_width = 100);
   
   void SetColor(std::string color);
   void SetStyle(std::string style, std::string color = "");
   void SetCustomStyle(std::string custom_left_border, const char custom_complete, 
                       const char custom_next_complete, const char custom_not_complete,
                       std::string custom_right_border, std::string color);
   void SetWidth(const int default_width);
   void SetText(std::string left_text);
   void Print(const double progress);
   void Clear();
   void RePrint();
   void Fill(); 
   void Reset();
   void SetBarStep(const double step);
   void SetPrecision(const int precision);

   ~ProgressBar();
   
   protected:
      
   std::string text;

   std::string bar_color;
   std::string left_border, right_border;
   std::string complete, next_complete, not_complete;
   
   int default_bar_width;
   int orig_default_width;
   
   double bar_step = 0.01;
   double bar_progress = -0.01;
   int bar_precision = 0;

   struct winsize w;

   int utf8_strlen (const std::string& str);
   std::string CheckStyle (std::string style);
   std::string DtoStr (const double val, const int precision = 2);
};

#endif
