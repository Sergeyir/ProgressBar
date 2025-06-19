/** 
 *  @file mt.cpp 
 *  @brief Example on simplest usage of ProgressBar in multithreaded applications
 *
 *  This file is an example in a project ProgressBar (https://github.com/Sergeyir/ProgressBar).
 *
 *  @author Sergei Antsupov (antsupov0124@gmail.com)
 **/
#include <unistd.h>
#include <memory>
#include <vector>
#include <thread>

#include "PBar.hpp"

void DoSomething()
{
	std::this_thread::sleep_for(std::chrono::milliseconds(10));
}

int main()
{
	const unsigned int numberOfThreads = std::thread::hardware_concurrency();

	std::cout << "Running this program on " << numberOfThreads << " threads" << std::endl;

   std::vector<unsigned long> numberOfCalls;
	unsigned long numberOfIterations = 500*numberOfThreads;

	bool isProcessFinished = false;
	
	auto ThrCall = [&](const unsigned int threadNumber)
	{
		for (int i = 0; i < 500; i++)
		{
			DoSomething();
			numberOfCalls[threadNumber]++;
		}
	};

	// pbar needs to have it's own thread for it 
	// to be consistent as frequent overwriting on
	// multiple cores leads to interference and 
	// therefore the progress bar is displayed incorrectly
	auto PbarCall = [&]()
	{
		ProgressBar pbarMT = ProgressBar("FANCY", "Multithread");
		while (!isProcessFinished)
		{
         unsigned long sumNumberOfCalls = 0.;
         for (const unsigned long& nCall : numberOfCalls)
         {
            sumNumberOfCalls += nCall;
         }
			pbarMT.Print(static_cast<double>(sumNumberOfCalls)/static_cast<double>(numberOfIterations));
         // note the sleep timer for this lambda function since ProgressBar is running on it's own 
         // thread; otherwise this while cycle will take all resources from the current thread
			std::this_thread::sleep_for(std::chrono::milliseconds(50));
		}
		pbarMT.Finish();
	};

	std::thread pbar_thread(PbarCall);
	std::vector<std::thread> thr;
	
	for (unsigned int i = 0; i < numberOfThreads; i++)
	{
      numberOfCalls.push_back(0.);
		thr.push_back(std::thread(ThrCall, i));
	}
	
	while (!thr.empty()) 
	{
		thr.back().join(); 
		thr.pop_back();
	}

	isProcessFinished = true;
	pbar_thread.join();

	return 0;
}
