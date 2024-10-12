/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukdid <aboukdid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 20:40:34 by aboukdid          #+#    #+#             */
/*   Updated: 2024/10/05 21:08:43 by aboukdid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

int main(int argc, char **argv)
{
	Sed sed;
	std::string str1;
	std::string str2;
	std::string first;
	if (argc != 4)
	{
		std::cout << "The input should be ./Sed First_file string1 string2" << std::endl;
		return(1);
	}
	else
	{
		first = argv[1];
		str1 = argv[2];
		str2 = argv[3];
		if (str1 == str2)
		{
			std::cout << "The both string are equals" << std::endl;
			return (1);
		}
		sed.set_first(argv[1]);
		sed.set_s1(str1);
		sed.set_s2(str2);
		sed.replace();
	}
}