/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukdid <aboukdid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 20:24:44 by aboukdid          #+#    #+#             */
/*   Updated: 2024/08/06 14:51:14 by aboukdid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <string>

int	Contact::set_first_name(const std::string& name)
{
	std::string new_name;
	int i = 0;
	while (i < name.size())
	{
		if (name[i] != ' ' && name[i] != '\t')
			new_name += name[i];
		i++;
	}
	if (new_name.empty())
		return (1);
	if (new_name.size() > 10)
		first_name = new_name.substr(0, 9) + ".";
	else
		first_name = new_name;
	return (0);
}
int	Contact::set_last_name(const std::string& name)
{
	std::string new_name;
	for (int i = 0; i < name.size(); i++)
	{
		if (name[i] != ' ' && name[i] != '\t')
			new_name += name[i];
	}
	if (new_name.empty())
		return (1);
	if (new_name.size() > 10)
		last_name = new_name.substr(0, 9) + ".";
	else
		last_name = new_name;
	return (0);
}
int	Contact::set_nickname(const std::string& name)
{
	std::string new_nickname;
	for (int i = 0; i < name.size(); i++)
	{
		if (name[i] != ' ' && name[i] != '\t')
			new_nickname += name[i];
	}
	if (new_nickname.empty())
		return (1);
	if (new_nickname.size() > 10)

		nickname = new_nickname.substr(0, 9) + ".";
	else
		nickname = new_nickname;
	return (0);
}
int	Contact::set_phone_number(const std::string& name)
{
	std::string new_number;
	for (int i = 0; i < name.size(); i++)
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
	if (new_number.size() > 10)
	{
		phone_number = new_number.substr(0, 9) + ".";
		return (0);
	}
	phone_number = new_number;
	return (0);
}
int	Contact::set_darkest_secret(const std::string& name)
{
	std::string new_dark;
	
	for (int i = 0; i < name.size(); i++)
	{
		if (name[i] != ' ' && name[i] != '\t')
			new_dark += name[i];
	}
	if (new_dark.empty())
		return (1);
	if (new_dark.size() > 10)
		darkest_secret = new_dark.substr(0, 9) + ".";
	else
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
PhoneBook::PhoneBook()
{
	last_contact = 0;
}

void	PhoneBook::add_contact(const Contact& name)
{
	contacts[last_contact] = name;
	last_contact = (last_contact + 1) % 8;
}
void	PhoneBook::add_to_the_contact(Contact& user)
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

void Contact::show_all(int i)
{
	std::cout << std::setw(10) << i << "|";
    std::cout << std::setw(10) << first_name << "|";
    std::cout << std::setw(10) << last_name << "|";
    std::cout << std::setw(10) << nickname << "|" << std::endl;
}
		
void	PhoneBook::searchcontact(Contact &name)
{
	bool isempty = true;
	std::cout << std::setw(10) << "Index " << "|" ;
	std::cout << std::setw(10) << "First name " << "|" ;
	std::cout << std::setw(10) << "Last name " << "|" ;
	std::cout << std::setw(10) << "Nickname " << "|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	while (1)
	{
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
			break;
		}
		std::string str;
		std::cout << "Enter the index of the contact you want to see: ";
		std::getline(std::cin, str);
		if (str.empty())
			break ;
		int index = std::stoi(str);
		if (index >= 0 && index < 8)
		{
			std::cout << "First name: " << contacts[index].get_first_name() << std::endl;
			std::cout << "Last name: " << contacts[index].get_last_name() << std::endl;
			std::cout << "Nickname: " << contacts[index].get_nickname() << std::endl;
			std::cout << "Phone number: " << contacts[index].get_phone_number() << std::endl;
			std::cout << "Darkest secret: " << contacts[index].get_darkest_secret() << std::endl;
			break ;
		}
		else
		{
			std::cout << "Please enter a valid index" << std::endl;
			break;
		}
	}
}

// i need to check the eof and parse the numbers;

int main(int argc, char **argv)
{
	PhoneBook Person;
	Contact user;
	std::string str;
	while (1)
	{
		std::cout <<"Choose between ADD, SEARCH, EXIT: ";
		std::getline(std::cin, str);
		if (str == "EXIT" || std::cin.eof())
			break ;
		else if (str == "ADD")
			Person.add_to_the_contact(user);
		else if (str == "SEARCH")
			Person.searchcontact(user);
		else
			std::cout << "Please choose between the 3 commands" << std::endl;
	}
	return (0);
}