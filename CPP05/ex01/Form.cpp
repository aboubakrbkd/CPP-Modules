#include "Form.hpp"

const char* Form::GradeTooHighException::what() const throw()
{
    return ("Grade Too High");
}

const char* Form::GradeTooLowException::what() const throw()
{
    return ("Grade Too Low");
}

Form::Form() : name("unnamed"), is_signed(false), sign_grade(5), execute_grade(5)
{
    std::cout << "Default Constructor called" << std::endl;
}

Form::Form(std::string name, int sign_grade, int execute_grade) : name(name), sign_grade(sign_grade), execute_grade(execute_grade)
{
    if (sign_grade < HIGHEST_GRADE || execute_grade < HIGHEST_GRADE)
        throw GradeTooHighException();
    else if (sign_grade > LOWEST_GRADE || execute_grade > LOWEST_GRADE)
        throw GradeTooLowException();
}

Form::~Form()
{
    std::cout << "Destrctor called" << std::endl;
}

Form::Form(const Form &obj) : name(obj.name), is_signed(obj.is_signed), sign_grade(obj.sign_grade), execute_grade(obj.execute_grade)
{
    std::cout << "Copy Constructor Called" << std::endl;
}

Form& Form::operator=(const Form& obj)
{
    if (this != &obj)
        is_signed = obj.is_signed;
    return *this;
}

std::string Form::getName() const 
{
    return(name);
}

bool Form::getIs_Signed() const
{
    return (is_signed);
}

int Form::GetSign_Grade() const
{
    return (sign_grade);
}

int Form::Get_Execute_grade() const
{
    return (execute_grade);
}

std::ostream &operator<<(std::ostream &out, const Form &obj)
{
    out << obj.getName() << obj.Get_Execute_grade() << obj.getIs_Signed() << obj.GetSign_Grade();
    return out;
}

void    Form::beSigned(Bureaucrat &sign)
{
    if (sign.getGrade() > this->GetSign_Grade())
        throw GradeTooLowException();
    this->is_signed = true;
}