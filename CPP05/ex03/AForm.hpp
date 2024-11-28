#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	protected:
		const std::string name;
		bool is_signed;
		const int sign_grade;
		const int exec_grade;
	public:
		class GradeTooHighException : public std::exception {
			public:
				const char *what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char *what() const throw();
		};
		class FormNotSignedException : public std::exception {
			public:
				const char *what() const throw();
		};
		AForm();
		AForm(std::string name, int sign_grade, int exec_grade);
		virtual ~AForm();
		AForm(const AForm& obj);
		AForm& operator=(const AForm& obj);

		const std::string getName() const;
		bool getis_signed() const;
		int getsign_grade() const;
		int getexec_grade() const;

		void	beSigned(Bureaucrat obj);
		virtual void execute(Bureaucrat const &executor) const = 0;


};

std::ostream &operator<<(std::ostream &out, const AForm &obj);


#endif