#include "Swoard.h"

Swoard::Swoard() : Weapon(5, 3) {}

void Swoard::isAttack()
{
	cout << " Âî¸£±â ! " << endl;
	weaponUse();
}