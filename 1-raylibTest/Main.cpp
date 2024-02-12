#include "raylib.h"
#include "raymath.h"

#include "GameManager.cpp"
#include "Hierarchy.cpp"
#include "Player.cpp"

int main() {
	GameManager *GM = new GameManager(60);
	GM->SetWindowSize(800, 600);

	Hierarchy *hierarchy = new Hierarchy();

	Player p = Player();

	hierarchy->AddGameObject(&p);

	GM->SetHierarchy(hierarchy);
	GM->Start();
	GM->Loop();

	delete GM;
	delete hierarchy;

	return 0;
}
