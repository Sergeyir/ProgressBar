#pragma once
//#ifndef PBAR_COLOR_HPP
//#define PBAR_COLOR_HPP

#include <string>

namespace PBarColor
{
	const std::string RESET = "\033[0m";
	const std::string BLACK = "\033[30m";
	const std::string RED ="\033[31m";
	const std::string GREEN = "\033[32m";
	const std::string YELLOW = "\033[33m";
	const std::string BLUE = "\033[34m";
	const std::string MAGENTA = "\033[35m";
	const std::string CYAN = "\033[36m";
	const std::string WHITE = "\033[37m";

	const std::string BOLD_BLACK = "\033[1m\033[30m";
	const std::string BOLD_RED = "\033[1m\033[31m";
	const std::string BOLD_GREEN = "\033[1m\033[32m";
	const std::string BOLD_YELLOW = "\033[1m\033[33m";
	const std::string BOLD_BLUE = "\033[1m\033[34m";
	const std::string BOLD_MAGENTA = "\033[1m\033[35m";
	const std::string BOLD_CYAN = "\033[1m\033[36m";
	const std::string BOLD_WHITE = "\033[1m\033[37m";
}

//#endif
