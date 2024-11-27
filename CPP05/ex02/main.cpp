#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"

int main() {
    // try {
    //     Bureaucrat bob("Bob", 3);
    //     std::cout << bob << std::endl;
    //     ShrubberyCreationForm form("garden");
    //     std::cout << form << std::endl;
    //     bob.signForm(form);
    //     form.execute(bob);

    // } catch (const std::exception &e) {
    //     std::cerr << e.what() << std::endl;
    // }
    try {
        Bureaucrat bob("Bob", 3);  // High enough to sign and execute
        std::cout << bob << std::endl;

        RobotomyRequestForm form("Robot");
        std::cout << form << std::endl;

        // Bob signs the form
        bob.signForm(form);

        // Bob executes the form
        form.execute(bob);

    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}
