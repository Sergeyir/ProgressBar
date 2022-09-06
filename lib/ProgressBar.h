#include <iostream>
#include "../lib/Colors.h"

struct{
	float barStep = 0.01;
	float barProgress = 0.;
	int barWidth = 80;

	void Print(std::string color, std::string left_border, std::string complete, std::string next_complete, std::string not_complete, std::string right_border, float progress, std::string end = "")
	{
		if (progress < barProgress - 1E-15) return;
	
		barProgress += barStep;

		int pos = barWidth * progress;

		std::cout << " " << color << left_border;

		for (int count = 0; count < barWidth; count++)
		{
			if (count == pos) std::cout << next_complete << OutputColor.reset;
			else if (count < pos) std::cout << complete;
			else std::cout << not_complete;
		}
		std::cout << color << right_border;

		int progress_perc = (int) (progress * 100.0);

		std::cout << " " << OutputColor.bold_white << "[" << progress_perc << "%]" << OutputColor.reset << " ";

		std::cout << " \r";
		std::cout.flush();

		if (progress >= 1) std::cout << std::endl;
	}
} GenericBar;

struct
{
	void Default(float progress, std::string color = OutputColor.bold_cyan)
	{
		GenericBar.Print(color, "[", "#", "", ".", "] ", progress);
	}

	void ImprovedDefault(float progress, std::string color = OutputColor.bold_cyan)
	{
		GenericBar.Print(color, "⁅", "⁜", "⊳", "~", "⁆", progress);
	}

	void Fancy(float progress, std::string color = OutputColor.bold_cyan)
	{
		GenericBar.Print(color, "◨▣", "▩", "▧", "▫", "▣◧", progress);
	}

	void Fancy1(float progress, std::string color = OutputColor.bold_cyan)
	{
		GenericBar.Print(color, "●", "◎", "○", "◌", "●", progress);
	}

	void Fancy2(float progress, std::string color = OutputColor.bold_red)
	{
		GenericBar.Print(color, "「", "※", "※", "※", " 」", progress);
	}

	void Wave(float progress, std::string color = OutputColor.bold_cyan)
	{
		GenericBar.Print(color, "「", "₪", " ", " ", "」", progress);
	}

	void Block(float progress, std::string color = OutputColor.blue)
	{
		GenericBar.Print(color, "", "▓", "▒", "▒", "", progress);
	}

	void Block1(float progress, std::string color = OutputColor.blue)
	{
		GenericBar.Print(color, "█", "▓", "▒", "▒", "█", progress);
	}

	void Block2(float progress, std::string color = OutputColor.bold_yellow)
	{
		GenericBar.Print(color, "◢█", "▓", "▒", "▒", "█◤", progress);
	}

	void Block3(float progress, std::string color = OutputColor.bold_cyan)
	{
		GenericBar.Print(color, "◢█", "╳", "╲", " ", "█◤", progress);
	}

	//cursed progress bars
	void GachiMuchi(float progress, std::string color = OutputColor.bold_white)
	{
		GenericBar.Print(color, "CUM ", "♂", "○", "♀", " ASS", progress);
	}

	void SUS(float progress, std::string color = OutputColor.bold_red)
	{
		GenericBar.Print(color, "SUS ", "ඞ", "ච", "○", " SUS", progress, " ");
	}	

	void Communism(float progress)
	{
		GenericBar.Print(OutputColor.bold_red, "☭", "✭", "☆", " ", "☭", progress, "☭");
	}	
} ProgressBar;
