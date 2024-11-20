#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Aboubakr") , grade(50)
{
    std::cout << "Default Constructor Called!!" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Destructor called!!" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name , int grade) : name(name), grade(grade)
{
    std::cout << "Parameterized Constructor Called" << std::endl;
    if (grade < HIGHEST_GRADE)
        throw GradeTooHighExeption();
    else if (grade > LOWEST_GRADE)
        throw GradeTooLowExecption();
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj) : name(obj.name), grade(obj.grade)
{
    std::cout << "Copy  constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj)
{
    std::cout << "Copy assignment operator called " << std::endl;
    if (this != &obj)
        grade = obj.grade;
    return *this;
}

int Bureaucrat::getGrade() const
{
    return (grade);
}

std::string Bureaucrat::getName() const
{
    return (name);
}

const char* Bureaucrat::GradeTooHighExeption::what() const throw()
{
    return ("Grade Too High");
}

const char* Bureaucrat::GradeTooLowExecption::what() const throw()
{
    return ("Grade Too Low");
}

void    Bureaucrat::increment()
{
    grade++;
    if (grade > LOWEST_GRADE)
        throw GradeTooLowExecption();
}

void    Bureaucrat::decrement()
{
    grade--;
    if (grade < HIGHEST_GRADE)
        throw GradeTooHighExeption();
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &obj)
{
    out << obj.getName() << ", bureaucrat grade " << obj.getGrade();
    return out;
}

void Bureaucrat::signForm(Form &form)
{
    try {
        form.beSigned(*this);
        std::cout << this->getName() << " signed " << form.getName() << std::endl;
    } catch (const std::exception& e) {
        std::cout << this->getName() << " couldn't sign " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}
