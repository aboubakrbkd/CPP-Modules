/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukdid <aboukdid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 21:46:41 by aboukdid          #+#    #+#             */
/*   Updated: 2024/10/03 14:21:21 by aboukdid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	last_contact = 0;
}
void	PhoneBook::add_contact(Contact name)
{
	contacts[last_contact] = name;
	last_contact = (last_contact + 1) % 8;
}
void	PhoneBook::add_to_the_contact(Contact user)
{
	std::string input;
	std::cout <<"Enter ur First name: ";
	std::getline(std::cin, input);
	if (user.set_first_name(input))
	{
		std::cout << "Please Choose a valid name" << std::endl;
		return ;
	}
	std::cout <<"Enter ur Last name: ";
	std::getline(std::cin, input);
	if (user.set_last_name(input))
	{
		std::cout << "Please choose a valid name" << std::endl;
		return ;
	}
	std::cout << "Enter ur Nickname: ";
	std::getline(std::cin, input);
	if (user.set_nickname(input))
	{
		std::cout << "Please choose a valide nickname" << std::endl;
		return ;
	}
	std::cout << "Enter ur Phone number: ";
	std::getline(std::cin, input);
	if (user.set_phone_number(input))
	{
		std::cout << "Please choose a valide phone number" << std::endl;
		return ;
	}
	std::cout << "Enter ur Darkest secret: ";
	std::getline(std::cin, input);
	if (user.set_darkest_secret(input))
	{
		std::cout << "Please enter a valid secret" << std::endl;
		return ;
	}
	add_contact(user);
}

int	PhoneBook::searchcontact()
{
	bool isempty = true;
	std::cout << std::setw(10) << "Index " << "|" ;
	std::cout << std::setw(10) << "First name " << "|" ;
	std::cout << std::setw(10) << "Last name " << "|" ;
	std::cout << std::setw(10) << "Nickname " << "|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		if (contacts[i].get_first_name().empty())
			break ;
		isempty = false;
		contacts[i].show_all(i);
	}
	if (isempty == true)
	{
		std::cout << "The Phonebook is empty " << std::endl;
		return (1);
	}
	std::string str;
	std::cout << "Enter the index of the contact you want to see: ";
	std::getline(std::cin, str);
	if (str.empty())
	{
		std::cout << "Please enter a valid index" << std::endl;
		return (1);
	}
	if (std::cin.eof())
	{
		std::cout << "\nGood bye" << std::endl;
		exit(0);
	}
	int index = std::atoi(str.c_str());
	if (index >= 0 && index < 8)
	{
		std::cout << "First name: " << contacts[index].get_first_name() << std::endl;
		std::cout << "Last name: " << contacts[index].get_last_name() << std::endl;
		std::cout << "Nickname: " << contacts[index].get_nickname() << std::endl;
		std::cout << "Phone number: " << contacts[index].get_phone_number() << std::endl;
		std::cout << "Darkest secret: " << contacts[index].get_darkest_secret() << std::endl;
		return (0);
	}
	else
	{
		std::cout << "Please enter a valid index" << std::endl;
		return (1);
	}
	return (0);
}
