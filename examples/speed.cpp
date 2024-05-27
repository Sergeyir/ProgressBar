//this macros tests the speed of progress bar printing

#include <unistd.h>
#include <chrono>

#include "PBar.hpp"

int main()
{
	const double NUMBER_OF_ITERATIONS = 1e9;
   
	ProgressBar pbar("FANCY");
	auto start = std::chrono::high_resolution_clock::now();
	
	for (int i = 0; i < NUMBER_OF_ITERATIONS; i++)
	{
		pbar.Print(static_cast<double>(i)/(NUMBER_OF_ITERATIONS - 1.));
	}
	
	auto stop = std::chrono::high_resolution_clock::now();

	unsigned int duration = 
      std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count();
	std::cout << "Number of iterations: " << NUMBER_OF_ITERATIONS << std::endl;
	std::cout << "Time elapsed: " << duration << " ms" << std::endl;
	return 0;
}
