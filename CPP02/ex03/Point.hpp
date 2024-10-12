/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukdid <aboukdid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:56:08 by aboukdid          #+#    #+#             */
/*   Updated: 2024/10/08 16:26:40 by aboukdid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:
		const Fixed x;
		const Fixed y;
	public:
		Point();
		Point(const Fixed x, const Fixed y);
		Point(const Point& obj);
		Point& operator=(const Point& obj);
		~Point();
		Fixed getx() const;
		Fixed gety() const;
};



bool bsp( Point const a, Point const b, Point const c, Point const point);
#endif
