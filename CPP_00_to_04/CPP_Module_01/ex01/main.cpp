#include "Zombie.hpp"

int	main()
{
	int	N = 3;
	Zombie* horde = zombieHorde(N, "Rafa");
	
	int	i = 0;
	while (i < N)
	{
		horde[i].announce();
		i++;
	}
	delete[] horde;
	return (0);
}
