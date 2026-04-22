#include "Zombie.hpp"

int	main()
{
	Zombie *heapZombie;
	Zombie *heapZombieTwo;
	Zombie *heapZombieThree;
	
	randomChump("Richi");
	randomChump("Nico");
	
	heapZombie = newZombie("Vincent");
	heapZombieTwo = newZombie("Nacho");
	heapZombieThree = newZombie("Juanan");
	heapZombie->announce();
	heapZombieTwo->announce();
	heapZombieThree->announce();
	delete heapZombie;
	delete heapZombieTwo;
	delete heapZombieThree;
	
	return (0);
}
