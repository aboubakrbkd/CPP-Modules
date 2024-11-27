#include "AForm.hpp"
#include "Bureaucrat.hpp"

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

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

    return 0;
}
