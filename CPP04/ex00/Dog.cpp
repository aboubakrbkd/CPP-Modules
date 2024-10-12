/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukdid <aboukdid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 20:28:24 by aboukdid          #+#    #+#             */
/*   Updated: 2024/10/12 20:28:43 by aboukdid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "(Dog) constructor called" << std::endl;
	type = "Dog";
}

Dog::Dog(const Dog& obj)
{
	std::cout << "(Dog) copy constructor called" << std::endl;
	type = obj.type;
}

Dog& Dog::operator=(const Dog& obj)
{
	std::cout << "(Dog) copy assignment constructor called" << std::endl;
	if (this != &obj)
		type = obj.type;
	return *this;
}

Dog::~Dog()
{
	std::cout <<"(Dog) destructor called" << std::endl;
}
void	Dog::makeSound() const
{
	std::cout << "The Dog bark!!" << std::endl;
}