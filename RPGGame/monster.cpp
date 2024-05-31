#include "Monster.h"
#include <iostream>

Monster::Monster(int m_hp, int m_level, int m_damage, int m_exp, string m_type)
	: hp(m_hp), level(m_level), monsterDamage(m_damage), exp(m_exp), type(m_type) {}

// 몬스터 데미지
void Monster::takeDamage(int damage)
{
	hp = hp - damage;
	if (hp < 0)
	{
		hp = 0;
	}
}

int Monster::getHp()
{
	return hp;
}

string Monster::getType()
{
	return type;
}

int Monster::getMonsterDamage()
{
	return monsterDamage;
}

int Monster::getExp()
{
	return exp;
}

// 몬스터 정보
Slime::Slime() : Monster(50, 1, 5, 10, "Slime") {}

Skeleton::Skeleton() : Monster(100, 3, 15, 20, "Skeleton") {}

