#include "../lib/ProgressBar.h"
#include <unistd.h>

int main()
{
	for (double progress = 0; progress <= 1.00001; progress += 0.01)
	{
		//ProgressBar.Default(progress);
		//ProgressBar.ImprovedDefault(progress);
		//ProgressBar.Fancy(progress);
		//ProgressBar.Fancy1(progress);
		//ProgressBar.Fancy2(progress);
		//ProgressBar.Wave(progress);
		ProgressBar.Block(progress);
		//ProgressBar.Block1(progress);
		//ProgressBar.Block2(progress);
		//ProgressBar.Block3(progress);

		//cursed
		//ProgressBar.SUS(progress);
		//ProgressBar.GachiMuchi(progress);
		//ProgressBar.Communism(progress);

		usleep(1e5);
	}
	return 0;
}
