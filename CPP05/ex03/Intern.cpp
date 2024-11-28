#include "Intern.hpp"


Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern& obj) {
	(void) obj;
}

Intern& Intern::operator=(const Intern& obj) {
	    if (this == &obj)
        return *this;
    return *this;
}


AForm* makeShrubberyCreationForm(const std::string target)
{
	return(new ShrubberyCreationForm(target));
}

AForm* makeRobotomyRequestForm(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm* makePresidentialPardonForm(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(const std::string form_name, const std::string target)
{
	AForm*	(*funct_ptr[3])(const std::string) = {&makePresidentialPardonForm, &makeRobotomyRequestForm, &makeShrubberyCreationForm};
	std::string levels[3] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
	for (int i = 0; i < 3; i++)
	{
		if (form_name == levels[i])
		{
			std::cout << "Intern creates " << form_name << "." << std::endl;
			return (funct_ptr[i](target));
		}
	}
	std::cout << "Error creating the Form" << std::endl;
	return (NULL);
}
