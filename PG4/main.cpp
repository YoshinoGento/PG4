
#include <iostream>
#include <map>
#include "Weapon.h"

int main()
{
    std::map<WeaponId, int> weaponBulletCounts;

    // 武器を登録する
    weaponBulletCounts[WeaponId::Handgun] = 12;
    weaponBulletCounts[WeaponId::SubmachineGun] = 30;
    weaponBulletCounts[WeaponId::RocketLauncher] = 5;

    // Handgunの弾を20発追加する
    weaponBulletCounts[WeaponId::Handgun] += 20;

    // RocketLauncherを発射する
    const WeaponId selectedWeapon = WeaponId::RocketLauncher;

    auto itWeapon = weaponBulletCounts.find(selectedWeapon);

    if (itWeapon == weaponBulletCounts.end())
    {
        std::cout << "Weapon not owned\n";
    }
    else if (itWeapon->second <= 0)
    {
        std::cout << "Out of bullets\n";
    }
    else
    {
        --itWeapon->second;
        std::cout << "Fired\n";
    }

    // 現在の所持武器を一覧表示する
    std::cout << "--- Owned weapons ---\n";

    for (const auto& entry : weaponBulletCounts)
    {
        std::cout << static_cast<int>(entry.first)
            << ": " << entry.second << '\n';
    }

    // Handgunを捨てる
    weaponBulletCounts.erase(WeaponId::Handgun);

    // 削除後の所持武器を一覧表示する
    std::cout << "--- After dropping Handgun ---\n";

    for (const auto& entry : weaponBulletCounts)
    {
        std::cout << static_cast<int>(entry.first)
            << ": " << entry.second << '\n';
    }

    return 0;
}
