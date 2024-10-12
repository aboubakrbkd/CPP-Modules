/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukdid <aboukdid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:35:37 by aboukdid          #+#    #+#             */
/*   Updated: 2024/10/05 20:32:24 by aboukdid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	if (N <= 0)
    {
        std::cout << "Error: N must be a positive integer." << std::endl;
        return NULL;
    }
	Zombie *zombie = new Zombie[N];
	for (int i = 0; i < N ; i++)
		zombie[i].setname(name);
	return (zombie);
}
