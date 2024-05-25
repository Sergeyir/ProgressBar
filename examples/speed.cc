//this macros tests the speed of progress bar printing

#include <unistd.h>
#include <chrono>

int main()
{
	ProgressBar pbar("FANCY");
	const double number_of_iterations = 1e9;
	auto chrono_start = std::chrono::high_resolution_clock::now();
	
	for (int i = 0; i < number_of_iterations; i++)
	{
		pbar.Print(static_cast<double>(i)/(number_of_iterations - 1.));
	}
	
	auto chrono_stop = std::chrono::high_resolution_clock::now();

	unsigned int duration = 
		std::chrono::duration_cast<std::chrono::milliseconds>(chrono_stop - chrono_start).count();
	std::cout << "Number of iterations: " << number_of_iterations << std::endl;
	std::cout << "Time elapsed: " << duration << " ms" << std::endl;
	return 0;
}
