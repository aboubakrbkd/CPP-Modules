/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukdid <aboukdid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 20:24:44 by aboukdid          #+#    #+#             */
/*   Updated: 2024/08/05 17:13:37 by aboukdid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <string>

void	Contact::set_first_name(const std::string& name)
{
	first_name = name;
}
void	Contact::set_last_name(const std::string& name)
{
	first_name = name;
}
void	Contact::set_nickname(const std::string& name)
{
	first_name = name;
}
void	Contact::set_phone_number(const std::string& name)
{
	first_name = name;
}
void	Contact::set_darkest_secret(const std::string& name)
{
	first_name = name;
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
		{
			std::string input;
			std::cout <<"Enter ur First name: ";
			std::getline(std::cin, input);
			user.set_first_name(input);
			std::cout <<"Enter ur Last name: ";
			std::getline(std::cin, input);
			user.set_last_name(input);
			std::cout << "Enter ur Nickname: ";
			std::getline(std::cin, input);
			user.set_last_name(input);
			std::cout << "Enter ur Phone number: ";
			std::getline(std::cin, input);
			user.set_phone_number(input);
			std::cout << "Enter ur Darkest secret: ";
			std::getline(std::cin, input);
			user.set_darkest_secret(input);
			Person.add_contact(user);
		}
		else if (str == "SEARCH")
			std::cout << "Hello in the search" << std::endl;
		else
			std::cout << "Please choose between the 3 commands" << std::endl;
	}
	return (0);
}