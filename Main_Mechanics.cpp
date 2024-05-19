#include "Main_Mechanics.h"
#include "iostream"

RadialTrigger::RadialTrigger()
{
	player = { 400.0f, 400.0f };
	barrel = { 250.0f, 250.0f };
	barrelRad = 20.0f;
	explosionRad = 100.0f;
}

RadialTrigger::~RadialTrigger()noexcept
{

}

void RadialTrigger::RadialVisualRad()
{
	DrawCircleLines(barrel.x, barrel.y, explosionRad, WHITE);
	Barrel();
}

void RadialTrigger::Barrel()
{
	DrawCircle(barrel.x, barrel.y, barrelRad,RED);
}

void RadialTrigger::RadialMechanics()
{
	RadialVisualRad();

	//player to barrel
	Vector2 Distance_Player_Barrel = Vector2Subtract(barrel, player);
	float Len_Player_Barrel = sqrtf((Distance_Player_Barrel.x * Distance_Player_Barrel.x) + (Distance_Player_Barrel.y * Distance_Player_Barrel.y));

	//player
	if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
	{
		player = GetMousePosition();
	}

	DrawCircle(player.x, player.y, 10.0f, BLUE);

	//Line visualization between player and barrel
	DrawLine(player.x, player.y, barrel.x, barrel.y, WHITE);

	

	if (Len_Player_Barrel <= explosionRad)
	{

		DrawText("KABOOM", 60, 60, 20, WHITE);

	}
	DrawText(TextFormat("player X: % f", player.x), 110, 110, 20, WHITE);
	DrawText(TextFormat("player Y: % f", player.y), 110, 90, 20, WHITE);

	DrawText(TextFormat("Distance Player to Barrel: % f", player.y), 110, 420, 20, WHITE);
	
}
