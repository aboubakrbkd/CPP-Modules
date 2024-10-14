/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukdid <aboukdid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 13:18:41 by aboukdid          #+#    #+#             */
/*   Updated: 2024/10/13 13:54:10 by aboukdid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "(Brain) Default constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "(Brain) Destructor called" << std::endl;
}

Brain::Brain(const Brain& obj)
{
	std::cout << "(Brain) copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = obj.ideas[i];
}

Brain& Brain::operator=(const Brain& obj)
{
	std::cout << "(brain) copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		for (int i = 0; i < 100; i++)
			ideas[i] = obj.ideas[i];
	}
	return *this;
}