#include "../lib/ProgressBar.h"
#include <unistd.h>
#include <memory>
#include <vector>
#include <thread>

void do_something()
{
	std::this_thread::sleep_for(std::chrono::milliseconds(10));
}

int main()
{
	ProgressBar pbar_mt = ProgressBar("FANCY", "Multithread");
	const auto nthreads = std::thread::hardware_concurrency();

	std::cout << "Running this program on " << nthreads << " threads" << std::endl;

	double ncalls = 0;
	const double max_ncalls = 5e2*nthreads;
	
	auto ThrCall = [&]()
	{
		for (int i = 0; i < 5e2; i++)
		{
			pbar_mt.Print(ncalls/max_ncalls);
			
			do_something();
			ncalls += 1.;
		}
	};
	
	std::vector<std::unique_ptr<std::thread>> thr;
	
	for (auto i = nthreads; i != 0; i--)
	{
		thr.push_back(std::unique_ptr<std::thread>(new std::thread(ThrCall)));
	}

	while (!thr.empty()) 
	{
		thr.back()->join(); 
		thr.pop_back();
	}

	pbar_mt.Print(1.);

	return 0;
}
