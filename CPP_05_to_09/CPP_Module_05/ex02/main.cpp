#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include <ctime>
#include <cstdlib>

int main()
{
    std::srand(std::time(NULL));

    std::cout << "---PresidentialPardonForm---" << std::endl;
    Bureaucrat First_Bureaucrat("First Bureaucrat", 1);
    Bureaucrat Second_Bureaucrat("Second Bureaucrat", 140);
    PresidentialPardonForm pardon("Vincent");

    First_Bureaucrat.executeForm(pardon);
    Second_Bureaucrat.signForm(pardon);
    First_Bureaucrat.signForm(pardon);
    Second_Bureaucrat.executeForm(pardon);  // Signed by First Bureaucrat, that's finem but grade 140 is too low to execute.
    First_Bureaucrat.executeForm(pardon);

    std::cout << "\n---RobotomyRequestForm---" << std::endl;
    Bureaucrat Third_Bureaucrat("Third Bureaucrat", 1);
    Bureaucrat Fourth_Bureaucrat("Fourth Bureaucrat", 100);
    RobotomyRequestForm r("Wally");

    Fourth_Bureaucrat.executeForm(r);
    Fourth_Bureaucrat.signForm(r);
    Third_Bureaucrat.signForm(r); 
    Fourth_Bureaucrat.executeForm(r);

    for (int i = 0; i < 6; i++)
        Third_Bureaucrat.executeForm(r);    // ok: random mix of success and failure (50%)

    std::cout << "\n---ShrubberyCreationForm" << std::endl;
    Bureaucrat Fifth_Bureaucrat("Fifth Bureaucrat", 1);
    Bureaucrat Sixth_Bureaucrat("Sixth Bureaucrat", 140);
    ShrubberyCreationForm s1("forest");
    ShrubberyCreationForm s2("park");

    Fifth_Bureaucrat.signForm(s1);
    Fifth_Bureaucrat.executeForm(s1); //ok: creates "forest_shrubbery"
    Fifth_Bureaucrat.executeForm(s2);
    Sixth_Bureaucrat.signForm(s2);
    Sixth_Bureaucrat.executeForm(s2);

    return (0);
}