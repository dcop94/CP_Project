#pragma once

#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
#include <string>

using namespace std;

class Weapon
{
protected:
	int weaponDamage;
	int weaponUseNum;
	string weaponName;

public:
	Weapon(int damage, int count, string name);
	
	virtual int isAttack();
	string getWeaponName();
	int getWeaponDamage();
	int getWeaponUseNum();
	
};


class Sword : public Weapon
{
public:
	Sword();
	int isAttack() override;
};

class Gun : public Weapon
{
public:
	Gun();
	int isAttack() override;
};



#endif // !WEAPON.H
