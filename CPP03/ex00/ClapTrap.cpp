/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukdid <aboukdid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:29:35 by aboukdid          #+#    #+#             */
/*   Updated: 2024/10/11 10:35:08 by aboukdid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "Parameterized Constructor Called" << std::endl;
	this->name = name;
	hit_points = 10;
	energy_points = 10;
	attack_damage = 0;
}

ClapTrap::ClapTrap()
{
	std::cout << "Default Constructor Called" << std::endl;
	name = "Drift";
	hit_points = 10;
	energy_points = 10;
	attack_damage = 0;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor Called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& obj)
{
	std::cout << "Copy Constructor Called" << std::endl;
	name = obj.name;
	hit_points = obj.hit_points;
	energy_points = obj.energy_points;
	attack_damage = obj.attack_damage;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		name = obj.name;
		hit_points = obj.hit_points;
		energy_points = obj.energy_points;
		attack_damage = obj.attack_damage;
	}
	return *this;
}

void	ClapTrap::attack(const std::string& target)
{
	if (hit_points <= 0 || energy_points <= 0)
	{
		std::cout << "ClapTrap " << name << "can't attack!!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attack_damage << " points of damage!" << std::endl;
	energy_points--;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (hit_points <= 0)
	{
		std::cout << "ClapTrap " << name << "Can't repair because it's have no hit points!" << std::endl;
		return;
	}
	if (energy_points <= 0)
	{
		std::cout << "ClapTrap " << name << "don't have energy to repair himself!" << std::endl;
	}
	hit_points += amount;
	energy_points--;
	std::cout << "ClapTrap " << name << " Repaired himself with " << amount << " points" << std::endl;
	std::cout << "ClapTrap " << name << " have now " << hit_points << " hit_points!" << std::endl;
	std::cout << "ClapTrap " << name << " have now " << energy_points << " energy points!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (hit_points <= 0)
	{
        std::cout << "ClapTrap " << name << " is already out of hit points and can't take any more damage!" << std::endl;
        return;
    }
	std::cout << "ClapTrap " << name << " takes " << amount << " points of damage!" << std::endl;
	if (amount >= hit_points) 
        hit_points = 0;
    else 
        hit_points -= amount;
	std::cout << "ClapTrap " << name << " now has " << hit_points << " hit points remaining." << std::endl;	
}