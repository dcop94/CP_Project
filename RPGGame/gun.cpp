#include "Gun.h"

Gun::Gun() : Weapon(10, 1) {}

void Gun::isAttack()
{
	cout << " �ѽ�� !! " << endl;
	weaponUse();
}