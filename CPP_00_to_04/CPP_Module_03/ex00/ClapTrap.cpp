#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name(""), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

ClapTrap &ClapTrap::operator=(const Fixed &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
	{
		this->_name = src._name;
		this->_hitPoints = src._hitPoints;
		this->_energyPoints = src._energyPoints;
		this->_attackDamage = src._attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	std::cout << "ClapTrap" << this->_name << " attacks " << target << " causing ";
}

/*PROTOTIPO MENSAJE:
ClapTrap <name> attacks <target>, causing <damage> points of damage! */

void ClapTrap::takeDamage(unsigned int amount)
{
	this->_hitPoints -= amount;
	std::cout << "ClapTrap" << this->_name << " takes " << amount << " damage! Now has " << this->_hitPoints << " hit points" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	this->_hitPoints += amount;
	std::cout << "ClapTrap" << this->_name << " regains " << amount << " is repaired! Now has " << this->_hitPoints << " hit points" << std::endl;
}


/*Cuando ClapTrap attack, hace que su objetivo pierda <attack damage>, hit points

Cuando ClapTrap beRepaired, recupera <amount>, hit points

attack y beRepaired cuesta 1 _energyPoint cada uno

sin _energyPoints, ClapTrap no puede hacer nada


 */


//1.takeDamage: recibe daño de algo externo. resta hitPoints

//2.attack: ataca, usa energía

//3.beRepaired: se repara, SUMA hitpoints.