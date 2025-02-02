/** 
 *  @file PBar.cpp 
 *  @brief Contains realisation of class ProgressBar
 *
 *  This file is a part of a project ProgressBar (https://github.com/Sergeyir/ProgressBar).
 *
 *  @author Sergei Antsupov (antsupov0124@gmail.com)
 **/
#ifndef PBAR_CPP
#define PBAR_CPP

#include "../include/PBar.hpp"

ProgressBar::ProgressBar(std::string style, const std::string& customText, 
                         const std::string& color)
{
   fullWidth = GetTerminalWidth();
    
   SetStyle(style, color);
   SetText(customText);
}

ProgressBar::ProgressBar(const std::string& customLeftBorder, const char customCompleteSymbol, 
                         const char customNextComplete, const char customNotCompleteSymbol,
                         const std::string& customRightBorder, const std::string& color, 
                         const std::string& customText)
{
   fullWidth = GetTerminalWidth();
   
   SetCustomStyle(customLeftBorder, customCompleteSymbol, customNextComplete, 
      customNotCompleteSymbol, customRightBorder, color);
   
   SetText(customText);
}

void ProgressBar::SetColor(const std::string& color)
{
   barColor = color;
}

void ProgressBar::SetStyle(std::string style, const std::string& color)
{
   for (char &c : style) c = toupper(c);
   
   std::array<std::string, 6> stylePar;
   if (PBarStyle::map.find(style) == PBarStyle::map.end() && 
      PBarStyle::secretMap.find(style) == PBarStyle::secretMap.end()) 
   {
      std::cout << PBarColor::BOLD_MAGENTA << "Warning: " << PBarColor::RESET << 
         "Style \"" << style << "\" was not found; changing to \"DEFAULT\"" << std::endl;
      style = "DEFAULT";

      std::cout << "You can use one of the predefined styles: " << std::endl;

      for (auto const &x : PBarStyle::map)
      {
         std::cout << " " << x.first << std::endl;
      }
      
      std::cout << "Or create your custom style with the constuctor for the cutstom style \n \
      If you don't need the style you can leave the object declaration constructor empty; \n \
      the style will be automaticaly set to default without printing the warning" << std::endl;

      stylePar = PBarStyle::map["DEFAULT"];
   }
   else if (PBarStyle::map.find(style) != PBarStyle::map.end())
   {
      stylePar = PBarStyle::map[style.c_str()];
   }
   else 
   {
      stylePar = PBarStyle::secretMap[style.c_str()];
   }

   leftBorder = stylePar[0];
   rightBorder = stylePar[4];
   
   completeSymbol = stylePar[1];
   nextCompleteSymbol = stylePar[2];
   notCompleteSymbol = stylePar[3];

   if (color == "") SetColor(stylePar[5]);
   else SetColor(color);
}

void ProgressBar::SetCustomStyle(const std::string& customLeftBorder, 
                                 const char customCompleteSymbol, 
                                 const char customNextComplete, const char customNotCompleteSymbol,
                                 const std::string& customRightBorder, const std::string& color)
{
   leftBorder = customLeftBorder;
   rightBorder = customRightBorder;
   
   completeSymbol = customCompleteSymbol;
   nextCompleteSymbol = customNextComplete;
   notCompleteSymbol = customNotCompleteSymbol;

   barColor = color;
}

void ProgressBar::SetWidth(const short customWidth)
{
   barBodyWidth = customWidth - utf8_strlen(barText) - 
      utf8_strlen(leftBorder) - utf8_strlen(rightBorder) - EMPTY_SPACE_WIDTH;

   fullWidth = customWidth;
}

void ProgressBar::SetText(const std::string& customText)
{
   barText = customText;
   SetWidth(fullWidth);
}

void ProgressBar::Print(const double progress)
{   
   //checks if the progress exceeded the step from the previous one
   if (progress - barStep/2. <= printedProgress) return;
   //checks if the progress and printed progress of the bar both exceed 1
   if (progress > 1. + barStep/2. && printedProgress > 1. + barStep/2.) return;

   printedProgress = progress + barStep;
   
   RePrint();
}

void ProgressBar::RePrint()
{   
   std::string progressPercentage;
   if (printedProgress < 1.) progressPercentage = DtoStr((printedProgress) * 100.0, barPrecision);
   else progressPercentage = DtoStr(100., barPrecision);
   
   short barWidthToPrint;
   
   if (barBodyWidth > GetTerminalWidth()) 
   {
      barWidthToPrint = GetTerminalWidth() - fullWidth + 
      barBodyWidth - utf8_strlen(progressPercentage) - EMPTY_SPACE_WIDTH;
   }
   else barWidthToPrint = barBodyWidth - utf8_strlen(progressPercentage) - EMPTY_SPACE_WIDTH;
   
   short nextCompleteSymbolPosition = static_cast<short>(barWidthToPrint * printedProgress);

   std::stringstream barToPrint;
   
   barToPrint << "\r " << PBarColor::BOLD_WHITE << barText << " " << barColor << leftBorder;

   for (short i = 0; i < barWidthToPrint; i++)
   {
      if (i == nextCompleteSymbolPosition) barToPrint << nextCompleteSymbol + PBarColor::RESET;
      else if (i < nextCompleteSymbolPosition) barToPrint << completeSymbol;
      else barToPrint << notCompleteSymbol;
   }
   barToPrint << barColor + rightBorder;

   barToPrint << " " + PBarColor::BOLD_WHITE + "[" + 
      progressPercentage + "%]" + PBarColor::RESET + " ";

   std::cout << barToPrint.str() << "\r";
   std::cout.flush();

   if (printedProgress + barStep/2. >= 1) std::cout << std::endl;
}

void ProgressBar::Clear()
{
   for (short i = 0; i < GetTerminalWidth(); i++) std::cout << " ";
   std::cout << "\r";
}

void ProgressBar::Fill() {Print(1.1);}

void ProgressBar::Reset() {printedProgress = 0;}

void ProgressBar::SetBarStep(const double step) {barStep = step;}

void ProgressBar::SetPrecision(const short precision) {barPrecision = precision;}

short ProgressBar::utf8_strlen(const std::string& str)
{
   short len = 0;
   for (short i = 0; i < static_cast<short>(str.length()); i++, len++)
   {
      const unsigned char c = (unsigned char) str[i];
      if      (c >= 0 && c <= 127)   i+=0;
      else if ((c & 0xE0) == 0xC0)   i+=1;
      else if ((c & 0xF0) == 0xE0)   i+=2;
      else if ((c & 0xF8) == 0xF0)   i+=3;
      else return 0;
   }
   return len;
}

short ProgressBar::GetTerminalWidth()
{
   ioctl(STDOUT_FILENO, TIOCGWINSZ, &terminalWindow);
   return terminalWindow.ws_col;
}

std::string ProgressBar::DtoStr(const double val, const short precision)
{
   std::stringstream ssval;
   ssval << std::fixed << std::setprecision(precision) << val;
   return ssval.str();
}

ProgressBar::~ProgressBar() {};

#endif /* PBAR_CPP */
