### Table of Contents  
**[Overview](#overview)**<br>
**[Installing](#installing)**<br>
**[Usage](#usage)**<br>
**[Changing progress bar parameters](#changing-progress-bar-parameters)**<br>
**[Predefined styles](#predefined-styles)**<br>
**[Predefined colors](#predefined-colors)**<br>

# Overview

This is a simple fast customizable graphic terminal display that shows you the progress of your process in a form of an ascii horizontal bar

# Installing

Run in your working directory to download

```sh
git clone https://github.com/Sergeyir/ProgressBar
```

Run in the downloaded directory to compile all code

```sh 
make install 
```

Compilation should take less than a second. You can check the compilation result by heading to the example directory by making the test.cpp and then running the executable

```sh
make test && ./test.exe
```

# Usage

You can link the compiled libraries and include headers as shown in Makefile in the examples directory. 

After linking to use the progress bar in your code create an instance of ProgressBar object with one of the following constructors:

```c++
    ProgressBar::ProgressBar(std::string style =      "DEFAULT", 
                             std::string customText = "", 
                             std::string color =      ""
                             )

    ProgressBar::ProgressBar(std::string customLeftBorder, 
                             const char  customCompleteSymbol, 
                             const char  customNextCompleteSymbol, 
                             const char  customNotCompleteSymbol,
                             std::string customRightBorder, 
                             std::string color, 
                             std::string customText = ""
                             )
```

The first constructor lets you choose one of predefined styles, add text to the left of your progress bar, choose the color. And the second lets you choose the characters that will construct the body of progress bar. For more details you can see by making and obserbing examples/possibilities.cpp.

More on the styles is shown in examples/style.cpp. You can make it and pass arguments that represetn the name of predefined styles that will run consequently.

For multithread implementation see examples/mt.cpp. You can also make it and run the executable.

**If you type something it terminal before the progress bar has finished it will owerrite it.** But if you need to print something with progress bar not finished and to avoid owerriting you need to call *ProgressBar::Clear()* to clear the progress bar, then print the text you needed to print, and finally call *ProgressBar::RePrint()*.

**Warning!** Do not use methods *ProgressBar::Clear()* and *ProgressBar::RePrint()* too often - it takes a lot of time to reprint the same line so if you intend to print a lot of text other than progress bar - it is better not to use it completely. In any different case use only *ProgressBar::Print()* which when called many times is very quick.

# Changing progress bar parameters

You can change the parameters of already created ProgressBar object using the ProgressBar methods:

- Changes the color of the progress bar body

```c++
	void SetColor(std::string color)
```

- Changes the style of the progress bar

```c++
	void SetStyle(std::string style, 
                  std::string color = ""
                  )
```
	
- Changes the style of the ProgressBar object to a custom style
```c++
   void ProgressBar::SetCustomStyle(std::string customLeftBorder, 
                                    const char  customCompleteSymbol, 
                                    const char  customNextCompleteSymbol, 
                                    const char  customNotCompleteSymbol,
                                    std::string customRightBorder, 
                                    std::string color)
```

- Sets the width of the bar (by default the width equals the number of columns of the terminal)
```c++
	void ProgressBar::SetWidth(const int customWidth)
```

- Add the text to the left of the progress bar body
```c++
	void ProgressBar::SetText(std::string customText)
```

# Predefined styles

- "DEFAULT"
- "IMPROVED"
- "FANCY"
- "FANCY1"
- "FANCY2"
- "WAVE"
- "BLOCK"
- "BLOCK1"
- "BLOCK2"

Keys are passed as parameters in a constuctor or in a method ProgressBar::SetSTyle and can contain both lower and upper case symbols.

# Predefined colors

Colors are binded to the terminal color palette so if your terminal has non-standard color palette the names might mismatch with the colors.

- PBarColor::RESET (default)
- PBarColor::BLACK
- PBarColor::RED
- PBarColor::GREEN
- PBarColor::YELLOW
- PBarColor::BLUE
- PBarColor::MAGENTA
- PBarColor::CYAN
- PBarColor::WHITE
- PBarColor::BOLD_BLACK
- PBarColor::BOLD_RED
- PBarColor::BOLD_GREEN
- PBarColor::BOLD_YELLOW
- PBarColor::BOLD_BLUE
- PBarColor::BOLD_MAGENTA
- PBarColor::BOLD_CYAN
- PBarColor::BOLD_WHITE
