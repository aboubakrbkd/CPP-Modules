#ifndef ShRUBBERYCREATIONFORM_HPP
#define ShRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>
#include "Bureaucrat.hpp"

class AForm;
class Bureaucrat;

class ShrubberyCreationForm : public AForm {
	private:
		const std::string target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string &target);
		~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm& obj);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& obj);
		void execute(Bureaucrat const &executor);
		const std::string getTarget() const;

};

std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm &obj);

#endif