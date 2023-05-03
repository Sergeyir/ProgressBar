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

	const std::string bold_black_on_black = "\033[1m\033[40;30m";
	const std::string bold_red_on_black = "\033[1m\033[40;31m";
	const std::string bold_green_on_black = "\033[1m\033[40;32m";
	const std::string bold_yellow_on_black = "\033[1m\033[40;33m";
	const std::string bold_blue_on_black = "\033[1m\033[40;34m";
	const std::string bold_magenta_on_black = "\033[1m\033[40;35m";
	const std::string bold_cyan_on_black = "\033[1m\033[40;36m";
	const std::string bold_white_on_black = "\033[1m\033[40;37m";

	//fancy stuff
	const std::string bold_black_inverse = "\033[1m\033[7;30m";
	const std::string bold_red_inverse = "\033[1m\033[7;31m";
	const std::string bold_green_inverse = "\033[1m\033[7;32m";
	const std::string bold_yellow_inverse = "\033[1m\033[7;33m";
	const std::string bold_blue_inverse = "\033[1m\033[7;34m";
	const std::string bold_magenta_inverse = "\033[1m\033[7;35m";
	const std::string bold_cyan_inverse = "\033[1m\033[7;36m";
	const std::string bold_white_inverse = "\033[1m\033[7;37m";

	const std::string underlined_bold_black = "\033[1m\033[4;30m";
	const std::string underlined_bold_red = "\033[1m\033[4;31m";
	const std::string underlined_bold_green = "\033[1m\033[4;32m";
	const std::string underlined_bold_yellow = "\033[1m\033[4;33m";
	const std::string underlined_bold_blue = "\033[1m\033[4;34m";
	const std::string underlined_bold_magenta = "\033[1m\033[4;35m";
	const std::string underlined_bold_cyan = "\033[1m\033[4;36m";
	const std::string underlined_bold_white = "\033[1m\033[4;37m";
}
