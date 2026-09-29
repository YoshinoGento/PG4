#include <iostream>
#include <map>
#include "Weapon.h"

int main()
{

    std::map<WeaponId, int> weaponBulletCounts;

    weaponBulletCounts[WeaponId::Handgun] = 12;

    std::cout << weaponBulletCounts.size() << '\n';
    std::cout << weaponBulletCounts[WeaponId::Handgun] << '\n';

    return 0;
}