# Overview

This is a simple library that allows you to use progressbar in your applications.

# Usage

Just call a function using structure ProgressBar (examples are in the test.cc macro). Passing it a float type argument between 0 and 1 outputs progressbar with progress between 0 and 100%.

Using ProgressBar.SetPrecision(int precision) you can change precision of progress. By default this value is 0.

Using ProgressBar.SetStep(int step) you can change step of progress at which it will update. By default this value is 0.01.
