#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    Intern intern;

    AForm* form1 = intern.makeForm("ShrubberyCreationForm", "Garden");

    if (form1) {
        try {
            Bureaucrat executor("John", 1);
            form1->beSigned(executor);
            form1->execute(executor);
        } catch (std::exception &e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
        delete form1;
    }

}