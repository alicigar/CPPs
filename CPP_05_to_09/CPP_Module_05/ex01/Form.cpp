#include "Form.hpp"

Form::Form(): _name("Default"), _signed(false), _signGrade(150), _execGrade(150) {}

Form::Form(const std::string& name, int signGrade, int execGrade) : _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade) 
{
    if(signGrade < 1 || execGrade < 1)
        throw GradeTooHighException();
    if(signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
}  

Form::Form(const Form& copy): _name(copy._name), _signed(copy._signed), _signGrade(copy._signGrade), _execGrade(copy._execGrade) {}

Form& Form::operator=(const Form& copy)
{
    _signed = copy._signed;
    return(*this);
}

Form::~Form() {}

void    Form::beSigned(const Bureaucrat& b)
{
    if(b.getGrade() <= _signGrade)
        _signed = true;
    else
        throw GradeTooLowException();
}

std::string Form::getName() const
{
    return(_name);
}

bool    Form::getSigned() const
{
    return(_signed);
}

int    Form::getSignGrade() const
{
    return(_signGrade);
}

int    Form::getExecGrade() const
{
    return(_execGrade);
}

const char *Form::GradeTooHighException::what() const throw()
{
    return("Grade is too high.");
}

const char *Form::GradeTooLowException::what() const throw()
{
    return("Grade is too low.");
}

std::ostream& operator<<(std::ostream& os, const Form& f)
{
    os << "Form: " << f.getName() << " , signed: " << f.getSigned() << " Required grade:  " << f.getSignGrade() << " to sign and : " << f.getExecGrade() << " to execute. ";
    return(os);
}