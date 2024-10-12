/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukdid <aboukdid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 20:49:22 by aboukdid          #+#    #+#             */
/*   Updated: 2024/10/12 20:49:33 by aboukdid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "(WrongCat) constructor called" << std::endl;
	type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& obj)
{
	std::cout << "(WrongCat) copy constructor called" << std::endl;
	type = obj.type;
}

WrongCat& WrongCat::operator=(const WrongCat& obj)
{
	std::cout << "(WrongCat) copy assignment constructor called" << std::endl;
	if (this != &obj)
		type = obj.type;
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout <<"(WrongCat) destructor called" << std::endl;
}
void	WrongCat::makeSound() const
{
	std::cout << "The WrongCat say meao!!" << std::endl;
}