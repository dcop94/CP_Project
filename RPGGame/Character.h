#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>
#include "Weapon.h"
#include "Monster.h"
#include <vector>

class Character
{
private:
	string name;
	int hp;
	int level;
	int exp;
	vector<Weapon*> weapons;
	Weapon* equippWeapon;

public:
	Character();
	
	void setName(string newName);
	string getName();

	int getHp();
	void setHp(int newHp);

	int getExp();
	void addExp(int expPoint);
	void levelUp();
	
	void pickWeapon(Weapon* weapon);
	string getEquipWeapon();
	void equipWeapon(Weapon* weapon);
	
	void attack(Monster& target, int weapon_num);
	void takeDamage(int damage);
	

};

#endif // !CHARACTER_H
