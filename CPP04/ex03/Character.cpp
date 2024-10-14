/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukdid <aboukdid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:26:37 by aboukdid          #+#    #+#             */
/*   Updated: 2024/10/14 16:50:06 by aboukdid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
	std::cout << "(Character) default constructor called" << std::endl;
	for (int i  = 0; i < 4; i++)
		slots[i] = NULL;
	name = "Drift";
}

Character::Character(std::string name)
{
	std::cout << "(Character) Parametrized constructor called" << std::endl;
	this->name = name;
	for (int i = 0; i < 4; i++)
		slots[i] = NULL;
}

Character::~Character()
{
	std::cout << "(Character) destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (slots[i])
			delete slots[i];
	}
}

Character::Character(const Character& obj)
{
	std::cout << "(Character) copy constructor called" << std::endl;
	name = obj.name;
	for (int i = 0; i < 4; i++)
	{
		if (obj.slots[i])
			slots[i] = obj.slots[i]->clone();
		else
			slots[i] = NULL;
	}
}

Character& Character::operator=(const Character& obj)
{
	std::cout << "(Character) Copyassignment operator called" << std::endl;
	if (this != &obj)
	{
		name = obj.name;
		for (int i = 0; i < 4; i++)
		{
			if (obj.slots[i])
				slots[i] = obj.slots[i]->clone();
			else
				slots[i] = NULL;
		}
	}
	return *this;
}
std::string const& Character::getName() const
{
	return name;
}

void	Character::equip(AMateria* m)
{
	if (!m)
		return ;
	for (int i =0; i < 4; i++)
	{
		if (slots[i] == NULL)
		{
			slots[i] = m->clone();
			std::cout << "equipped at: " << i << std::endl;
			return ;
		}
	}
	std::cout <<"inventory is full" << std::endl;
}

void	Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4)
	{
		slots[idx] = NULL;
	std::cout << "unequip materia in slot: " << idx << std::endl;
	}
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && slots[idx] != NULL)
		slots[idx]->use(target);
	else
		std::cout << "Cannot use Materia at slot " << idx << std::endl;
}
