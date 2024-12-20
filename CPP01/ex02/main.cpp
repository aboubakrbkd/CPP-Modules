/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukdid <aboukdid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 18:13:22 by aboukdid          #+#    #+#             */
/*   Updated: 2024/10/05 20:29:26 by aboukdid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout <<"The memory address of the string variable: " << &str << std::endl;
    std::cout <<"The memory adress held by stringPTR: " << stringPTR << std::endl;
    std::cout <<"The memory adress held by stringREF: " << &stringREF << std::endl;

    std::cout << "-----------------------------------------" << std::endl;

    std::cout <<"The value of the string variable: " << str << std::endl;
    std::cout <<"The value pointer by stringPTR: " << *stringPTR << std::endl;
    std::cout <<"The value pointer by stringREF: " << stringREF << std::endl;
}