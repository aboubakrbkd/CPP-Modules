#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon weapon)
{
    return;
}

HumanA::~HumanA()
{
    std::cout << "Good bye HumanA" << std::endl;
}

void    HumanA::attack()
{
    std::cout << name << "attacks with their " << weapon.getType() << std::endl;
}
