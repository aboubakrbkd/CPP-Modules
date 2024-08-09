/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukdid <aboukdid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 21:50:25 by aboukdid          #+#    #+#             */
/*   Updated: 2024/08/07 22:14:04 by aboukdid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	std::cout << "----------Heap Zombies----------" << std::endl; 
	Zombie *zombie = newZombie("First");
	Zombie *zombie1 = newZombie("Second");
	zombie->announce();
	zombie1->announce();
	delete(zombie);
	delete(zombie1);
	std::cout << "----------Stack Zombies----------" << std::endl;
	randomChump("First");
	randomChump("second");	
}
