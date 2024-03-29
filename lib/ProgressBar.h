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
	protected:
		
	std::string text;

	std::string bar_color;
	std::string left_border, right_border;
	std::string complete, next_complete, not_complete;
	
	int default_bar_width;
	int orig_default_width;
	
	double bar_step = 0.01;
	double bar_progress = -0.01;
	int bar_precision = 0;

	struct winsize w;

	int utf8_strlen(const std::string& str)
	{
		int len = 0;
		for (int i=0; i < static_cast<int>(str.length()); i++, len++)
		{
			const unsigned char c = (unsigned char) str[i];
			if      (c>=0   && c<=127) i+=0;
			else if ((c & 0xE0) == 0xC0) i+=1;
			else if ((c & 0xF0) == 0xE0) i+=2;
			else if ((c & 0xF8) == 0xF0) i+=3;
			else return 0;
		}
		return len;
	}

	std::string CheckStyle(std::string style)
	{
		if (PBStyle::map.find(style) == PBStyle::map.end()) 
		{
			std::cout << OutputColor::bold_magenta << "Warning: " << OutputColor::reset << 
				"Style \"" << style << "\" was not found; changing to \"DEFAULT\"" << std::endl;
			style = "DEFAULT";

			std::cout << "You can use one of the predefined styles: " << std::endl;

			for (auto const &x : PBStyle::map)
			{
				std::cout << " " << x.first << std::endl;
			}
			
			std::cout << "Or create your custom style with the constuctor for the cutstom style" << std::endl;
			std::cout << "If you don't need the style you can leave the object declaration constructor empty; " << std::endl; 
			std::cout << "the style will be automaticaly set to default without printing the warning" << std::endl;
		}

		return style;
	}

	public:

	void SetColor(std::string color)
	{
		bar_color = color;
	}

	void SetStyle(std::string style, std::string color = "")
	{
		style = CheckStyle(style);

		std::array<std::string, 6> style_par = PBStyle::map[style.c_str()];

		left_border = style_par[0];
		right_border = style_par[4];
		
		complete = style_par[1];
		next_complete = style_par[2];
		not_complete = style_par[3];

		if (color == "") bar_color = style_par[5];
		else bar_color = color;
	}

	void SetCustomStyle(std::string custom_left_border, const char custom_complete, 
		const char custom_next_complete, const char custom_not_complete,
		std::string custom_right_border, std::string color)
	{
		left_border = custom_left_border;
		right_border = custom_right_border;
		
		complete = custom_complete;
		next_complete = custom_next_complete;
		not_complete = custom_not_complete;

		bar_color = color;
	}

	void SetWidth(const int default_width)
	{
		default_bar_width = default_width - utf8_strlen(text) - 
			utf8_strlen(left_border) - utf8_strlen(right_border) - 8;

		orig_default_width = default_width;
	}

	void SetText(std::string left_text)
	{
		text = left_text;
		SetWidth(orig_default_width);
	}

	ProgressBar(std::string style = "DEFAULT", std::string left_text = "", std::string color = "", const int default_width = 100)
	{
		for (char &c : style) c = toupper(c);

		SetStyle(style, color);
		orig_default_width = default_width;
		//SetText method recalculates the width of the bar
		SetText(left_text);
	}

	ProgressBar(std::string custom_left_border, const char custom_complete, 
		const char custom_next_complete, const char custom_not_complete,
		std::string custom_right_border, std::string color, 
		std::string left_text = "", const int default_width = 100)
	{

		SetCustomStyle(custom_left_border, 
			custom_complete, 
			custom_next_complete, 
			custom_not_complete, 
			custom_right_border, 
			color);
		
		orig_default_width = default_width;
		SetText(left_text);
	}

	~ProgressBar(){}

	void Print(const double progress)
	{	
		if (progress - bar_step/2. <= bar_progress) return;
		if (progress > 1. + bar_step/2. && bar_progress + bar_step > 1. - bar_step/2.) return;

		bar_progress = progress - bar_step;
		
		std::string progress_perc = ProgressBarTools::DtoStr((bar_progress + bar_step) * 100.0, bar_precision);
		
		ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
		
		int width;
		if (default_bar_width > w.ws_col - 4) width = w.ws_col - 4 - orig_default_width + default_bar_width - utf8_strlen(progress_perc);
		else width = default_bar_width - utf8_strlen(progress_perc)-4;
		
		bar_progress += bar_step;

		int pos = static_cast<int>(width * bar_progress);

		std::stringstream to_print;
		to_print << "\r " << OutputColor::bold_white << text << " " << bar_color << left_border;

		for (int count = 0; count < width; count++)
		{
			if (count == pos) to_print << next_complete + OutputColor::reset;
			else if (count < pos) to_print << complete;
			else to_print << not_complete;
		}
		to_print << bar_color + right_border;

		to_print << " " + OutputColor::bold_white + "[" + progress_perc + "%]" + OutputColor::reset + " ";

		std::cout << to_print.str() << " \r";
		std::cout.flush();

		if (bar_progress + bar_step/2. >= 1) std::cout << std::endl;
	}

	void Clear()
	{
		ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
		const int width = w.ws_col;
		for (int i = 0; i < width; i++) std::cout << " ";
	}

	void RePrint()
	{	
		std::string progress_perc = ProgressBarTools::DtoStr((bar_progress + bar_step) * 100.0, bar_precision);
		
		ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
		
		int width;
		
		if (default_bar_width > w.ws_col - 4) width = w.ws_col - 4 - orig_default_width + default_bar_width - utf8_strlen(progress_perc);
		else width = default_bar_width - utf8_strlen(progress_perc)-4;

		int pos = static_cast<int>(width * bar_progress);

		std::stringstream to_print;
		to_print << "\r " << OutputColor::bold_white << text << " " << bar_color << left_border;

		for (int count = 0; count < width; count++)
		{
			if (count == pos) to_print << next_complete + OutputColor::reset;
			else if (count < pos) to_print << complete;
			else to_print << not_complete;
		}
		to_print << bar_color << right_border;

		to_print << " " << OutputColor::bold_white << 
			"[" << progress_perc << "%]" << OutputColor::reset << " ";

		std::cout << to_print.str() << " \r";
		std::cout.flush();

		if (bar_progress + bar_step/2. >= 1) std::cout << std::endl;
	}
	
	void Fill() {Print(1.1);}
	
	void Reset() {bar_progress = 0;}
	void SetBarStep(const double step) {bar_step = step;}
	void SetPrecision(const int precision) {bar_precision = precision;}
};
