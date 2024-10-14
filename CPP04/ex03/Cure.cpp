/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukdid <aboukdid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:21:28 by aboukdid          #+#    #+#             */
/*   Updated: 2024/10/14 16:38:48 by aboukdid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << "(cure) default constructor called" << std::endl;
}
Cure::Cure(const Cure& obj) : AMateria(obj)
{
	std::cout << "(Cure) copy constructor has been called" << std::endl;
	type = obj.type;
}
Cure::~Cure()
{
	std::cout << "(Cure) destrutor has been called" << std::endl;
}
Cure& Cure::operator=(const Cure& obj)
{
	std::cout << "(Cure) copy assignment constructor called" << std::endl;
	if(this != &obj)
		AMateria::operator=(obj);
	return *this;
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
Cure* Cure::clone() const
{
	Cure *res = new Cure;
	return res;
}

