#pragma once

#include <string>

namespace OutputColor
{
	const std::string reset = "\033[0m";
	const std::string black = "\033[30m";
	const std::string red ="\033[31m";
	const std::string green = "\033[32m";
	const std::string yellow = "\033[33m";
	const std::string blue = "\033[34m";
	const std::string magenta = "\033[35m";
	const std::string cyan = "\033[36m";
	const std::string white = "\033[37m";

	const std::string bold_black = "\033[1m\033[30m";
	const std::string bold_red = "\033[1m\033[31m";
	const std::string bold_green = "\033[1m\033[32m";
	const std::string bold_yellow = "\033[1m\033[33m";
	const std::string bold_blue = "\033[1m\033[34m";
	const std::string bold_magenta = "\033[1m\033[35m";
	const std::string bold_cyan = "\033[1m\033[36m";
	const std::string bold_white = "\033[1m\033[37m";
}
