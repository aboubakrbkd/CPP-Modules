/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukdid <aboukdid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 20:43:02 by aboukdid          #+#    #+#             */
/*   Updated: 2024/10/12 20:49:12 by aboukdid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "(WrongAnimal) constructor called" << std::endl;
	type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(const WrongAnimal& obj)
{
	std::cout << "(WrongAnimal) copy constructor called" << std::endl;
	type = obj.type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& obj)
{
	std::cout << "(WrongAnimal) copy assignment constructor called" << std::endl;
	if (this != &obj)
		type = obj.type;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout <<"(WrongAnimal) destructor called" << std::endl;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "The WrongAnimal make a sound" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return (type);
}
