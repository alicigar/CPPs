#include "Bureaucrat.hpp"

int main()
{
    std::cout << "Test 1: valid Bureaucrat" << std::endl;
    try
    {
        Bureaucrat b("First Bureaucrat", 43);
        std::cout << b << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "Test 2: Too high grade" << std::endl;
    try
    {
        Bureaucrat b("Second Bureaucrat", 0);
        std::cout << b << std::endl;
    }
    catch(const Bureaucrat::GradeTooHighException& e)
    {
        std::cout << "Caught GradeTooHighException: " << e.what() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << "Caught std::exception: " << e.what() << std::endl;
    }

    std::cout << "\nTest 3: Too low grade" << std::endl;
    try
    {
        Bureaucrat b("Third Bureaucrat", 151);
        std::cout << b << std::endl;
    }
    catch(const Bureaucrat::GradeTooLowException& e)
    {
        std::cout << "Caught GradeTooLowException: " << e.what() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << "Caught std::exception: " << e.what() << std::endl;
    }

    std::cout << "\nTest 4: Testing increase in limit case" << std::endl;
    try
    {
        Bureaucrat b("Fourth Bureaucrat", 1);
        std::cout << b << std::endl;
        b.incrementGrade();
    }
    catch(const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\nTest 5: Testing decrease in limit case" << std::endl;
    try
    {
        Bureaucrat b("Fifth Bureaucrat", 150);
        std::cout << b << std::endl;
        b.decrementGrade();
    }
    catch(const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\nTest 6: Normal increment and decrement" << std::endl;
    {
        try
        {
            Bureaucrat b("Sixth Bureaucrat", 3);
            std::cout << b << std::endl;
            b.incrementGrade();
            std::cout << b << std::endl;
            b.decrementGrade();
            std::cout << b << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cout << "Error: " << e.what() << std::endl;
        }
        
    }
    return (0);
}