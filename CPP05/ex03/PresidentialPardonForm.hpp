#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class AForm;
class Bureaucrat;

class PresidentialPardonForm : public AForm {
	private:
		const std::string target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string target);
		~PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm& obj);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& obj);
		const std::string getTarget() const;
		void	execute(Bureaucrat const& executor) const;
};

std::ostream &operator<<(std::ostream &out, const PresidentialPardonForm &obj);

#endif