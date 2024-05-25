# Overview

This is a simple tool that allows you to use the progress bar in your c++ projects that run in terminal

# Installing

Run in your working directory to download

```sh
git clone https://github.com/Sergeyir/ProgressBar
```

# Usage

Run ```sh make install ``` in ProgressBar directory. You can use the compiled libraries as in examples directory

```c++
#include "/working_dir/lib/ProgressBar.h"
```

Then create ProgressBar object with one of the constructors:

```c++
ProgressBar::ProgressBar(std::string style = "DEFAULT", std::string left_text = "", 
	std::string color = "", const int default_width = 100) {};

ProgressBar(std::string custom_left_border, 
	std::string custom_right_border,
	const char custom_complete, 
	const char custom_next_complete, 
	const char custom_not_complete,
	std::string color, 
	std::string left_text = "", 
	const int default_width = 100) {};
```

Using the first one you can choose one of predefined style options. And with the second one you can create ProgressBar object with a custom style. Then all you need to do is to call *ProgressBar::Print(const double progress)* where you need it to use. You can see the example in examples/test.cc how to use ProgressBar and run it by typing

```sh
make test && ./test.exe
```

Also you can print the bar with any style using an example style.cc. To do this run

```sh
make style && ./style.exe name1 name2 ...
```

There is also an example of multithread implementation. It doesn't use the lock guard for the progress increment therefore the ProgressBar works fast. Though the value of progress might be a bit inaccurate (up to 1-2% on 4 threads) when using it in multithread projects, the ProgressBar was created with intent to visualize the workflow of the program, not to show very accurate values.

```sh
make mt && ./mt.exe
```

# You can change the parameters of already created ProgressBar object using the ProgressBar methods:

- Changes the style of the ProgressBar object
```c++
	ProgressBar::SetStyle(std::string style, std::string color) {};
```
	
- Changes the style of the ProgressBar object to a custom style
```c++
	ProgressBar::SetCustomStyle(std::string custom_left_border, 
		const char custom_complete, 
		const char custom_nex_complete, 
		const char custom_not_complete, 
		std::string custom_right_border, 
		std::string color) {};
```

- Sets the width of the bar
```c++
	ProgressBar::SetWidth(const int default_width) {};
```

- Sets the text to the left of the bar
```c++
	ProgressBar::SetText(std::string left_text) {};
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

- OutputColor::reset (default)
- OutputColor::black
- OutputColor::red
- OutputColor::green
- OutputColor::yellow
- OutputColor::blue
- OutputColor::magenta
- OutputColor::cyan
- OutputColor::white
- OutputColor::bold_black
- OutputColor::bold_red
- OutputColor::bold_green
- OutputColor::bold_yellow
- OutputColor::bold_blue
- OutputColor::bold_magenta
- OutputColor::bold_cyan
- OutputColor::bold_white

Colors are binded to the terminal colors thus may change if you change colors in terminal.
