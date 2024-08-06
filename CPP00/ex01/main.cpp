/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukdid <aboukdid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 20:24:44 by aboukdid          #+#    #+#             */
/*   Updated: 2024/08/06 22:23:33 by aboukdid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <string>

int main()
{
	PhoneBook Person;
	Contact user;
	std::string str;
	while (1)
	{
		std::cout <<"Choose between ADD, SEARCH, EXIT: ";
		std::getline(std::cin, str);
		if (str == "EXIT" || std::cin.eof())
		{
			std::cout << "\nGood bye " << std::endl;
			break ;
		}
		else if (str == "ADD")
			Person.add_to_the_contact(user);
		else if (str == "SEARCH")
			Person.searchcontact();
		else
			std::cout << "Please choose between the 3 commands" << std::endl;
	}
	return (0);
}