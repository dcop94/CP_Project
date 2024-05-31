#pragma once

#ifndef SWOARD_H
#define SWOARD_H

#include "Weapon.h"

class Swoard : public Weapon
{
public:
	Swoard();
	void isAttack() override;
};

#endif // !SWOARD_H
