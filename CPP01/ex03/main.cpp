#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
    Weapon club = Weapon("crude spiked club");
    HumanA bob("Bob", club);
    bob.attack();
    club.setType("some other type of club");

    Weapon club1 = Weapon("crude spiked club");
    HumanB jim("jim");
    jim.setWeapon(club1);
    jim.attack();
    club1.setType("some other type of club");
    jim.attack();

}