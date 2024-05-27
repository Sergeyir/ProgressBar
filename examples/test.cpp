#include <unistd.h>

#include "PBar.hpp"

void do_something() {usleep(1e3);}

int main()
{
	//Default constructor
	//Default style is used
	std::cout << "Default constuctor" << std::endl;
	ProgressBar pbar1;
	for (int i = 0; i < 1e3; i++)
	{
		pbar1.Print(static_cast<double>(i)/(1e3 - 1.));
		do_something();
	}
	
	//Using predefined style
	std::cout << "Use predefined style" << std::endl;
	ProgressBar pbar2("FANCY");
	for (int i = 0; i < 1e3; i++)
	{
		pbar2.Print(static_cast<double>(i)/(1e3 - 1.));
		do_something();
	}

	//Adding text
	ProgressBar pbar3("FANCY", "Add text");
	for (int i = 0; i < 1e3; i++)
	{
		pbar3.Print(static_cast<double>(i)/(1e3 - 1.));
		do_something();
	}

	//Changing color
	ProgressBar pbar4("FANCY", "Change color", PBarColor::GREEN);
	for (int i = 0; i < 1e3; i++)
	{
		pbar4.Print(static_cast<double>(i)/(1e3 - 1.));
		do_something();
	}

	//Creating progress bar with it's own style
	ProgressBar pbar5("(", '+', '>', '-', ")", PBarColor::BOLD_MAGENTA, "Custom");
	for (int i = 0; i < 1e3; i++)
	{
		pbar5.Print(static_cast<double>(i)/(1e3 - 1.));
		do_something();
	}
	return 0;
}
