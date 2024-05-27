#include <unistd.h>

#include "PBar.hpp"

void DoSomething() {usleep(1e3);}

int main()
{
	ProgressBar pbar;
	std::cout << "Congratulations: compilation was succesful" << std::endl;
	for (int i = 0; i < 1e3; i++)
	{
		pbar.Print(static_cast<double>(i)/(1e3 - 1.));
		DoSomething();
	}
}
