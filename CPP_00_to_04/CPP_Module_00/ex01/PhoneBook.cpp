#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    this->_total = 0;
    this->_next = 0;
}

PhoneBook::~PhoneBook(){}

std::string PhoneBook::checkEmptyName(std::string message)
{
    std::string input;
    while (input.empty())
    {
        std::cout << message;
        std::getline(std::cin, input);
		int	i = 0;
		int	valid = 1;
		if (input == "")
			valid = 0;
		while (input[i])
		{
			if (input[i] == ' ')
			{
				i++;
				continue ;
			}
			if (!(input[i] >= 'a' && input[i] <= 'z') && !(input[i] >= 'A' && input[i] <= 'Z'))
			{
				std::cout << "Wrong input" << std::endl;
				valid = 0;
				break ;
			}
			i++;
		}
        if (i == 0)
			valid = 0;
		if (valid == 0)
			input = "";
    }
    return (input);
}

std::string PhoneBook::checkEmptyPhone(std::string message)
{
    std::string input;
    while (input.empty())
    {
        std::cout << message;
        std::getline(std::cin, input);
		int	i = 0;
		int valid = 1;
		if (input == "")
			valid = 0;
		while (input[i])
		{
			if (!(input[i] >= '0' && input[i] <= '9'))
			{
				std::cout << "Wrong input" << std::endl;
				valid = 0;
				break ;
			}
			i++;
		}
        if (i == 0)
			valid = 0;
		if (valid == 0)
			input = "";
    }
    return (input);
}

void    PhoneBook::add(void)
{
    this->_contacts[this->_next].setName(checkEmptyName("First name: "));
    this->_contacts[this->_next].setSurname(checkEmptyName("Last name: "));
    this->_contacts[this->_next].setNickname(checkEmptyName("Nickname: "));
    this->_contacts[this->_next].setTelephone(checkEmptyPhone("Phone number: "));
    this->_contacts[this->_next].setSecret(checkEmptyName("Darkest secret: "));
    this->_next = (this->_next + 1) % 8;
    if (this->_total < 8)
        this->_total++;
}

std::string PhoneBook::truncate(std::string str)
{
    if (str.length() > 10)
        return (str.substr(0, 9) + ".");
    return (str);
}

void    PhoneBook::search(void)
{
    if (this->_total == 0)
    {
        std::cout << "The PhoneBook has no contacts." << std::endl;
        return ;
    }
    std::cout << std::right << std::setw(10) << "Index" << "|" << std::setw(10) << "First Name" << "|" 
	<< std::setw(10) << "Last Name"  << "|" << std::setw(10) << "Nickname"   << "|" << std::endl;
    int i = 0;
    while (i < this->_total)
    {
        std::cout << std::right << std::setw(10) << i << "|" << std::setw(10) 
		<< truncate(this->_contacts[i].getName()) << "|" << std::setw(10) << truncate(this->_contacts[i].getSurname())  
		<< "|" << std::setw(10) << truncate(this->_contacts[i].getNickname()) << "|" << std::endl;
        i++;
    }
    std::string input;
    int         index;
    std::cout << "Enter index: ";
    std::getline(std::cin, input);
    if (input.empty())
    {
        std::cout << "Invalid input" << std::endl;
        return ;
    }
    int j = 0;
    while (j < (int)input.length())
    {
        if (!(input[j] >= '0' && input[j] <= '9'))
        {
            std::cout << "Invalid input" << std::endl;
            return ;
        }
        j++;
    }
    index = std::atoi(input.c_str());
    if (index < 0 || index >= this->_total)
    {
        std::cout << "Invalid index" << std::endl;
        return ;
    }
    std::cout << this->_contacts[index].getName() << std::endl;
    std::cout << this->_contacts[index].getSurname() << std::endl;
    std::cout << this->_contacts[index].getNickname() << std::endl;
    std::cout << this->_contacts[index].getTelephone() << std::endl;
    std::cout << this->_contacts[index].getSecret() << std::endl;
}
