#include "AForm.hpp"

AForm::AForm(): _name("Default"), _signed(false), _signGrade(150), _execGrade(150) {}

AForm::AForm(const std::string& name, int signGrade, int execGrade) : _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade) 
{
    if(signGrade < 1 || execGrade < 1)
        throw GradeTooHighException();
    if(signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
}  

AForm::AForm(const AForm& copy): _name(copy._name), _signed(copy._signed), _signGrade(copy._signGrade), _execGrade(copy._execGrade) {}

AForm& AForm::operator=(const AForm& copy)
{
    _signed = copy._signed;
    return(*this);
}

AForm::~AForm() {}

void    AForm::beSigned(const Bureaucrat& b)
{
    if(b.getGrade() <= _signGrade)
        _signed = true;
    else
        throw GradeTooLowException();
}

void    AForm::execute(const Bureaucrat& executor) const
{
    if (!_signed)
        throw FormNotSignedException();
    if (executor.getGrade() > _execGrade)
        throw GradeTooLowException();
    executeAction();
}

std::string AForm::getName() const
{
    return(_name);
}

bool    AForm::getSigned() const
{
    return(_signed);
}

int    AForm::getSignGrade() const
{
    return(_signGrade);
}

int    AForm::getExecGrade() const
{
    return(_execGrade);
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return("Grade is too high.");
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return("Grade is too low.");
}

const char *AForm::FormNotSignedException::what() const throw()
{
    return ("Form is not signed");
}

std::ostream& operator<<(std::ostream& os, const AForm& f)
{
    os << "Form " << f.getName() << ", signed: " << (f.getSigned()) << ", requires grade " << f.getSignGrade() << " to sign and " << f.getExecGrade() << " to execute.";
    return (os);
}