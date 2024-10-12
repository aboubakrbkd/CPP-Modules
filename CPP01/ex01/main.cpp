/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukdid <aboukdid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:35:29 by aboukdid          #+#    #+#             */
/*   Updated: 2024/10/05 20:24:32 by aboukdid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	int n = 5;
	Zombie* zombies = zombieHorde(n, "zombie");
	for (int i = 0; i < n; i++)
		zombies[i].announce();
	delete [] zombies;
}
