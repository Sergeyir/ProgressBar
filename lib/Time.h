#pragma once

#include<ctime>
#include<chrono>
#include<iostream>

typedef std::chrono::_V2::system_clock::time_point chrono_t;	

struct
{
	void PrintDuration(std::chrono::_V2::system_clock::time_point start, std::chrono::_V2::system_clock::time_point stop)
	{
		unsigned int duration = (unsigned int) std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count();
		std::cout << duration/3600000 << "h " << (duration % 3600000)/60000 << "m " << (duration % 60000)/1000 << "s " << duration % 1000 << "ms" << std::endl;
	}
		
	void PrintRemaining(std::chrono::_V2::system_clock::time_point start, std::chrono::_V2::system_clock::time_point stop, double remain, double done)
	{
		ncalls++;
		unsigned int duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count();
		passed_time += duration;
		processing_speed = static_cast<double>(((processing_speed*(ncalls-1) + (double) done/duration))/ncalls);

		unsigned int remaining_time = remain/processing_speed/1000;
		std::cout << remaining_time/3600 << "h " << (remaining_time % 3600)/60 << "m " << (remaining_time % 60) << "s" << std::endl;
	}
} Time;
