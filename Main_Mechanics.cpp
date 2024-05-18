#include "Main_Mechanics.h"

RadialTrigger::RadialTrigger()
{
	player = { 400.0f, 400.0f };
	barrel = { 250.0f, 250.0f };
}

RadialTrigger::~RadialTrigger()noexcept
{

}

void RadialTrigger::RadialVisualRad()
{
	DrawCircleLines(barrel.x, barrel.y, 100.0f, WHITE);
	Barrel();
}

void RadialTrigger::Barrel()
{
	DrawCircle(250,250, 20.0f,RED);
}

void RadialTrigger::RadialMechanics()
{
	RadialVisualRad();

	Vector2 Distance_Barrel_Player = Vector2Subtract(player, barrel);

	int Len_barrel = sqrtf(barrel.x * barrel.x + barrel.y * barrel.y);

	Vector2 Unit_barrel = {barrel.x / Len_barrel, barrel.y / Len_barrel};

	float scalarproj = Vector2DotProduct(Unit_barrel, Distance_Barrel_Player);

	//player
	if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
	{
		player = GetMousePosition();
	}

	DrawCircle(player.x, player.y, 10.0f, BLUE);


	//Detection
	DrawLine(barrel.x, barrel.y, barrel.x + Unit_barrel.x * scalarproj, barrel.y + Unit_barrel.y * scalarproj, WHITE);

	if (Unit_barrel.x < 0 && Unit_barrel.y < 0)
	{
		DrawText("KABOOM", 100, 100, 20, WHITE);
	}
	if (scalarproj * Unit_barrel.x >= 100.0f && scalarproj * Unit_barrel.y >= 100.0f)
	{
		DrawText("NOT KABOOM", 100, 100, 20, WHITE);
	}
	
	
}
