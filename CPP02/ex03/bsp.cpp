/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukdid <aboukdid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:56:02 by aboukdid          #+#    #+#             */
/*   Updated: 2024/10/08 17:38:29 by aboukdid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed absolute(Fixed &result)
{
	if (result < 0)
		return (result * -1);
	return (result);
}

Fixed area_of_triangle(Point const &a, Point const &b, Point const &c)
{
	Fixed result;
	Fixed floa(0.5f);
	result = (a.getx().toFloat() * (b.gety().toFloat() - c.gety().toFloat())
		   +  b.getx().toFloat() * (c.gety().toFloat() - a.gety().toFloat())
		   +  c.getx().toFloat() * (a.gety().toFloat() - b.gety().toFloat()));
	return (floa * absolute(result));
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed abc = area_of_triangle(a, b, c);
	Fixed pab = area_of_triangle(point, a, b);
	Fixed pbc = area_of_triangle(point, b, c);
	Fixed pca = area_of_triangle(point, c, a);
	Fixed result = pab.toFloat() + pbc.toFloat() + pca.toFloat();
	return (abc.toFloat() == result.toFloat());
}
