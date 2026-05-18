#include "ClapTrap.hpp"

int main()
{
	ClapTrap seagull("Seagull");

	seagull.attack("Cat");
	seagull.takeDamage(3);
	seagull.beRepaired(2);
	return (0);
}
