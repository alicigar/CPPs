#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iomanip>
# include <string>
# include <iostream>
# include <cstdlib>

class PhoneBook
{
	private:
		Contact	_contacts[8];
		int		_total;
		int		_next;
	public:
		PhoneBook();
		~PhoneBook();
		std::string checkEmptyName(std::string message);
		std::string checkEmptyPhone(std::string message);
		std::string	truncate(std::string str);
		void	add(void);
		void	search(void);
};

#endif