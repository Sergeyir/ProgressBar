#pragma once
//#ifndef PBARSTYLE_HPP
//#define PBARSTYLE_HPP

#include <string>
#include <map>

#include "PBarColors.hpp"

namespace PBStyle
{
   static std::map<std::string, std::array<std::string, 6>> map = 
   {
      {"DEFAULT", {"[", "#", "", ".", "]", PBarColor::BOLD_CYAN}},
      {"IMPROVED", {"⁅", "⁜", "⊳", "~", "⁆", PBarColor::BOLD_CYAN}},
      {"FANCY", {"◨▣", "▩", "▧", "▫", "▣◧", PBarColor::BOLD_CYAN}},
      {"FANCY1", {"●", "◎", "○", "◌", "●", PBarColor::BOLD_CYAN}},
      {"FANCY2", {"「", "※", "※", "※", " 」", PBarColor::BOLD_RED}},
      {"WAVE", {"「", "₪", " ", " ", "」", PBarColor::BOLD_CYAN}},
      {"BLOCK", {"", "▓", "▒", "▒", "", PBarColor::BLUE}},
      {"BLOCK1", {"█", "▓", "▒", "▒", "█", PBarColor::MAGENTA}},
      {"BLOCK2", {"◢█", "▓", "▒", "▒", "█◤", PBarColor::BOLD_YELLOW}},
      {"GACHI", {"CUM ", "♂", "○", "♀", " ASS", PBarColor::BOLD_WHITE}},
      {"SUS", {"SUS ", "ඞ", "ච", "○", " SUS", PBarColor::BOLD_RED}},
      {"COMMUNISM", {"☭", "✭", "☆", " ", "☭", PBarColor::BOLD_RED}}
   };
} 

//#endif
