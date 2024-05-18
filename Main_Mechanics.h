#pragma once
#include "raylib.h"
#include "raymath.h"

class RadialTrigger {

private:
	Vector2 player;
	Vector2 barrel;
public:
	RadialTrigger();
	~RadialTrigger()noexcept;

	void RadialVisualRad();
	void Barrel();

	void RadialMechanics();
};
