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
	std::cout << "Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade) 
{
	std::cout << "Parameterized constructor called" << std::endl;
	if (grade < HIGHEST_GRADE)
		throw GradeTooHighException();
	else if (grade > LOWEST_GRADE)
		throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& obj) : name(obj.name)
{
	std::cout << "Copy Constructor Called" << std::endl;
	grade = obj.grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj)
{
	std::cout << "Copy assignment consructor called" << std::endl;
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