#pragma once
#include "raylib.h"
#include "string"
#include "assert.h"
#include "Main_Mechanics.h"

class Window {
public:
	Window(int S_width, int S_height, int S_fps, std::string title );
	~Window()noexcept;
	bool GameShouldClose();

};
