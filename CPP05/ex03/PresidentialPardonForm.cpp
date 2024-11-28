#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Pardon", 25, 5), target("Pardon")
{

}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("Pardon", 25, 5), target(target)
{

}

PresidentialPardonForm::~PresidentialPardonForm()
{

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj) : AForm(obj), target(obj.target) 
{

}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& obj)
{
    if (this != &obj)
        AForm::operator=(obj);
	return *this;
}

const std::string PresidentialPardonForm::getTarget() const
{
	return (target);
}

void	PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
	if (!this->is_signed)
		throw FormNotSignedException();
	if (executor.getGrade() > this->getexec_grade())
        throw AForm::GradeTooLowException();
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

std::ostream &operator<<(std::ostream &out, const PresidentialPardonForm &obj)
{
	out << "PresidentialPardonForm targetting " << obj.getTarget();
	return out;
}