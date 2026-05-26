#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
# include <string>

class AAnimal
{
	protected:
		std::string _type;
	public:
		AAnimal();
		AAnimal(std::string type);
		AAnimal(const AAnimal &src);
		AAnimal &operator=(const AAnimal &src);
		virtual ~AAnimal();

		std::string getType() const;
		virtual void makeSound() const = 0;
};

#endif
