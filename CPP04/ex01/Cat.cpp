/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukdid <aboukdid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 20:27:04 by aboukdid          #+#    #+#             */
/*   Updated: 2024/10/12 20:27:23 by aboukdid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "(Cat) constructor called" << std::endl;
	type = "Cat";
}

Cat::Cat(const Cat& obj)
{
	std::cout << "(Cat) copy constructor called" << std::endl;
	type = obj.type;
}

Cat& Cat::operator=(const Cat& obj)
{
	std::cout << "(Cat) copy assignment constructor called" << std::endl;
	if (this != &obj)
		type = obj.type;
	return *this;
}

Cat::~Cat()
{
	std::cout <<"(Cat) destructor called" << std::endl;
}
void	Cat::makeSound() const
{
	std::cout << "The Cat say meao!!" << std::endl;
}