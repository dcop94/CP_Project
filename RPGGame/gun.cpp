#include "Gun.h"

Gun::Gun() : Weapon(10, 1) {}

void Gun::isAttack()
{
	cout << " ÃÑ½î±â !! " << endl;
	weaponUse();
}