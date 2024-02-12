#ifndef PlayerClass
#define PlayerClass 1

#include "Raylib.h"
#include "GameObject.cpp"

#include <iostream>

class Player : public GameObject {
public:

	int s = 1;
	Color MyColor = GREEN;

	int Mpixel = 100;
	float speed = 4.3;
	float runSpeed = 5.6;

	int MeterOfPixel = 100;

	int xLocation = 100;
	int yLocation = 100;

	Texture2D texture;

	Player() : GameObject(0, "Player")
	{
		//Image image = LoadImage("Square.png");
		//this->texture = LoadTextureFromImage(image);
		//UnloadImage(image);

	}

	void Update(float dT) override {
		float tempX = 0;
		float tempY = 0;
		float tempSpeed = speed;

		if (IsKeyDown(KEY_W)) {
			tempY -= 1.0f;
		}
		if (IsKeyDown(KEY_S)) {
			tempY += 1.0f;
		}
		if (IsKeyDown(KEY_A)) {
			tempX -= 1.0f;
		}
		if (IsKeyDown(KEY_D)) {
			tempX += 1.0f;
		}

		if (IsKeyDown(KEY_LEFT_SHIFT) || IsKeyDown(KEY_RIGHT_SHIFT)) {
			tempSpeed = runSpeed;
		}

		tempSpeed *= dT;
		tempSpeed *= MeterOfPixel;

		float xSpeed = (tempX * tempSpeed);
		float ySpeed = (tempY * tempSpeed);

		xSpeed = (xSpeed < 0) ? floor(xSpeed) : ceil(xSpeed);
		ySpeed = (ySpeed < 0) ? floor(ySpeed) : ceil(ySpeed);

		xLocation += xSpeed;
		yLocation += ySpeed;

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			if (s == 1) {
				s = 2;
				MyColor = BLUE;
			}
			else {
				s = 1;
				MyColor = GREEN;
			}
		}

	}

	void LateUpdate(float dT) override {}
	void Start() override {}

	void Draw() override {
		DrawCircle(xLocation, yLocation, 64, MyColor);
		//DrawTexture(texture, xLocation, yLocation, WHITE);
	}

	~Player() {
		UnloadTexture(texture);
	}

};

#endif // !Player
