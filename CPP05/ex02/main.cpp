#include "Form.hpp"
#include "Bureaucrat.hpp"

int main()
{
    Form validForm("Valid Form", 50, 100);
    std::cout << validForm << std::endl;
    Bureaucrat john("John", 45);
    std::cout << john << std::endl;
    john.signForm(validForm);
    std::cout << validForm << std::endl;
    try
    {
        Form highForm("High Form", 0, 10);
    }
    catch (const std::exception &e)
    {
        std::cout << "Error creating High Form: " << e.what() << std::endl;
    }
    try
    {
        Form lowForm("Low Form", 200, 180);
    }
    catch (const std::exception &e)
    {
        std::cout << "Error creating Low Form: " << e.what() << std::endl;
    }
    Bureaucrat bob("Bob", 150);
    bob.signForm(validForm);
    std::cout << validForm << std::endl;
}
