/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukdid <aboukdid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 20:40:40 by aboukdid          #+#    #+#             */
/*   Updated: 2024/10/05 11:53:50 by aboukdid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
#define SED_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

class Sed
{
	private:
		std::string s1;
		std::string s2;
		std::string first;
	public:
		void	set_first(std::string first);
		void	set_s1(std::string s1);
		void	set_s2(std::string s2);	
		void	replace();
};

#endif