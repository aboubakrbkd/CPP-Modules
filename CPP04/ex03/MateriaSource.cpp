/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukdid <aboukdid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:37:41 by aboukdid          #+#    #+#             */
/*   Updated: 2024/10/14 16:37:52 by aboukdid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "(MateriaSource) default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		slots[i] = NULL;
}
MateriaSource::~MateriaSource()
{
	std::cout << "(MateriaSource) destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (slots[i])
			delete slots[i];
	}
}

MateriaSource::MateriaSource(const MateriaSource& obj)
{
	std::cout << "(MateriaSource) copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (obj.slots[i])
			slots[i] = obj.slots[i]->clone();
		else
			slots[i] = NULL;
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& obj)
{
	std::cout << "(MateriaSource) copy asisgnment operator called" << std::endl;
	if (this != &obj)
	{
		for (int i = 0; i < 4; i++)
		{
			if (slots[i])
				delete slots[i];
		}
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

AMateria* MateriaSource::createMateria(std::string const& type)
{
	for (int i = 0; i < 4; i++)
	{
		if (slots[i] && slots[i]->getType() == type)
		{
			std::cout << "Materia of type '" << type << "' created from slot " << i << std::endl;
			return slots[i]->clone();
		}	
	}
	std::cout << "the type does not match any materia type" << std::endl;
	return NULL;
}

void	MateriaSource::learnMateria(AMateria* m)
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
