#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
    /*ScavTrap seagull("Seagull");
	ScavTrap cat("Cat");

    seagull.attack("Cat");
    cat.takeDamage(50);
    cat.beRepaired(20);
	cat.takeDamage(100);
    cat.beRepaired(20);
    seagull.guardGate();

	FragTrap iberianLynx("Iberian Lynx");
	FragTrap streetCat("Street cat");

    iberianLynx.attack("Iberian Lynx");
    streetCat.takeDamage(50);
    streetCat.beRepaired(20);
    streetCat.takeDamage(100);
    streetCat.beRepaired(20);
    iberianLynx.highFivesGuys();*/


	DiamondTrap ubuntu("Ubuntu");
	DiamondTrap windows("Windows");
	
	ubuntu.attack("Windows");
	windows.takeDamage(20);
	windows.beRepaired(2);
	ubuntu.guardGate();
	ubuntu.highFivesGuys();
	windows.whoAmI();

}
