/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukdid <aboukdid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:29:39 by aboukdid          #+#    #+#             */
/*   Updated: 2024/10/11 11:05:36 by aboukdid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	ScavTrap robot;
	robot.attack("me");
	robot.takeDamage(5);
	robot.beRepaired(7);
	robot.attack("alae");
	robot.guardGate();
	return (0);
	
}
