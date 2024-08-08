#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
    return ;
}

HumanB::~HumanB()
{
    std::cout << "Good Bye HumanB" << std::endl;
}

void    HumanB::attack()
{
    std::cout << name << "attacks with their " << weapon.getType() << std::endl;
}