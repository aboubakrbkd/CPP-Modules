/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukdid <aboukdid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:56:06 by aboukdid          #+#    #+#             */
/*   Updated: 2024/10/08 16:27:03 by aboukdid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(const Fixed x, const Fixed y): x(x), y(y) {}

Point::Point(const Point& obj) : x(obj.x) , y(obj.y)
{
	*this = obj;
}

Point& Point::operator=(const Point& obj)
{
	(void) obj;
	return *this;
}

Point::~Point() {}

Fixed Point::getx() const 
{
	return x;
}

Fixed Point::gety() const 
{
	return y;
}