/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukdid <aboukdid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 16:17:43 by aboukdid          #+#    #+#             */
/*   Updated: 2024/10/14 16:38:28 by aboukdid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
	std::cout << "(AMateria) default constructor has been called" << std::endl;
}
AMateria::AMateria(std::string const& type)
{
	std::cout << "(AMateria) paramterized constructor has been called" << std::endl;
	this->type = type;
}
AMateria::AMateria(const AMateria& obj)
{
	std::cout << "(AMateria) copy constructor has been called" << std::endl;
	type = obj.type;
}
AMateria::~AMateria()
{
	std::cout << "(AMateria) destructor has been called" << std::endl;
}
AMateria& AMateria::operator=(const AMateria& obj)
{
	std::cout << "(AMateria) copy assignment constructor called" << std::endl;
	if (this != &obj)
		type = obj.type;
	return (*this);
}

std::string const&  AMateria::getType() const
{
	return (type);
}

void	AMateria::use(ICharacter& target)
{
	std::cout << "* uses unknown materia on " << target.getName() << " *" << std::endl;
}

