#include "AForm.hpp"

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Grade Too High");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Grade Too Low");
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return ("Form not signed");
}

AForm::AForm() : name("unnamed"), is_signed(false), sign_grade(30), exec_grade(15)
{

}

AForm::AForm(std::string name, int sign_grade, int exec_grade) : name(name), is_signed(false), sign_grade(sign_grade) , exec_grade(exec_grade)
{
	if (sign_grade < HIGHEST_GRADE || exec_grade < HIGHEST_GRADE)
		throw GradeTooHighException();
	else if (sign_grade > LOWEST_GRADE || exec_grade > LOWEST_GRADE)
		throw GradeTooLowException();
}

AForm::~AForm()
{

}

AForm::AForm(const AForm& obj) : name(obj.name), is_signed(obj.is_signed), sign_grade(obj.sign_grade) , exec_grade(obj.exec_grade)
{

}

AForm&  AForm::operator=(const AForm& obj)
{
	if (this != &obj)
		is_signed = obj.is_signed;
	return *this;
}

const std::string AForm::getName() const
{
	return (name);
}

bool AForm::getis_signed() const
{
	return (is_signed);
}

int AForm::getsign_grade() const
{
	return (sign_grade);
}

int AForm::getexec_grade() const
{
	return (exec_grade);
}

void	AForm::beSigned(Bureaucrat obj)
{
	if (obj.getGrade() <= this->getsign_grade())
		this->is_signed =true;
	else
		throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &out, const AForm &obj)
{
	out << obj.getName() << " with sign grade " << obj.getsign_grade()
	 << " and a exec grade " << obj.getexec_grade() << " signed: " << (obj.getis_signed() ? "Yes" : "No");
	return out;
}