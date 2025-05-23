#pragma once
#include "Tank.h"
#include "Bullets.h"

namespace Tmpl8 {

class Surface;
class Game
{
public:
	void SetTarget( Surface* surface ) { screen = surface; }
	void Init();
	void Shutdown();
	void Tick( float deltaTime );
	void MouseUp( int button ) 
	{ 
		if (button == 1) // Left mouse button
		{
			clicked = false;
		}
	}

	void MouseDown( int button ) 
	{ 
		if (button == 1)
		{
			clicked = true;
		}
	}

	void MouseMove(int x, int y) 
	{ 
		mouseX += x; mouseY += y; 

	}
	void KeyUp(int key) { tanks[0].keyUp(key); }
	void KeyDown(int key) { tanks[0].keyDown(key); }
	static bool CheckPos(float x, float y);
	static bool CheckGun(float x, float y);
	Tank* getTanks() { return tanks; }
	Bullets* getBullets() { return bullets; }

private:
	Surface* screen;
	int lives = 3;
	int collected = 0;

	bool show_game = false;
	bool show_startscreen = true;
	bool show_gameover = false;
	bool show_controls = false;
	bool show_win = false;
	bool resetTankPos = false;

	float mouseX = 0.0f;
	float mouseY = 0.0f;
	bool clicked = false;
	bool enabled = false;

	Tank tanks[6];
	Bullets bullets[6];


	bool tank1 = false;
	bool tank2 = false;
	bool tank3 = false;
	bool tank4 = false;

	bool bullet0 = false;
	bool bullet1 = false;
	bool bullet2 = false;
	bool bullet3 = false;
	bool bullet4 = false;
	bool bullet5 = false;
};
}; // namespace Tmpl8