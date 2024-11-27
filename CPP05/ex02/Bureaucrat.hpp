#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include "AForm.hpp"

#define HIGHEST_GRADE 1
#define LOWEST_GRADE 150

class AForm;

class Bureaucrat {
	private:
		const std::string name;
		int grade;
	public:
		class GradeTooHighException : public std::exception {
			public:
				const char *what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char *what() const throw();
		};
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat& obj);
		Bureaucrat& operator=(const Bureaucrat& obj);

		const std::string getName() const;
		int getGrade() const;

		void	increment();
		void	decrement();

		void	signForm(AForm &form);
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &obj);

#endif