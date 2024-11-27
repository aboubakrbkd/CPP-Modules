#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:
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
		AForm();
		AForm(std::string name, int sign_grade, int exec_grade);
		~AForm();
		AForm(const AForm& obj);
		AForm& operator=(const AForm& obj);

		const std::string getName() const;
		bool getis_signed() const;
		int getsign_grade() const;
		int getexec_grade() const;

		void	beSigned(Bureaucrat obj);

};

std::ostream &operator<<(std::ostream &out, const AForm &obj);


#endif