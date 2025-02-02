/** 
 *  @file style.cpp 
 *  @brief When executed this example allows to test different styles of ProgressBar 
 *
 *  This file is an example in a project ProgressBar (https://github.com/Sergeyir/ProgressBar).
 *
 *  @author Sergei Antsupov (antsupov0124@gmail.com)
 **/
#include <unistd.h>

#include "PBar.hpp"

void DoSomething() {usleep(5e3);}

int main(int argc, char *argv[])
{
	if (argc < 2) 
	{
		std::cout << "\033[1m\033[31mError:\033[0m " << 
			          "Number of passed arguments is " << argc - 1 << 
			          " while at least 1 was expected" << std::endl;
      std::cout << "\033[32mUsage:\033[0m " << 
                   "Pass one or multiple string containing style names as an arguments" << std::endl;
      std::cout << "Example: ./style FANCY BLOCK" << std::endl;
		exit(1);
	}

	for (int i = 1; i < argc; i++)
	{
		std::cout << "Showing the style " << i << " out of " << argc-1 
			<< " with the name \"" << argv[i] << "\"" << std::endl;
		
		ProgressBar pbar((std::string) argv[i]);
		for (int j = 0; j < 1e3; j++)
		{
			pbar.Print(static_cast<double>(j)/(1e3 - 1.));
			DoSomething();
		}
	}
	return 0;
}
