#include "FirstLevel.h"

FirstLevel::FirstLevel() {
	Textures* texturesLevels = new Textures();
	texturesLevels->addTexture(1, "Textures/Levels/One/Walls/Wall_1.png");
	scene = new GameScene({ 44, 28 }, { 40, 40 }, texturesLevels);
	scene->setFloor(new Floor({ 22, 14 }, { 128, 128 }, new GameTexture("Textures/Levels/One/Floors/Floor.png")));
	scene->setWalls(0, "0000100000");
	scene->setWalls(1, "0000100000");
	scene->setWalls(2, "0000100000");
	scene->setWalls(4, "1111100000");
}

GameScene* FirstLevel::getGameScene() {
	return scene;
}