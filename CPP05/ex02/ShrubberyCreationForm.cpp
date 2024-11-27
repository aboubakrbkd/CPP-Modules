#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("TreeForm", 145, 137), target("default")
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("TreeForm", 145, 137), target(target)
{

}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj) : AForm(obj), target(obj.target)
{

}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& obj)
{
    if (this != &obj)
        AForm::operator=(obj);
    return *this;
}

const std::string ShrubberyCreationForm::getTarget() const
{
	return (target);
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor)
{
	if (!this->is_signed)
		throw FormNotSignedException();
	if (executor.getGrade() > this->getexec_grade())
        throw AForm::GradeTooLowException();
	std::ofstream file(target + "_shrubbery");
    if (!file.is_open())
        throw std::ios_base::failure("Failed to open file");
	file << "       _-_\n"
        << "    /~~   ~~\\\n"
        << " /~~         ~~\\\n"
        << "{               }\n"
        << " \\  _-     -_  /\n"
        << "   ~  \\ //  ~\n"
        << "_- -   | | _- _\n"
        << "  _ -  | |   -_\n"
        << "      // \\\n";

    file.close();
    std::cout << "Shrubbery created in " << target << "_shrubbery" << std::endl;
}
	
std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm &obj)
{
	out << "ShrubberyCreationForm targeting: " << obj.getTarget();
	return out;
}