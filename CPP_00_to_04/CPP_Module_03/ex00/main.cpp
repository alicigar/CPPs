#include "ClapTrap.hpp"

int main()
{
	ClapTrap seagull("Seagull");
	ClapTrap cat("Cat");

	seagull.attack("Cat");
	cat.takeDamage(3);
	cat.beRepaired(2);
	seagull.attack("Cat");
	cat.takeDamage(12);
	cat.beRepaired(1);
	return (0);
}
