/** 
 *  @file   PBarStyle.hpp 
 *  @brief Contains map of styles for ProgressBar class
 *
 *  This file is a part of a project https://github.com/Sergeyir/ProgressBar
 *
 *  @author Sergei Antsupov (antsupov0124@gmail.com)
 **/
#ifndef PBAR_STYLE_HPP
#define PBAR_STYLE_HPP

#include <string>
#include <map>

#include "PBarColor.hpp"

/// @namespace PBarStyle PBarStyle namespace containing styles for ProgressBar class
namespace PBarStyle
{
   // some symbols are thicker than the width that strlen() returns: 
   // for those \r and empty spaces are used to artificialy inflate the length of the string
   /// map of styles for ProgressBar
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
   // this is a secret, you're not supposed to see it
   static std::map<std::string, std::array<std::string, 6>> secretMap = 
   {
      {"SUS", {"SUS ", "ඞ", "ච", "○", " SUS", PBarColor::BOLD_RED}},
      {"COMMUNISM", {"☭", "✭", "☆", " ", "☭", PBarColor::BOLD_RED}},
      {"GACHI", {"CUM ", "♂", "○", "♀", " ASS", PBarColor::BOLD_WHITE}}
   };
} 

#endif /* PBAR_STYLE_HPP */
