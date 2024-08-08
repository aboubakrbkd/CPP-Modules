#include "Zombie.hpp"
#include <stdlib.h>

int	main()
{
    int N = 5;
    std::string name = "Aboubakr";
    Zombie *horde;

    horde = zombieHorde(N, name);
    for (int i = 0; i < N; i++)
        horde[i].announce();
    delete [] horde;
}