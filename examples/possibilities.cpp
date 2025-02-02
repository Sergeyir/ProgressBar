/** 
 *  @file possibilities.cpp 
 *  @brief Example that shows different ways to use ProgressBar
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
	//Default constructor
	//Default style is used
	std::cout << "Default constuctor" << std::endl;
	ProgressBar pbar1;
	for (int i = 0; i < 1e3; i++)
	{
		pbar1.Print(static_cast<double>(i)/(1e3 - 1.));
		DoSomething();
	}
	
	//Using predefined style
	std::cout << "Use predefined style" << std::endl;
	ProgressBar pbar2("FANCY");
	for (int i = 0; i < 1e3; i++)
	{
		pbar2.Print(static_cast<double>(i)/(1e3 - 1.));
		DoSomething();
	}

	//Adding text
	ProgressBar pbar3("FANCY", "Add text");
	for (int i = 0; i < 1e3; i++)
	{
		pbar3.Print(static_cast<double>(i)/(1e3 - 1.));
		DoSomething();
	}

	//Changing color
	ProgressBar pbar4("FANCY", "Change color", PBarColor::GREEN);
	for (int i = 0; i < 1e3; i++)
	{
		pbar4.Print(static_cast<double>(i)/(1e3 - 1.));
		DoSomething();
	}

	//Creating progress bar with it's own style
	ProgressBar pbar5("(", '+', '>', '-', ")", PBarColor::BOLD_MAGENTA, "Custom");
	for (int i = 0; i < 1e3; i++)
	{
		pbar5.Print(static_cast<double>(i)/(1e3 - 1.));
		DoSomething();
	}
}
