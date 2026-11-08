#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default target") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) : AForm(copy), _target(copy._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy)
{
    if(this != &copy)
    {
        AForm::operator=(copy);
        _target = copy._target;
    }
    return(*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void    ShrubberyCreationForm::executeAction() const
{
    std::ofstream file((_target + "_shrubbery").c_str());
    if(!file.is_open())
    {
        std::cout << "Error: could not create file " << _target << "_shrubbery" << std::endl;
        return ;
    }
    const char * tree[] = {
        "    *    ",
        "   ^^^   ",
        "  ^^^^^  ",
        " ^^^^^^^ ",
        "   | |   "
    };
    
    for(int t = 0; t < 3; t++)
    {
        for (int i = 0; i < 5; i++)
            file << tree[i] << std::endl;
        file << std::endl;
    }
    file.close();
}