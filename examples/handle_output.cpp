/** 
 *  @file handle_output.cpp 
 *  @brief Example on usage of ProgressBar showing how to handle output in terminal while ProgressBar is in progress
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
	ProgressBar pBar("BLOCK1");
	std::cout << "An example that shows how to handle output with progress bar" << std::endl;
	for (int i = 0; i < 1e3; i++)
	{
		pBar.Print(static_cast<double>(i)/(1e3 - 1.));
		DoSomething();
      if ((i + 1) % 100 == 0) pBar.HandleOutput("Number of iterations:", i + 1);
	}
   pBar.Finish();
}
