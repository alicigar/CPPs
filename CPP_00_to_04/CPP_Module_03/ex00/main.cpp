#include "ClapTrap.hpp"

int main()
{
	ClapTrap a("Seagull");

	a.attack("Cat");
	a.takeDamage(5);
	a.beRepaired(2);
	return (0);
}