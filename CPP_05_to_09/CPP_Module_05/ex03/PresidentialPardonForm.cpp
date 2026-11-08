#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("default target") {} 

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) : AForm(copy), _target(copy._target)
{
    *this = copy;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& copy)
{
    if(this != &copy)
    {
        AForm::operator=(copy);
        _target = copy._target;
    }
    return(*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm :: executeAction() const
{
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}