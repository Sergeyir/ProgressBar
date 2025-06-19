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
	ProgressBar pBar1;
	for (int i = 0; i < 1e3; i++)
	{
		pBar1.Print(static_cast<double>(i)/(1e3 - 1.));
		DoSomething();
	}

   pBar1.Finish();
   std::cout << " Progress bar with default constructor finished" << std::endl;
	
	//Using predefined style
	ProgressBar pBar2("FANCY");
	for (int i = 0; i < 1e3; i++)
	{
		pBar2.Print(static_cast<double>(i)/(1e3 - 1.));
		DoSomething();
	}

   pBar2.Finish();
   std::cout << " Progress bar with constructor that specified style finished" << std::endl;

	//Adding text
	ProgressBar pBar3("FANCY", "Add text");
	for (int i = 0; i < 1e3; i++)
	{
		pBar3.Print(static_cast<double>(i)/(1e3 - 1.));
		DoSomething();
	}

   pBar3.Finish();
   std::cout << " Progress bar with constructor that specified style and text finished" << std::endl;

	//Changing color
	ProgressBar pBar4("FANCY", "Change color", PBarColor::GREEN);
	for (int i = 0; i < 1e3; i++)
	{
		pBar4.Print(static_cast<double>(i)/(1e3 - 1.));
		DoSomething();
	}

   pBar4.Finish();
   std::cout << " Progress bar with constructor that specified style, text, and color finished" << std::endl;

	//Creating progress bar with it's own style
	ProgressBar pBar5("(", '+', '>', '-', ")", PBarColor::BOLD_MAGENTA, "Custom");
	for (int i = 0; i < 1e3; i++)
	{
		pBar5.Print(static_cast<double>(i)/(1e3 - 1.));
		DoSomething();
	}

   pBar5.Finish();
   std::cout << " Progress bar with constructor for custom bar finished" << std::endl;
}
