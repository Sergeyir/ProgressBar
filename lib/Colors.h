#pragma once

#include <string>

struct 
{
	std::string reset = "\033[0m";
	std::string black = "\033[30m";
	std::string red ="\033[31m";
	std::string green = "\033[32m";
	std::string yellow = "\033[33m";
	std::string blue = "\033[34m";
	std::string magenta = "\033[35m";
	std::string cyan = "\033[36m";
	std::string white = "\033[37m";

	std::string bold_black = "\033[1m\033[30m";
	std::string bold_red = "\033[1m\033[31m";
	std::string bold_green = "\033[1m\033[32m";
	std::string bold_yellow = "\033[1m\033[33m";
	std::string bold_blue = "\033[1m\033[34m";
	std::string bold_magenta = "\033[1m\033[35m";
	std::string bold_cyan = "\033[1m\033[36m";
	std::string bold_white = "\033[1m\033[37m";

	std::string bold_black_on_black = "\033[1m\033[40;30m";
	std::string bold_red_on_black = "\033[1m\033[40;31m";
	std::string bold_green_on_black = "\033[1m\033[40;32m";
	std::string bold_yellow_on_black = "\033[1m\033[40;33m";
	std::string bold_blue_on_black = "\033[1m\033[40;34m";
	std::string bold_magenta_on_black = "\033[1m\033[40;35m";
	std::string bold_cyan_on_black = "\033[1m\033[40;36m";
	std::string bold_white_on_black = "\033[1m\033[40;37m";

	//fancy stuff
	std::string bold_black_inverse = "\033[1m\033[7;30m";
	std::string bold_red_inverse = "\033[1m\033[7;31m";
	std::string bold_green_inverse = "\033[1m\033[7;32m";
	std::string bold_yellow_inverse = "\033[1m\033[7;33m";
	std::string bold_blue_inverse = "\033[1m\033[7;34m";
	std::string bold_magenta_inverse = "\033[1m\033[7;35m";
	std::string bold_cyan_inverse = "\033[1m\033[7;36m";
	std::string bold_white_inverse = "\033[1m\033[7;37m";

	std::string underlined_bold_black = "\033[1m\033[4;30m";
	std::string underlined_bold_red = "\033[1m\033[4;31m";
	std::string underlined_bold_green = "\033[1m\033[4;32m";
	std::string underlined_bold_yellow = "\033[1m\033[4;33m";
	std::string underlined_bold_blue = "\033[1m\033[4;34m";
	std::string underlined_bold_magenta = "\033[1m\033[4;35m";
	std::string underlined_bold_cyan = "\033[1m\033[4;36m";
	std::string underlined_bold_white = "\033[1m\033[4;37m";
} OutputColor;
