#include "Window.h"


int main()
{
	constexpr int Screen_Width = 500;
	constexpr int Screen_Height = 500;
	int Fps = 60;

	Window window{Screen_Width, Screen_Height,Fps, "Radial Trigger Mechanics"};
	
	RadialTrigger radial;
	
	while (!window.GameShouldClose())
	{
		BeginDrawing();
		ClearBackground(BLACK);
		radial.RadialMechanics();
		EndDrawing();
	}

	return 0;
}