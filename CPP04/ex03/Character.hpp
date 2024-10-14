/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukdid <aboukdid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:25:21 by aboukdid          #+#    #+#             */
/*   Updated: 2024/10/14 16:38:43 by aboukdid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include"ICharacter.hpp"

class ICharacter ;

class Character : public ICharacter
{
	private:
		std::string name;
		AMateria* slots[4];
	public:
		Character();
		Character(std::string name);
		~Character();
		Character(const Character& obj);
		Character& operator=(const Character& obj);
		std::string const& getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};


#endif