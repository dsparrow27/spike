#include "graphics\window.h"

int main()
{
	Window window("spike", 960, 540);

	while (!window.closed())
	{
		window.clear();
		window.update();
	}
	return 0;
}