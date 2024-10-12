/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukdid <aboukdid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:07:26 by aboukdid          #+#    #+#             */
/*   Updated: 2024/10/11 11:17:10 by aboukdid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name")
{
	std::cout << "Parameterized Constructor called (DiamondTrap)" << std::endl;
	this->name = name;
	hit_points = FragTrap::hit_points;
	energy_points = ScavTrap::energy_points;
	attack_damage = FragTrap::attack_damage;
}

DiamondTrap::DiamondTrap() : ClapTrap("Magnus_clap_name") , FragTrap(), ScavTrap()
{
	std::cout << "Default Constructor called (DiamondTrap)" << std::endl;
	name = "Magnus";
	hit_points = FragTrap::hit_points;
	energy_points = ScavTrap::energy_points;
	attack_damage = FragTrap::attack_damage;
}

DiamondTrap::DiamondTrap(const DiamondTrap& obj) : FragTrap(obj), ScavTrap(obj)
{
	std::cout << "Copy Constructor called (DiamondTrap)" << std::endl;
	name = obj.name;
	hit_points = obj.hit_points;
	energy_points = obj.energy_points;
	attack_damage = obj.attack_damage;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "Destructor called (DiamondTrap)" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& obj)
{
	std::cout << "Copy assignment operator called (DiamondTrap)" << std::endl;
	if (this != &obj)
	{
		ScavTrap::operator=(obj);
		FragTrap::operator=(obj);
	}
	return *this;
}

void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI()
{
	std::cout << "My name is " << name << " ans my ClapTrap name is " << ClapTrap::name << std::endl;
}