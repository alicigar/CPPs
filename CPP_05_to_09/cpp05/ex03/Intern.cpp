#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

typedef AForm* (*FormCreator)(const std::string&);

Intern::Intern() {}

Intern::Intern(const Intern& copy) 
{
    (void)copy;
}

Intern& Intern::operator=(const Intern& copy)
{
    (void)copy;
    return(*this);
}

Intern::~Intern() {}

AForm* Intern::createShrubbery(const std::string& target)
{
    return(new ShrubberyCreationForm(target));
}

AForm* Intern::createRobotomy(const std::string& target)
{
    return(new RobotomyRequestForm(target));
}

AForm* Intern::createPardon(const std::string& target)
{
    return(new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const
{
    const std::string names[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };
    FormCreator creators[3] = {
        &Intern::createShrubbery,
        &Intern::createRobotomy,
        &Intern::createPardon
    };
    for(int i = 0; i < 3; i++)
    {
        if(formName == names[i])
        {
            std::cout << "Intern creates " << formName << std::endl;
            return (creators[i](target));
        }
    }
    std::cout << "Error: form \"" << formName << "\" does not exist" << std::endl;
    return(NULL);
}