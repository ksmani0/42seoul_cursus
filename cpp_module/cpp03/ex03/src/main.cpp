#include "DiamondTrap.hpp"

int main(void)
{
    DiamondTrap kim("kim");
	DiamondTrap lee("lee");
	std::cout << std::endl;

	kim.whoAmI();
	lee.whoAmI();
	std::cout << std::endl;

	kim.attack("lee");
	lee.takeDamage(kim.GetAttackDamage());
	std::cout << std::endl;

	lee.attack("kim");
	kim.takeDamage(lee.GetAttackDamage());
	std::cout << std::endl;

	kim.guardGate();
	lee.highFivesGuys();

	return (0);
}