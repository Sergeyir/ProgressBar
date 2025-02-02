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
	ProgressBar pbar("BLOCK1");
	std::cout << "An example how to handle output with progress bar" << std::endl;
	for (int i = 0; i < 1e4; i++)
	{
		pbar.Print(static_cast<double>(i)/(1e4 - 1.));
		DoSomething();
      if ((i + 1) % 100 == 0) pbar.HandleOutput("Writing something as the process goes");
      if ((i + 1) % 1000 == 0) pbar.HandleOutput("Number of iterations:", i+1);
	}
}
