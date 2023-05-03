# Overview

This is a simple tool that allows you to use the progress bar in your c++ projects that run in terminal

# Usage

First place lib folder in you working directory. Then include file ProgressBar.h in you code :

'''cpp
#include "../lib/ProgressBar.h"
'''

Then create ProgressBar object with one of the constructors:

'''cpp
ProgressBar::ProgressBar() {};

ProgressBar::ProgressBar(std::string style = "DEFAULT", std::string left_text = "", 
	std::string color = "", const int default_width = 100) {};

ProgressBar(std::string custom_left_border, std::string custom_right_border,
	const char custom_complete, const char custom_next_complete, const char custom_not_complete,
	std::string color, std::string left_text = "", const int default_width = 100) {};
'''

The first one uses "DEFAULT" style option. Using the second one you can choose one of predefined style options. And with the last one you can create ProgressBar object with it's unique style. Then all you need to do is to put ProgressBar::Print(const double progress) where you need it to use. You can see the example in stc/test.cc how to use ProgressBar

There are 12 predefined styles in the file lib/ProgressBar.h. There are their keys:

Passing style keys can be done both with lower and upper case characters.
