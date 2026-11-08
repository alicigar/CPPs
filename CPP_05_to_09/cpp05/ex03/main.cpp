#include <cstdlib>
#include <ctime>
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"

static void test(Intern& i, Bureaucrat& b, const std::string& name, const std::string& target)
{
    AForm* form = i.makeForm(name, target);
    if(form)
    {
        b.signForm(*form);
        b.executeForm(*form);
        delete form;
    }
}

int main()
{
    std::srand(std::time(NULL));

    Intern      i;
    Bureaucrat  b("The Bureaucrat", 1);

    test(i, b, "robotomy request", "Wally");
    test(i, b, "presidential pardon", "Vincent");
    test(i, b, "shrubbery creation", "forest");
    test(i, b, "noria request", "Nico"); // fails: prints error, nothing is created

    return (0);
}