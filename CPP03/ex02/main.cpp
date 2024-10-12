/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukdid <aboukdid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:29:39 by aboukdid          #+#    #+#             */
/*   Updated: 2024/10/11 11:08:23 by aboukdid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
	FragTrap k;
	k.attack("me");
	k.attack("robot");
	k.beRepaired(8);
	k.takeDamage(20);
	k.highFivesGuys();
	return (0);
}
