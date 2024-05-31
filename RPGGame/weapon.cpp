#include "Weapon.h"

Weapon::Weapon(int damage, int count, string name) 
	: weaponDamage(damage), weaponUseNum(count), weaponName(name) {}

// 무기 사용 횟수 
int Weapon::isAttack()
{
	if (weaponUseNum > 0)
	{
		weaponUseNum--;
		cout << " [ 무기 사용 횟수 : " << weaponUseNum << " ] " << endl;
		return weaponDamage;
	}
	else
	{
		cout << " [ 무기를 사용 할 수 없습니다 ! ] " << endl;
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


// 검 관련 무기 정보
Sword::Sword() : Weapon(13, 4, "초보자 목검") {}


int Sword::isAttack()
{
	int damage = Weapon::isAttack();
	if (damage > 0)
	{
		cout << " [ 베기 ! ] " << endl;
	}
	return damage;
}

// 총 관련 무기 정보
Gun::Gun() : Weapon(17, 3, "초보자 권총") {}

int Gun::isAttack()
{
	int damage = Weapon::isAttack();
	if (damage > 0)
	{
		cout << " [ 단발 ! ] " << endl;
	}
	return damage;
}