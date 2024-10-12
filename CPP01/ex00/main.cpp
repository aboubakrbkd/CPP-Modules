/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukdid <aboukdid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 14:51:51 by aboukdid          #+#    #+#             */
/*   Updated: 2024/10/05 17:24:06 by aboukdid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	std::cout << "-------Stack Zombie-------" << std::endl;
	randomChump("Zombie1");
	randomChump("Zombie2");
	randomChump("Zombie3");
	std::cout << "-------Heap Zombie-------" << std::endl;
	Zombie* z4 = newZombie("Zombie4");
	Zombie* z5 = newZombie("Zombie5");
	Zombie* z6 = newZombie("Zombie6");
	z4->announce();
	z5->announce();
	z6->announce();
	delete z4;
	delete z5;
	delete z6;
}
