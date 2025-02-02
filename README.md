# Overview

This is a simple fast customizable graphic terminal display that shows you the progress of your process in a form of an ascii horizontal bar.

![](https://github.com/Sergeyir/ProgressBar/blob/main/preview/pbar_demo.gif)

# Requirements

- GNU GCC++11 or newer

# Installing

Run in your working directory to download

```sh
git clone https://github.com/Sergeyir/ProgressBar
```

Run in the downloaded directory to compile the code for ProgressBar

```sh 
make
```

You can check the compilation result by heading to the examples directory by making examples and then running the simplest test executable

```sh
make && ./test
```

# Documentation

You can view the detailed documentation https://sergeyir.github.io/ProgressBar/ (see Classes / Class List / ProgressBar).

If the link is unaccesible you can generate the documentation yourself with doxygen. To do this run while in root of the repository

```sh
doxygen
```

To view the generated html file open html/index.html with any browser or simply run to automaticaly open it on linux

```sh
xdg-open html/index.html
```

# Usage

You can link the compiled librariy libPBar.so (see Makefile and Makefile.am for reference in the examples directory). Also see [examples](https://sergeyir.github.io/ProgressBar/examples.html) in examples directory:
- style.cpp - execute, run and try different ProgressBar with different styles.
- possibilities.cpp - shows different ways to use ProgressBar.
- handle_output.cpp - shows how to handle output while ProgressBar is in progress.
- mt.cpp - shows the simplest usage of ProgressBar in multithreaded applications.
- speed.cpp - shows how much time it takes for calling ProgressBar::Print(progress) 1 billion times.
