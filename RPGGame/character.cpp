#include "Character.h"
#include "Weapon.h"
#include <iostream>

using namespace std;

Character::Character() : name(""), hp(100), level(1), exp(0), equippWeapon(0) {}

// 플레이어 이름 받기

string Character::getName()
{
	return name;
}

void Character::setName(string newName)
{
	name = newName;
}

// 플레이어 체력 관리
int Character::getHp()
{
	return hp;
}

void Character::setHp(int newHp)
{
	hp = newHp;
}

// 플레이어 레벨업 관리
int Character::getExp()
{
	return exp;
}

void Character::addExp(int expPoint)
{
	exp = exp + expPoint;
}

void Character::levelUp()
{
	if (exp >= 100)
	{
		level++;
		exp = 0;
		hp = 100 + (level - 1) * 35;

		cout << " [ 레벨업 ! ] " << endl;
		cout << " 현재 레벨 : " << level << endl;
		cout << endl;
		cout << " [ 체력이 증가하였습니다 ! ] " << endl;
		cout << " 현재 체력 :  " << hp << endl;
	}
	
}

// 플레이어 무기 장착 관리
void Character::pickWeapon(Weapon* weapon)
{
	weapons.push_back(weapon);
}

string Character::getEquipWeapon()
{
	if (equippWeapon != 0)
	{
		return equippWeapon->getWeaponName();
	}
	else
	{
		return " 무기 없음 ";
	}
}

void Character::equipWeapon(Weapon* weapon)
{
	equippWeapon = weapon;
}

// 플레이어 공격 관리
void Character::attack(Monster& target, int weapon_num)
{
	if (equippWeapon != 0)
	{
		int damage = equippWeapon->isAttack();
		target.takeDamage(damage);
	}
	else
	{
		cout << " [ 무기를 장착해주세요 ! ] " << endl;
	}
}

void Character::takeDamage(int damage)
{
	hp = hp - damage;
	if (hp < 0)
	{
		hp = 0;
	}
}
