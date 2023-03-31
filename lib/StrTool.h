#pragma once
#include <string>
#include <sstream>
#include <iomanip>

std::string FtoStr(float val, const int precision = 2)
{
	std::stringstream ssval;
	ssval << std::fixed << std::setprecision(precision) << val;
	return ssval.str();
}

std::string DtoStr(float val, const int precision = 2)
{
	std::stringstream ssval;
	ssval << std::fixed << std::setprecision(precision) << val;
	return ssval.str();
}
