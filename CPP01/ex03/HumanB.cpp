#include "HumanB.hpp"

HumanB::HumanB(std::string name) : weapon(NULL)
{
    this->name = name;
    return ;
}

void    HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
}

HumanB::~HumanB()
{
    std::cout << "Good Bye HumanB" << std::endl;
}

void    HumanB::attack()
{
    if (weapon == NULL)
        std::cout << "We dont have a weapon" << std::endl;
    else
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}