/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukdid <aboukdid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:54:44 by aboukdid          #+#    #+#             */
/*   Updated: 2024/10/08 17:25:37 by aboukdid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

#include <iostream>

int main()
{
	Point	a(Fixed(1), Fixed(2));
	Point	b(Fixed(1), Fixed(4));
	Point	c(Fixed(2), Fixed(3));
	Point	p(Fixed(6), Fixed(6));

	if (bsp(a, b, c, p))
		std::cout << "The point is inside the triangle " << std::endl;
	else
		std::cout << "The point is outside the triangle" << std::endl;
}