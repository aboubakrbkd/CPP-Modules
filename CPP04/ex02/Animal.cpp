/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukdid <aboukdid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 14:19:41 by aboukdid          #+#    #+#             */
/*   Updated: 2024/10/13 14:58:54 by aboukdid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "(Animal) constructor called" << std::endl;
	type = "Animal";
}

Animal::Animal(const Animal& obj)
{
	std::cout << "(Animal) copy constructor called" << std::endl;
	type = obj.type;
}

Animal& Animal::operator=(const Animal& obj)
{
	std::cout << "(Animal) copy assignment constructor called" << std::endl;
	if (this != &obj)
		type = obj.type;
	return *this;
}

Animal::~Animal()
{
	std::cout <<"(Animal) destructor called" << std::endl;
}

std::string Animal::getType() const
{
	return (type);
}
