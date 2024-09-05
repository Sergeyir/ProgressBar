// $HEADER$
//------------------------------------------------------------------------------------------------
//                                    PBar style structure
//------------------------------------------------------------------------------------------------
// PBar: progress bar
//
// ** Free and open code for anyone to use **
//
// Author: Sergei Antsupov
//
/**
 * Set of styles for a PBar
 **/
//------------------------------------------------------------------------------------------------

#ifndef PBARSTYLE_HPP
#define PBARSTYLE_HPP

#include <string>
#include <map>

#include "PBarColors.hpp"

namespace PBStyle
{
   //some symbols are thicker than the width that cpp calculates: 
   //for those \r and empty spaces are used
   static std::map<std::string, std::array<std::string, 6>> map = 
   {
      {"DEFAULT", {"[", "#", "", ".", "]", PBarColor::BOLD_CYAN}},
      {"IMPROVED", {"⁅", "⁜", "⊳", "~", "⁆", PBarColor::BOLD_CYAN}},
      {"FANCY", {"◨▣", "▩", "▧", "▫", "▣◧", PBarColor::BOLD_CYAN}},
      {"FANCY1", {"●", "◎", "○", "◌", "●", PBarColor::BOLD_CYAN}},
      {"FANCY2", {"\r  「", "※", "※", "※", " 」", PBarColor::BOLD_RED}},
      {"WAVE", {"\r  「", "₪", " ", " ", " 」", PBarColor::BOLD_CYAN}},
      {"BLOCK", {"", "▓", "▒", "▒", "", PBarColor::BLUE}},
      {"BLOCK1", {"█", "▓", "▒", "▒", "█", PBarColor::MAGENTA}},
      {"BLOCK2", {"◢█", "▓", "▒", "▒", "█◤", PBarColor::BOLD_YELLOW}}
   };

   static std::map<std::string, std::array<std::string, 6>> secretMap = 
   {
      {"SUS", {"SUS ", "ඞ", "ච", "○", " SUS", PBarColor::BOLD_RED}},
      {"COMMUNISM", {"☭", "✭", "☆", " ", "☭", PBarColor::BOLD_RED}},
      {"GACHI", {"CUM ", "♂", "○", "♀", " ASS", PBarColor::BOLD_WHITE}}
   };
} 

#endif /*PBARSTYLE_HPP*/
