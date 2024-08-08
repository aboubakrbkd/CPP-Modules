#include "Zombie.hpp"
#include <stdlib.h>



Zombie* zombieHorde(int N, std::string name)
{
    Zombie* zombie = new Zombie[N];
    for (int i = 0; i < N; i++)
        zombie->set_name(name);
    return (zombie);
}
