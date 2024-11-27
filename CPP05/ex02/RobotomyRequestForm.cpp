#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robot", 72, 45), target("Robot")
{

}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("Robot", 72, 45), target(target)
{

}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj) : AForm(obj), target(obj.target)
{

}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& obj)
{
	if (this != &obj)
        AForm::operator=(obj);
    return *this;
}

const std::string RobotomyRequestForm::getTarget() const
{
	return (target);
}

void	RobotomyRequestForm::execute(Bureaucrat const& executor)
{
	int ran;
	if (!this->is_signed)
		throw FormNotSignedException();
	if (executor.getGrade() > this->getexec_grade())
        throw AForm::GradeTooLowException();
	srand(time(NULL));
	ran = rand() % 10 + 1;
	if (ran <= 5)
		std::cout << this->getTarget() << " has been robotomized!" << std::endl;
	else
		std::cout << this->getTarget() << " robotomy failed" << std::endl;

}

std::ostream &operator<<(std::ostream &out, const RobotomyRequestForm &obj)
{
	out << "RobotomyRequestForm targetting " << obj.getTarget();
	return out;
}