#pragma once

#ifndef GUN_H
#define GUN_H

#include "Weapon.h"

class Gun : public Weapon
{
public:
	Gun();
	void isAttack() override;
};

#endif // !GUN_H
