#pragma once

#include <iostream>
#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>

#include "Colors.h"
#include "StrTool.h"

struct
{
	struct winsize w;
	int barWidth;

	double barStep = 0.01;
	double barProgress = -0.01;
	
	const int precision = 0;

	void Print(std::string color, std::string left_border, std::string complete, 
		std::string next_complete, std::string not_complete, std::string right_border, 
		double progress, std::string end = "")
	{	
		if (progress - barStep/2. <= barProgress) return;
		if (progress > 1. + barStep/2. && barProgress + barStep > 1. - barStep/2.) return;

		barProgress = progress - barStep;
		
		std::cout << progress << " " << barProgress << std::endl;

		std::string progress_perc = DtoStr((barProgress + barStep) * 100.0, precision);
		
		ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
		
		if (w.ws_col < 100) barWidth = w.ws_col - 4 - progress_perc.length() - 10;
		else barWidth = 96 - progress_perc.length();	

		barProgress += barStep;

		int pos = barWidth * barProgress;

		std::cout << " " << color << left_border;

		for (int count = 0; count < barWidth; count++)
		{
			if (count == pos) std::cout << next_complete << OutputColor.reset;
			else if (count < pos) std::cout << complete;
			else std::cout << not_complete;
		}
		std::cout << color << right_border;

		std::cout << " " << OutputColor.bold_white << 
			"[" << progress_perc << "%]" << OutputColor.reset << " ";

		std::cout << " \r";
		std::cout.flush();

		if (barProgress + barStep/2. >= 1) std::cout << std::endl;
	}
} GenericBar;

struct
{
	void Default(double progress, std::string color = OutputColor.bold_cyan)
	{
		GenericBar.Print(color, "[", "#", "", ".", "] ", progress);
	}

	void ImprovedDefault(double progress, std::string color = OutputColor.bold_cyan)
	{
		GenericBar.Print(color, "⁅", "⁜", "⊳", "~", "⁆", progress);
	}

	void Fancy(double progress, std::string color = OutputColor.bold_cyan)
	{
		GenericBar.Print(color, "◨▣", "▩", "▧", "▫", "▣◧", progress);
	}

	void Fancy1(double progress, std::string color = OutputColor.bold_cyan)
	{
		GenericBar.Print(color, "●", "◎", "○", "◌", "●", progress);
	}

	void Fancy2(double progress, std::string color = OutputColor.bold_red)
	{
		GenericBar.Print(color, "「", "※", "※", "※", " 」", progress);
	}

	void Wave(double progress, std::string color = OutputColor.bold_cyan)
	{
		GenericBar.Print(color, "「", "₪", " ", " ", "」", progress);
	}

	void Block(double progress, std::string color = OutputColor.blue)
	{
		GenericBar.Print(color, "", "▓", "▒", "▒", "", progress);
	}

	void Block1(double progress, std::string color = OutputColor.blue)
	{
		GenericBar.Print(color, "█", "▓", "▒", "▒", "█", progress);
	}

	void Block2(double progress, std::string color = OutputColor.bold_yellow)
	{
		GenericBar.Print(color, "◢█", "▓", "▒", "▒", "█◤", progress);
	}

	void Block3(double progress, std::string color = OutputColor.bold_cyan)
	{
		GenericBar.Print(color, "◢█", "╳", "╲", " ", "█◤", progress);
	}

	//cursed progress bars
	void GachiMuchi(double progress, std::string color = OutputColor.bold_white)
	{
		GenericBar.Print(color, "CUM ", "♂", "○", "♀", " ASS", progress);
	}

	void SUS(double progress, std::string color = OutputColor.bold_red)
	{
		GenericBar.Print(color, "SUS ", "ඞ", "ච", "○", " SUS", progress, " ");
	}	

	void Communism(double progress)
	{
		GenericBar.Print(OutputColor.bold_red, "☭", "✭", "☆", " ", "☭", progress, "☭");
	}	
	
	void Reset()
	{
		GenericBar.barProgress = 0;
	}

	void SetBarStep(double step) 
	{
		GenericBar.barStep = step;
		GenericBar.barProgress = -step/2.;
	}
	void SetPrecision(int precision)
	{
		GenericBar.precision = precision;
	}
	
} ProgressBar;
