#pragma once

#include <iostream>
#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>
#include <map>
#include <array>
#include <cstring>

#include "OutputColor.h"
#include "StrTool.h"

namespace PBStyle
{
	std::map<std::string, std::array<std::string, 6>> map = 
	{
		{"DEFAULT", {"[", "#", "", ".", "]", OutputColor::bold_cyan}},
		{"IMPROVED", {"⁅", "⁜", "⊳", "~", "⁆", OutputColor::bold_cyan}},
		{"FANCY", {"◨▣", "▩", "▧", "▫", "▣◧", OutputColor::bold_cyan}},
		{"FANCY1", {"●", "◎", "○", "◌", "●", OutputColor::bold_cyan}},
		{"FANCY2", {"「", "※", "※", "※", " 」", OutputColor::bold_red}},
		{"WAVE", {"「", "₪", " ", " ", "」", OutputColor::bold_cyan}},
		{"BLOCK", {"", "▓", "▒", "▒", "", OutputColor::blue}},
		{"BLOCK1", {"█", "▓", "▒", "▒", "█", OutputColor::magenta}},
		{"BLOCK2", {"◢█", "▓", "▒", "▒", "█◤", OutputColor::bold_yellow}},
		{"GACHI", {"CUM ", "♂", "○", "♀", " ASS", OutputColor::bold_white}},
		{"SUS", {"SUS ", "ඞ", "ච", "○", " SUS", OutputColor::bold_red}},
		{"COMMUNISM", {"☭", "✭", "☆", " ", "☭", OutputColor::bold_red}}
	};
} 

class ProgressBar
{
	private:
		
	std::string text;

	std::string bar_color;
	std::string left_border, right_border;
	char complete, next_complete, not_complete;
	
	int default_bar_width;
	
	double bar_step = 0.01;
	double bar_progress = -0.01;
	int bar_precision = 0;

	struct winsize w;

	public:

	ProgressBar()
	{
		std::array<std::string, 6> style_par = PBStyle::map["DEFAULT"];

		left_border = style_par[0];
		right_border = style_par[4];
		
		complete = style_par[1][0];
		next_complete = style_par[2][0];
		not_complete = style_par[3][0];

		bar_color = style_par[5];

	}
	
	ProgressBar(std::string style = "DEFAULT", std::string left_text = "", std::string color = "", const int default_width = 100)
	{
		for (char &c : style) c = toupper(c);
		if (PBStyle::map.find(style) == PBStyle::map.end()) 
		{
			std::cout << OutputColor::bold_magenta << "Warning" << OutputColor::reset << 
				"Style \"" << style << "\" was not found; changing to DEFAULT" << std::endl;
		}

		std::array<std::string, 6> style_par = PBStyle::map["DEFAULT"];

		left_border = style_par[0];
		right_border = style_par[4];
		
		complete = style_par[1][0];
		next_complete = style_par[2][0];
		not_complete = style_par[3][0];

		if (color == "") bar_color = style_par[5];
		else bar_color = color;

		text = left_text;
		
		default_bar_width = default_width - left_text.length() - 
			left_border.length() - right_border.length() - 7;
	}

	ProgressBar(std::string custom_left_border, std::string custom_right_border,
		const char custom_complete, const char custom_next_complete, const char custom_not_complete,
		std::string color, std::string left_text = "", const int default_width = 100)
	{
		left_border = custom_left_border;
		right_border = custom_right_border;
		
		complete = custom_complete;
		next_complete = custom_next_complete;
		not_complete = custom_not_complete;

		bar_color = color;

		text = left_text;

		default_bar_width = default_width - left_text.length() - 
			left_border.length() - right_border.length() - 7;
	}

	~ProgressBar(){}

	void Print(const double progress)
	{	
		if (progress - bar_step/2. <= bar_progress) return;
		if (progress > 1. + bar_step/2. && bar_progress + bar_step > 1. - bar_step/2.) return;

		bar_progress = progress - bar_step;
		
		std::string progress_perc = DtoStr((bar_progress + bar_step) * 100.0, bar_precision);
		
		ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
		
		int width;
		if (w.ws_col < default_bar_width) width = w.ws_col - progress_perc.length();
		else width = default_bar_width - progress_perc.length();

		bar_progress += bar_step;

		int pos = static_cast<int>(width * bar_progress);

		std::cout << OutputColor::bold_white << text << " " << bar_color << left_border;

		for (int count = 0; count < width; count++)
		{
			if (count == pos) std::cout << next_complete << OutputColor::reset;
			else if (count < pos) std::cout << complete;
			else std::cout << not_complete;
		}
		std::cout << bar_color << right_border;

		std::cout << " " << OutputColor::bold_white << 
			"[" << progress_perc << "%]" << OutputColor::reset << " ";

		std::cout << " \r";
		std::cout.flush();

		if (bar_progress + bar_step/2. >= 1) std::cout << std::endl;
	}
	
	void Fill() {Print(1.1);}
	
	void Reset() {bar_progress = 0;}
	void SetBarStep(const double step) {bar_step = step;}
	void SetPrecision(const int precision) {bar_precision = precision;}
};
