#include "Weapon.h"

Weapon::Weapon(int damage, int count, string name) 
	: weaponDamage(damage), weaponUseNum(count), weaponName(name) {}

// ���� ��� Ƚ�� 
int Weapon::isAttack()
{
	if (weaponUseNum > 0)
	{
		weaponUseNum--;
		cout << " [ ���� ��� Ƚ�� : " << weaponUseNum << " ] " << endl;
		return weaponDamage;
	}
	else
	{
		cout << " [ ���⸦ ��� �� �� �����ϴ� ! ] " << endl;
		return 0;
	}
}

string Weapon::getWeaponName()
{
	return weaponName;
}

int Weapon::getWeaponDamage()
{
	return weaponDamage;
}

int Weapon::getWeaponUseNum()
{
	return weaponUseNum;
}


// �� ���� ���� ����
Sword::Sword() : Weapon(13, 4, "�ʺ��� ���") {}


int Sword::isAttack()
{
	int damage = Weapon::isAttack();
	if (damage > 0)
	{
		cout << " [ ���� ! ] " << endl;
	}
	return damage;
}

// �� ���� ���� ����
Gun::Gun() : Weapon(17, 3, "�ʺ��� ����") {}

int Gun::isAttack()
{
	int damage = Weapon::isAttack();
	if (damage > 0)
	{
		cout << " [ �ܹ� ! ] " << endl;
	}
	return damage;
}