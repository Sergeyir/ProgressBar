# Overview

This is a simple tool that allows you to use the progress bar in your c++ projects that run in terminal

# Installing

Run in your working directory to download

```sh
git clone https://github.com/Sergeyir/ProgressBar
```

# Usage

First place lib folder in you working directory. Then include file ProgressBar.h in you code :

```c++
#include "/working_dir/lib/ProgressBar.h"
```

Then create ProgressBar object with one of the constructors:

```c++
ProgressBar::ProgressBar(std::string style = "DEFAULT", std::string left_text = "", 
	std::string color = "", const int default_width = 100) {};

ProgressBar(std::string custom_left_border, std::string custom_right_border,
	const char custom_complete, const char custom_next_complete, const char custom_not_complete,
	std::string color, std::string left_text = "", const int default_width = 100) {};
```

Using the first one you can choose one of predefined style options. And with the second one you can create ProgressBar object with a custom style. Then all you need to do is to call *ProgressBar::Print(const double progress)* where you need it to use. You can see the example in stc/test.cc how to use ProgressBar and run it by typing

```sh
make test && ./test
```

**If you type something it terminal before the progress bar has finished it will owerrite it**. But if you need to print something with progress bar not finished and to avoid owerriting you need to call *ProgressBar::Clear()* to clear the progress bar, than print the text you needed to print, and finally call *ProgressBar::RePrint()*.

**Warning!** Do not use methods *ProgressBar::Clear()* and *ProgressBar::RePrint()* too often - it takes a lot of time to reprint the same line so if you intend to print a lot of text other than progress bar - it is better not to use it completely. In any different case use only *ProgressBar::Print()* which when called many times is still very quick.

# Keys of predefined progress bar styles

- "DEFAULT"
- "IMPROVED"
- "FANCY"
- "FANCY1"
- "FANCY2"
- "WAVE"
- "BLOCK"
- "BLOCK1"
- "BLOCK2"

Keys are passed as parameters in constuctor and can contain both lower and upper case symbols.

# Predefined colors

- reset (default)
- black
- red
- green
- yellow
- blue
- magenta
- cyan
- white
- bold_black
- bold_red
- bold_green
- bold_yellow
- bold_blue
- bold_magenta
- bold_cyan
- bold_white

The colors are binded to the terminal colors thus may change if you change colors in terminal.
