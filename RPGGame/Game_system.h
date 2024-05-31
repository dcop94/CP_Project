#pragma once
#ifndef GAME_SYSTEM_H
#define GAME_SYSTEM_H

#include <iostream>
#include <vector>
#include "Character.h"
#include "Weapon.h"



class Game
{
private:
	Character player;
	vector<Weapon*> weapons;


public:
	Game();

	void start();

	void explainGame();
	void createCharacter();

	void showMenu();
	void infoCharacter();
	void huntMonster();
	void showInventory();
	void saveGame();
	void loadGame();

};

#endif // !GAME_SYSTEM_H
