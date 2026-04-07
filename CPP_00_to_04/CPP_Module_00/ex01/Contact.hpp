#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact
{
	private:
		std::string _name;
		std::string _surname;
		std::string _nickname;
		std::string _telephone;
		std::string _secret;
	public:
		Contact();
		~Contact();
		void	setName(std::string name);
		std::string getName(void);
		void	setSurname(std::string surname);
		std::string getSurname(void);
		void	setNickname(std::string nickname);
		std::string getNickname(void);
		void	setTelephone(std::string telephone);
		std::string getTelephone(void);
		void	setSecret(std::string secret);
		std::string getSecret(void);
};

#endif