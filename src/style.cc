#include "../lib/ProgressBar.h"
#include <unistd.h>

void do_something() {usleep(5e3);}

int main(int argc, char *argv[])
{
	if (argc < 2) 
	{
		std::cout << OutputColor::bold_red << "Error: " << 
			OutputColor::reset << "Number of passed arguments is " << argc - 1 << 
			" while at least 1 was expected" << std::endl;
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
			do_something();
		}
	}
	return 0;
}
