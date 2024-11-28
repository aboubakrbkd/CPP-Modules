#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class AForm;

class Intern {
	public:
		Intern();
		~Intern();
		Intern(const Intern& obj);
		Intern& operator=(const Intern& obj);
		AForm* makeForm(const std::string form_name, const std::string target);
};

#endif