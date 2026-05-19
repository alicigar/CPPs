
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name(""), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << this->_name << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &src)
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
	std::cout << "ClapTrap " << this->_name << " destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " can't attack: no hit points left!" << std::endl;
		return ;
	}
	if (_energyPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " can't attack: no energy points left!" << std::endl;
		return ;
	}
	this->_energyPoints--;
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << _attackDamage << " points of damage! And now has " << this->_energyPoints << " energy points" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if ((int)amount > this->_hitPoints)
		this->_hitPoints = 0;
	else
		this->_hitPoints -= amount;
	std::cout << "ClapTrap " << this->_name << " has received " << amount << " points of damage! And now has " << this->_hitPoints << " hit points left" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " is already dead! No hit points left. " << std::endl;
		return ;
	}
	else if (_energyPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " can't repair: no energy points left!" << std::endl;
		return ;
	}
	this->_energyPoints--;
	this->_hitPoints += amount;
	std::cout << "ClapTrap " << _name << " repairs itself, regaining " << amount << " hit points! Now has " << _hitPoints << " hit points and " << _energyPoints << " energy points" << std::endl;
}