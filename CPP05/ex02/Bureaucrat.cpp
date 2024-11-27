#include "Bureaucrat.hpp"

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade Too High");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade Too Low");
}

Bureaucrat::Bureaucrat(): name("Default"), grade(50)
{

}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade) 
{
	if (grade < HIGHEST_GRADE)
		throw GradeTooHighException();
	else if (grade > LOWEST_GRADE)
		throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const Bureaucrat& obj) : name(obj.name)
{
	grade = obj.grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj)
{
	if (this != &obj)
		grade = obj.grade;
	return (*this);
}

int Bureaucrat::getGrade() const
{
	return (grade);
}

const std::string Bureaucrat::getName() const
{
	return (name);
}

void Bureaucrat::increment()
{
	if (grade - 1 < HIGHEST_GRADE)
		throw GradeTooHighException();
	grade--;
}

void Bureaucrat::decrement()
{
	if (grade + 1 > LOWEST_GRADE)
		throw GradeTooLowException();
	grade++;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &obj)
{
	out << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return out;
}

void Bureaucrat::signForm(Form &form)
{
    try
    {
        form.beSigned(*this);
        std::cout << this->getName() << " signed " << form.getName() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << this->getName() << " couldn't sign " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}
