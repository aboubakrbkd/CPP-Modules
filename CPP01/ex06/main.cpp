/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukdid <aboukdid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 14:12:22 by aboukdid          #+#    #+#             */
/*   Updated: 2024/10/05 20:03:36 by aboukdid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl harl;
	std::string level;
	if (argc != 2)
	{
		std::cout << "The input is ./HarlFilter [COMMAND]" << std::endl;
		return (1);
	}
	level = argv[1];
	int levels = getlevel(level);
	switch (levels)
	{
		case 0:
			harl.complain("DEBUG");
		case 1:
			harl.complain("INFO");
		case 2:
			harl.complain("WARNING");
		case 3:
			harl.complain("ERROR");
			break ;
		default:
			harl.complain("HAHA");
	}
}