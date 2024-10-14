/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukdid <aboukdid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:23:22 by aboukdid          #+#    #+#             */
/*   Updated: 2024/10/14 16:23:43 by aboukdid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << "(Ice) default constructor called" << std::endl;
}
Ice::Ice(const Ice& obj) : AMateria(obj)
{
	std::cout << "(Ice) copy constructor has been called" << std::endl;
	type = obj.type;
}
Ice::~Ice()
{
	std::cout << "(Ice) destrutor has been called" << std::endl;
}
Ice& Ice::operator=(const Ice& obj)
{
	std::cout << "(Ice) copy assignment constructor called" << std::endl;
	if(this != &obj)
		AMateria::operator=(obj);
	return *this;
}

Ice* Ice::clone() const
{
	Ice *res = new Ice;
	return res;
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" <<  std::endl;
}
