/** 
 *  @file stest.cpp 
 *  @brief The simplest usage of ProgressBar
 *
 *  This file is an example in a project ProgressBar (https://github.com/Sergeyir/ProgressBar).
 *
 *  @author Sergei Antsupov (antsupov0124@gmail.com)
 **/
#include <unistd.h>

#include "PBar.hpp"

void DoSomething() {usleep(1e3);}

int main()
{
	ProgressBar pBar;
	std::cout << "Congratulations: compilation was succesful" << std::endl;
	for (int i = 0; i < 1e3; i++)
	{
		pBar.Print(static_cast<double>(i)/(1e3 - 1.));
		DoSomething();
	}
   // if the progress that is passed to pBar.Print(counter) goes beyond 1. the following
   // function will be called automaticaly and the ProgressBar will no longer be printed
   pBar.Finish();
}
