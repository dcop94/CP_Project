#include "Character.h"
#include "Weapon.h"
#include <iostream>

using namespace std;

Character::Character() : name(""), hp(100), level(1), exp(0), equippWeapon(0) {}

// �÷��̾� �̸� �ޱ�

string Character::getName()
{
	return name;
}

void Character::setName(string newName)
{
	name = newName;
}

// �÷��̾� ü�� ����
int Character::getHp()
{
	return hp;
}

void Character::setHp(int newHp)
{
	hp = newHp;
}

// �÷��̾� ������ ����
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

		cout << " [ ������ ! ] " << endl;
		cout << " ���� ���� : " << level << endl;
		cout << endl;
		cout << " [ ü���� �����Ͽ����ϴ� ! ] " << endl;
		cout << " ���� ü�� :  " << hp << endl;
	}
	
}

// �÷��̾� ���� ���� ����
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
		return " ���� ���� ";
	}
}

void Character::equipWeapon(Weapon* weapon)
{
	equippWeapon = weapon;
}

// �÷��̾� ���� ����
void Character::attack(Monster& target, int weapon_num)
{
	if (equippWeapon != 0)
	{
		int damage = equippWeapon->isAttack();
		target.takeDamage(damage);
	}
	else
	{
		cout << " [ ���⸦ �������ּ��� ! ] " << endl;
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
