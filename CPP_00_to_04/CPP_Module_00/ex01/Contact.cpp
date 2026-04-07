#include "Contact.hpp"

Contact::Contact()
{
	this->_name = "";
	this->_surname = "";
	this->_nickname = "";
	this->_telephone = "";
	this->_secret = "";
}
Contact::~Contact(){}
void	Contact::setName(std::string name)
{
	this->_name = name;
}
std::string Contact::getName(void)
{
	return(this->_name);
}
void	Contact::setSurname(std::string surname)
{
	this->_surname = surname;
}
std::string Contact::getSurname(void)
{
	return(this->_surname);
}
void	Contact::setNickname(std::string nickname)
{
	this->_nickname = nickname;
}
std::string Contact::getNickname(void)
{
	return(this->_nickname);
}
void	Contact::setTelephone(std::string telephone)
{
	this->_telephone = telephone;
}
std::string Contact::getTelephone(void)
{
	return(this->_telephone);
}
void	Contact::setSecret(std::string secret)
{
	this->_secret = secret;
}
std::string Contact::getSecret(void)
{
	return(this->_secret);
}
