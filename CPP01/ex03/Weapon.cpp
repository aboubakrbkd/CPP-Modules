#include "Weapon.hpp"

Weapon::Weapon()
{
    return ;
}

Weapon::Weapon(std::string name)
{
    this->type = name;
    return ;
}

std::string Weapon::getType()
{
    return (type);
}

void    Weapon::setType(std::string name)
{
    this->type = name;
    return ;
}
