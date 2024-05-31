#pragma once
#ifndef MONSTER_H
#define MONSTER_H

#include <iostream>
#include <string>

using namespace std;

class Monster
{
protected:
	int hp;
	int level;
	int monsterDamage;
	int exp;
	string type;

public:
	Monster(int m_hp, int m_level, int m_damage, int m_exp, string m_type);
	virtual void takeDamage(int damage);
	int getHp();
	string getType();
	int getMonsterDamage();
	int getExp();
};

class Slime : public Monster
{
public:
	Slime();
	
};

class Skeleton : public Monster
{
public:
	Skeleton();
};

#endif // !MONSTER_H
