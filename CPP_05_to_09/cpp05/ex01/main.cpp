#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << "Test 1: Valid form" << std::endl;
    try
    {
        Form f("Form", 50, 25);
        std::cout << f << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\nTest 2: Too high sign grade form (0)" << std::endl;
    try
    {
        Form f("Wrong Form", 0, 50);
        std::cout << f << std::endl;
    }
    catch (const Form::GradeTooHighException& e)
    {
        std::cout << "Caught GradeTooHighException: " << e.what() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Caught std::exception: " << e.what() << std::endl;
    }

    std::cout << "\nTest 3: Too low execution grade form (151)" << std::endl;
    try
    {
        Form f("Wrong Form", 50, 151);
        std::cout << f << std::endl;
    }
    catch (const Form::GradeTooLowException& e)
    {
        std::cout << "Caught GradeTooLowException: " << e.what() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Caught std::exception: " << e.what() << std::endl;
    }

    std::cout << "\nTest 4: Bureaucrat with enough sign grade" << std::endl;
    try
    {
        Bureaucrat b("Bureaucrat", 10);
        Form f("valid form", 50, 25);
        std::cout << f << std::endl;
        b.signForm(f);
        std::cout << f << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\nTest 5: Bureaucrat with too low grade, so fails to sign" << std::endl;
    try
    {
        Bureaucrat b("Bureaucrat", 120);
        Form f("invalid form", 50, 25);
        b.signForm(f);
        std::cout << f << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\nTest 6: Limit case: all the grades are the same)" << std::endl;
    try
    {
        Bureaucrat b("Bureaucrat", 50);
        Form f("cool form", 50, 50);
        b.signForm(f);
        std::cout << f << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}