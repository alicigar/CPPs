#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name)
{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    else
        _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy): _name(copy._name), _grade(copy._grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& copy)
{
    if(this != &copy)
        _grade = copy._grade;
    return(*this);
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const
{
    return (_name);
}

int Bureaucrat::getGrade() const
{
    return (_grade);
}

void    Bureaucrat::incrementGrade()
{
    if(_grade == 1)
        throw GradeTooHighException();
    else
        _grade--;
}

void    Bureaucrat::decrementGrade()
{
    if(_grade == 150)
        throw GradeTooLowException();
    else
        _grade++;
}

void Bureaucrat::signForm(AForm& f)
{
    try
    {
        f.beSigned(*this);
    }
    catch(const std::exception& e)
    {
        std::cout << _name << " couldn't sign " << f.getName() << " because " << e.what() << std::endl;
        return ;
    }
    std::cout << _name << " signed " << f.getName() << std::endl;
}

void Bureaucrat::executeForm(const AForm& f) const
{
    try
    {
        f.execute(*this);
        std::cout << _name << " executed " << f.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << _name << " couldn't execute " << f.getName() << " because " << e.what() << std::endl;
    }
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return("Grade is too high.");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return("Grade is too low.");
}

std::ostream& operator<<(std::ostream& os, Bureaucrat const &b)
{
    os << b.getName() << ", Bureucrat grade: " << b.getGrade() << std::endl;
    return(os);
}