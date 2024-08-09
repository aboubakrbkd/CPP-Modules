#include "Harl.hpp"

Harl::Harl()
{
    return ;
}

void    Harl::debug()
{
     std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}


void    Harl::info()
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didnt putenough bacon in my burger! If you did, I wouldnt be asking for more!" << std::endl;
}

void    Harl::warning()
{
    std::cout << "I think I deserve to have some extra bacon for free. Ive been coming for years whereas you started working here since last month." << std::endl;
}

void    Harl::error()
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void    Harl::complain(std::string level)
{
    typedef void (Harl::*Member_func)();
    Member_func func[]={&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string levels[]={"DEBUG", "INFO", "WARNING", "ERROR"};
    for(int i = 0; i < 4; i++)
    {
        if (level == levels[i])
        {
            (this->*func[i])();
            return ;
        }
    }
    std::cout << "Another Bla Bla" << std::endl;
}