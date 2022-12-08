#pragma once
#include <string>
#include <sstream>
#include <iomanip>

std::string FloatToStrNf(float val, const int precision = 2)
{
	std::stringstream ssval;
	ssval << std::fixed << std::setprecision(precision) << val;
	return ssval.str();
}
