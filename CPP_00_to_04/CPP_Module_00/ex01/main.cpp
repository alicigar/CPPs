#include "PhoneBook.hpp"
#include <string>
#include <iostream>

int	main(void)
{
	PhoneBook	pb;
	std::string cmd;

	while (1)
	{
		std::cout << "Please, enter one these options: ADD, SEARCH or EXIT" << std::endl;
		std::getline(std::cin, cmd);
		if (cmd == "ADD")
			pb.add();
		else if (cmd == "SEARCH")
			pb.search();
		else if (cmd == "EXIT")
			return (0);
	}
}
