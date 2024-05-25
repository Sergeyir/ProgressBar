#pragma once
//#ifndef PBARSTYLE_HPP
//#define PBARSTYLE_HPP

#include <string>
#include <map>

namespace PBStyle
{
   static std::map<std::string, std::array<std::string, 6>> map = 
   {
      {"DEFAULT", {"[", "#", "", ".", "]", OutputColor::bold_cyan}},
      {"IMPROVED", {"⁅", "⁜", "⊳", "~", "⁆", OutputColor::bold_cyan}},
      {"FANCY", {"◨▣", "▩", "▧", "▫", "▣◧", OutputColor::bold_cyan}},
      {"FANCY1", {"●", "◎", "○", "◌", "●", OutputColor::bold_cyan}},
      {"FANCY2", {"「", "※", "※", "※", " 」", OutputColor::bold_red}},
      {"WAVE", {"「", "₪", " ", " ", "」", OutputColor::bold_cyan}},
      {"BLOCK", {"", "▓", "▒", "▒", "", OutputColor::blue}},
      {"BLOCK1", {"█", "▓", "▒", "▒", "█", OutputColor::magenta}},
      {"BLOCK2", {"◢█", "▓", "▒", "▒", "█◤", OutputColor::bold_yellow}},
      {"GACHI", {"CUM ", "♂", "○", "♀", " ASS", OutputColor::bold_white}},
      {"SUS", {"SUS ", "ඞ", "ච", "○", " SUS", OutputColor::bold_red}},
      {"COMMUNISM", {"☭", "✭", "☆", " ", "☭", OutputColor::bold_red}}
   };
} 

//#endif
