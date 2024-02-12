#ifndef GameManagerClass
#define GameManagerClass 1

#include "raylib.h"
#include "raymath.h"
#include <string>
#include <cmath>
#include <sstream>
#include <tuple>

#include "hierarchy.cpp"

class GameManager {
public :
	int UnitSizePixel = 100;
	int ScreenSizeWidth = 800;
	int ScreenSizeHeight = 600;
	int FontSize = 16;
	int TargetFPS = 500;

	bool ScreenFlex = false;
	bool UseVsync = true;
	bool ShowFPS = true;

	bool MSAA_4X = true;

	Hierarchy *hierarchy;

	Color DefaultBackgroundColor = BLACK;
	std::string WindowTitle = "Game Manager";

	GameManager() {}
	GameManager(int TargetFPS) : TargetFPS(TargetFPS) {}
	GameManager(bool UseVsync) : UseVsync(UseVsync) {}

	void SetHierarchy(Hierarchy* hierarchy) {
		this->hierarchy = hierarchy;
	}

	void SetWindowSize(std::tuple<int, int> Sizes) {
		this->SetWindowSize(std::get<0>(Sizes), std::get<1>(Sizes));
	}

	void SetWindowSize(int Width, int Height) {
		this->ScreenSizeWidth = Width;
		this->ScreenSizeHeight = Height;
	}

	void Start() {
		SetTargetFPS(this->TargetFPS);

		if (this->UseVsync)
			SetConfigFlags(FLAG_VSYNC_HINT);
		if(this->MSAA_4X)
			SetConfigFlags(FLAG_MSAA_4X_HINT);

		InitWindow(this->ScreenSizeWidth, this->ScreenSizeHeight, this->WindowTitle.c_str());

		for (int i = 0; i < hierarchy->hierarchy.size(); i++)
		{
			hierarchy->hierarchy[i]->Start();
		}
	}

	void Loop() {

		while (!WindowShouldClose()) {
			BeginDrawing();
			ClearBackground(this->DefaultBackgroundColor);

			float dTime = GetFrameTime();

			for (int i = 0; i < hierarchy->hierarchy.size(); i++)
			{
				hierarchy->hierarchy[i]->Update(dTime);
				hierarchy->hierarchy[i]->LateUpdate(dTime);
				hierarchy->hierarchy[i]->Draw();
			}

			if (this->ShowFPS)
				this->ShowFPSonWindow(dTime);

			if (IsKeyDown(KEY_ESCAPE)) {
				CloseWindow();
			}

			EndDrawing();
		}

		CloseWindow();
	}

	void ShowFPSonWindow(float dTime) {
		std::ostringstream oss;
		oss << "FPS: " << std::to_string(static_cast<int>(round(1.0f / dTime)));
		
		int fSize = this->FontSize;
		int padding = fSize / 2;

		DrawRectangle(0, 0, (padding * 2) + MeasureText(oss.str().c_str(), fSize), (padding * 2) + fSize, Fade(WHITE, 0.25));
		DrawText(oss.str().c_str(), padding, padding, fSize, GREEN);
	}
};

#endif
