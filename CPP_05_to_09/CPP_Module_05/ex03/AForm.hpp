#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"

class AForm
{
    private:
        const std::string _name;
        bool              _signed;
        const int         _signGrade;
        const int         _execGrade;
    
    protected:
        virtual void       executeAction() const = 0;

    public:
        AForm();
        AForm(const std::string& name, int signGrade, int execGrade);
        AForm(const AForm& copy);
        AForm& operator=(const AForm& copy);
        virtual ~AForm();

        void        beSigned(const Bureaucrat& b);
        void        execute(const Bureaucrat& executor) const;
        std::string getName() const;
        bool        getSigned() const;
        int         getSignGrade() const;
        int         getExecGrade() const;

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

        class FormNotSignedException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif