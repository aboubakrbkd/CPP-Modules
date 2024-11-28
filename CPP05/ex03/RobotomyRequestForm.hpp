#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>
#include "Bureaucrat.hpp"

class AForm;
class Bureaucrat;

class RobotomyRequestForm : public AForm {
	private:
		const std::string target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string target);
		~RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm& obj);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& obj);
		const std::string getTarget() const;
		void	execute(Bureaucrat const& executor) const;
};

std::ostream &operator<<(std::ostream &out, const RobotomyRequestForm &obj);
#endif