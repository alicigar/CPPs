#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string _name;
        bool              _signed;
        const int         _signGrade;
        const int         _execGrade;

    public:
        Form();
        Form(const std::string& name, int signGrade, int execGrade);
        Form(const Form& copy);
        Form& operator=(const Form& copy);
        ~Form();

        void        beSigned(const Bureaucrat& b);
        std::string getName() const;
        bool        getSigned() const;
        int        getSignGrade() const;
        int        getExecGrade() const;

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif