#include "AForm.hpp"
#include "Bureaucrat.hpp"

int main()
{
    AForm validForm("Valid Form", 50, 100);
    std::cout << validForm << std::endl;
    Bureaucrat john("John", 45);
    std::cout << john << std::endl;
    john.signForm(validForm);
    std::cout << validForm << std::endl;
    try
    {
        AForm highForm("High Form", 0, 10);
    }
    catch (const std::exception &e)
    {
        std::cout << "Error creating High Form: " << e.what() << std::endl;
    }
    try
    {
        AForm lowForm("Low Form", 200, 180);
    }
    catch (const std::exception &e)
    {
        std::cout << "Error creating Low Form: " << e.what() << std::endl;
    }
    Bureaucrat bob("Bob", 150);
    bob.signForm(validForm);
    std::cout << validForm << std::endl;
}
