/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukdid <aboukdid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 21:47:01 by aboukdid          #+#    #+#             */
/*   Updated: 2024/08/08 22:12:10 by aboukdid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Sed
{
	private:
		std::string s1;
		std::string s2;
	public:
		Sed();
		~Sed();
		std::string get_s1();
		std::string get_s2();
};

Sed::Sed()
{
	return ;
}
Sed::~Sed()
{
	std::cout << "Good Bye" << std::endl;
}
std::string	Sed::get_s1()
{
	return (s1);
}

std::string	Sed::get_s2()
{
	return (s2);
}

int main(int argc, char **argv)
{
	if (argc != 4)
		std::cout << "give me a file and two string to replace " << std::endl;
	else
	{
		std::ifstream
		// insert
		// erase
	}
}