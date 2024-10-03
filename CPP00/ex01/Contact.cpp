/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukdid <aboukdid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 19:23:20 by aboukdid          #+#    #+#             */
/*   Updated: 2024/10/03 14:20:04 by aboukdid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	Contact::set_first_name(std::string name)
{
	std::string new_name;
	unsigned long i = 0;
	
	if(std::cin.eof())
	{
		std::cout << "\nGood bye" << std::endl;
		exit(0);
	}
	while (i < name.size())
	{
		if (name[i] != ' ' && name[i] != '\t')
			new_name += name[i];
		i++;
	}
	if (new_name.empty())
		return (1);
	first_name = new_name;
	return (0);
}
int	Contact::set_last_name(std::string name)
{
	std::string new_name;
	if(std::cin.eof())
	{
		std::cout << "\nGood bye" << std::endl;
		exit(0);
	}
	for (unsigned long i = 0; i < name.size(); i++)
	{
		if (name[i] != ' ' && name[i] != '\t')
			new_name += name[i];
	}
	if (new_name.empty())
		return (1);
	last_name = new_name;
	return (0);
}
int	Contact::set_nickname(std::string name)
{
	std::string new_nickname;
	if(std::cin.eof())
	{
		std::cout << "\nGood bye" << std::endl;
		exit(0);
	}
	for (unsigned long i = 0; i < name.size(); i++)
	{
		if (name[i] != ' ' && name[i] != '\t')
			new_nickname += name[i];
	}
	if (new_nickname.empty())
		return (1);
	nickname = new_nickname;
	return (0);
}
int	Contact::set_phone_number(std::string name)
{
	std::string new_number;
	if(std::cin.eof())
	{
		std::cout << "\nGood bye" << std::endl;
		exit(0);
	}
	for (unsigned long i = 0; i < name.size(); i++)
	{
		if (name[i] != ' ' && name[i] != '\t')
		{
			if (!isdigit(name[i]))
				return (1);
			new_number += name[i];
		}
	}
	if (new_number.empty())
		return (1);
	phone_number = new_number;
	return (0);
}
int	Contact::set_darkest_secret(std::string name)
{
	std::string new_dark;
	
	if(std::cin.eof())
	{
		std::cout << "\nGood bye" << std::endl;
		exit(0);
	}
	for (unsigned long i = 0; i < name.size(); i++)
	{
		if (name[i] != ' ' && name[i] != '\t')
			new_dark += name[i];
	}
	if (new_dark.empty())
		return (1);
	darkest_secret = new_dark;
	return (0);
}
std::string	Contact::get_first_name()
{
	return (first_name);
}
std::string	Contact::get_last_name()
{
	return (last_name);
}
std::string	Contact::get_nickname()
{
	return (nickname);
}
std::string	Contact::get_phone_number()
{
	return (phone_number);
}
std::string	Contact::get_darkest_secret()
{
	return (darkest_secret);
}

std::string truncate_with_dot(std::string str)
{
    if (str.length() > 10)
        return (str.substr(0, 9) + ".");
    return str;
}

void Contact::show_all(int i) {
    std::cout << std::setw(10) << i << "|";
    std::cout << std::setw(10) << truncate_with_dot(first_name) << "|";
    std::cout << std::setw(10) << truncate_with_dot(last_name) << "|";
    std::cout << std::setw(10) << truncate_with_dot(nickname) << "|" << std::endl;
}