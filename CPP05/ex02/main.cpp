#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Bureaucrat bob("Bob", 3);
        std::cout << bob << std::endl;
        ShrubberyCreationForm form("garden");
        std::cout << form << std::endl;
        bob.signForm(form);
        form.execute(bob);

    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
	std::cout << "------------------------" << std::endl;
    try {
        Bureaucrat bob("Bob", 3);
        std::cout << bob << std::endl;

        RobotomyRequestForm form("Robot");
        std::cout << form << std::endl;
        bob.signForm(form);
        form.execute(bob);

    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
	std::cout << "--------------------------" << std::endl;
	try {
        Bureaucrat bob("Bob", 3);
        std::cout << bob << std::endl;

        PresidentialPardonForm form("John Doe");
        std::cout << form << std::endl;
        bob.signForm(form);

        form.execute(bob);

    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}
