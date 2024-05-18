#include "Window.h"

Window::Window(int S_width, int S_height, int S_fps, std::string title)
{
	assert(WindowShouldClose());
	InitWindow(S_width, S_height,title.c_str());
	SetTargetFPS(S_fps);
}

Window::~Window() noexcept
{
	assert(!WindowShouldClose());
	CloseWindow();
}

bool Window::GameShouldClose()
{
	return WindowShouldClose();
}
