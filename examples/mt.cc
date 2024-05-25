#include <unistd.h>
#include <memory>
#include <vector>
#include <thread>

#include "../include/ProgressBar.hpp"

void do_something()
{
	std::this_thread::sleep_for(std::chrono::milliseconds(10));
}

int main()
{
	const auto nthreads = std::thread::hardware_concurrency();

	std::cout << "Running this program on " << nthreads << " threads" << std::endl;

	double ncalls = 0;
	const double max_ncalls = 5e2*nthreads;

	bool process_finished = false;
	
	auto ThrCall = [&]()
	{
		for (int i = 0; i < 5e2; i++)
		{
			do_something();
			ncalls += 1.;
		}
	};

	//pbar needs to have it's own thread for it 
	//to be consistent as frequent overwriting on
	//multiple cores leads to interference and 
	//therefore the progress bar is displayed incorrectly
	auto PbarCall = [&]()
	{
		ProgressBar pbar_mt = ProgressBar("FANCY", "Multithread");
		while (!process_finished)
		{
			pbar_mt.Print(ncalls/max_ncalls);
			std::this_thread::sleep_for(std::chrono::milliseconds(20));
		}
		pbar_mt.Print(1.);
	};

	std::thread pbar_thread(PbarCall);
	
	std::vector<std::thread> thr;
	
	for (auto i = nthreads; i != 0; i--)
	{
		thr.push_back(std::thread(ThrCall));
	}
	
	while (!thr.empty()) 
	{
		thr.back().join(); 
		thr.pop_back();
	}

	process_finished = true;
	pbar_thread.join();

	return 0;
}
