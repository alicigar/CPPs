#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    ScavTrap seagull("Seagull");
	ScavTrap cat("Cat");

    seagull.attack("Cat");
    cat.takeDamage(50);
    cat.beRepaired(20);
	cat.takeDamage(100);
    cat.beRepaired(20);
    seagull.guardGate();

    return (0);
}
