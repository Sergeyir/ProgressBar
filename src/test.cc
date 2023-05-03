#include "../lib/ProgressBar.h"
#include <unistd.h>

void do_something() {usleep(1e3);}

int main()
{
	//Default constructor
	//Default style is used
	std::cout << "Default constuctor" std::endl;
	ProgressBar pbar1();
	for (int i = 0; i < 1e3; i++)
	{
		pbar2.Print(static_cast<double>(i)/(1e3 - 1.));
		do_something();
	}
	
	//Using predefined styles
	std::cout << "Predefined style" std::endl;
	ProgressBar pbar2("BLOCK", "");
	for (int i = 0; i < 1e3; i++)
	{
		pbar2.Print(static_cast<double>(i)/(1e3 - 1.));
		do_something();
	}

	//Creating progress bar with it's own style
	std::cout << "Custom style bar" std::endl;
	ProgressBar pbar2("(", ")", "+", ">", "-");
	return 0;
}
