/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukdid <aboukdid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 20:27:04 by aboukdid          #+#    #+#             */
/*   Updated: 2024/10/13 13:40:33 by aboukdid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "(Cat) constructor called" << std::endl;
	type = "Cat";
	ideas = new Brain();
}

Cat::Cat(const Cat& obj)
{
	std::cout << "(Cat) copy constructor called" << std::endl;
	type = obj.type;
	ideas = new Brain(*obj.ideas);
}

Cat& Cat::operator=(const Cat& obj)
{
	std::cout << "(Cat) copy assignment constructor called" << std::endl;
	if (this != &obj)
	{
		type = obj.type;
		delete ideas;
		ideas = new Brain(*obj.ideas);
	}
	return *this;
}

Cat::~Cat()
{
	std::cout <<"(Cat) destructor called" << std::endl;
	delete ideas;
}
void	Cat::makeSound() const
{
	std::cout << "The Cat say meao!!" << std::endl;
}