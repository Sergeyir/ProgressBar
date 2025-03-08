# Overview

This repository contains class ProgressBar that allows you to print a fast and customizable ASCII bar to show the progress in the terminal.

![](https://github.com/Sergeyir/ProgressBar/blob/main/preview/pbar_demo.gif)

# Requirements

- GNU GCC++17 or newer

# Installing

Run in your working directory to download

```sh
git clone https://github.com/Sergeyir/ProgressBar
```

Run in the downloaded directory to generate the Makefile

```sh 
cmake .
```

Then run to compile libraries and executables

```sh
make
```

You can check the compilation result by  running the simplest test executable

```sh
./bin/test
```

There is another option for compilation with Makefile (located in etc directory). To compile the project this way run

```sh
cp etc/Makefile* . && make
```

# Documentation

You can view the detailed documentation at https://sergeyir.github.io/documentation/ProgressBar/ (see Classes/Class List/ProgressBar).

If the link is inaccessible, you can generate the documentation yourself with Doxygen. To do this run while in the root of the repository

```sh
doxygen
```

To view the generated HTML file, open html/index.html with any browser or simply run to open it on Linux

```sh
xdg-open html/index.html
```

# Usage

You can link the compiled library libPBar.so (see Makefile and Makefile.am for reference in the examples directory or see CMakeLists.txt). Also see [examples](https://sergeyir.github.io/ProgressBar/examples.html) in the examples directory:
- style.cpp - execute, run and try different ProgressBar with different styles.
- possibilities.cpp - shows different ways to use ProgressBar.
- handle_output.cpp - shows how to handle output while ProgressBar is in progress.
- mt.cpp - shows the simplest usage of ProgressBar in multithreaded applications.
- speed.cpp - shows how much time it takes for calling ProgressBar::Print(progress) 1 billion times.
