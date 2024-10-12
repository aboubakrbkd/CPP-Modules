/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukdid <aboukdid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 20:40:36 by aboukdid          #+#    #+#             */
/*   Updated: 2024/10/05 21:07:48 by aboukdid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

void	Sed::set_first(std::string first)
{
	this->first = first;
}

void	Sed::set_s1(std::string s1)
{
	this->s1 = s1;
}

void	Sed::set_s2(std::string s2)
{
	this->s2 = s2;
}

void	Sed::replace()
{
	std::ifstream first_file;
	first_file.open(first.c_str());
	if (!first_file.is_open())
	{
		std::cout << "Error opening the file" << std::endl;
		return ;
	}
	std::string last = first + ".replace";
	std::ofstream last_file;
	last_file.open(last.c_str());
	if (!last_file.is_open())
	{
		std::cout << "Error creating the last file" << std::endl;
		first_file.close();
		return ;
	}
	if (s1.empty())
	{
		std::cout << "S1 is empty" << std::endl;
		first_file.close();
		last_file.close();
		return ;
	}
	std::ostringstream tmp;
    tmp << first_file.rdbuf();
    std::string str = tmp.str();
	size_t i = 0;
	while ((i = str.find(s1, i)) != std::string::npos)
	{
		str.erase(i, s1.length());
		str.insert(i, s2);
		i += s2.length();
	}
	last_file << str;
	std::cout << "Mission complete" << std::endl;
	first_file.close();
	last_file.close();
	
}
