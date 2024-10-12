/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukdid <aboukdid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 16:12:27 by aboukdid          #+#    #+#             */
/*   Updated: 2024/10/08 16:14:05 by aboukdid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::bits = 8;

Fixed::Fixed()
{
	value = 0;
}

Fixed& Fixed::operator=(const Fixed& obj)
{
	if (this != &obj)
		value = obj.value;
	return *this;
}

Fixed::Fixed(const Fixed &obj)
{
	*this = obj;
}

Fixed::~Fixed() {}

int		Fixed::getRawBits() const
{
	return (value);
}

void	Fixed::setRawBits(int const raw)
{
	value = raw;
}

Fixed::Fixed(const int value)
{
	this->value = value << bits;
}

Fixed::Fixed(const float value)
{
	this->value = roundf(value * (1 << bits));
}

float	Fixed::toFloat() const
{
	return static_cast<float>(this->value) / (1 << bits);
}

int	Fixed::toInt() const
{
	return value >> bits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &obj)
{
	out << obj.toFloat();
	return out;
}

bool Fixed::operator>(const Fixed &obj) const
{
	return this->getRawBits() > obj.getRawBits();
}

bool Fixed::operator<(const Fixed &obj) const
{
	return this->getRawBits() < obj.getRawBits();
}

bool Fixed::operator>=(const Fixed &obj) const
{
	return this->getRawBits() >= obj.getRawBits();
}

bool Fixed::operator<=(const Fixed &obj) const
{
	return this->getRawBits() <= obj.getRawBits();
}

bool Fixed::operator==(const Fixed &obj) const
{
	return this->getRawBits() == obj.getRawBits();
}

bool Fixed::operator!=(const Fixed &obj) const
{
	return this->getRawBits() != obj.getRawBits();
}

Fixed Fixed::operator+(const Fixed &obj) const
{
	Fixed result;
	result.setRawBits(this->getRawBits() + obj.getRawBits());
	return result;
}

Fixed Fixed::operator-(const Fixed &obj) const
{
	Fixed result;
	result.setRawBits(this->getRawBits() - obj.getRawBits());
	return result;
}

Fixed Fixed::operator*(const Fixed &obj) const
{
	Fixed result;
	result.setRawBits(this->getRawBits() * obj.getRawBits() >> 8);
	return result;
}

Fixed Fixed::operator/(const Fixed &obj) const
{
	Fixed result;
	result.setRawBits((this->getRawBits() << 8 ) / obj.getRawBits());
	return result;
}

Fixed& Fixed::operator++()
{
	this->value = this->value + 1;
	return *this;
}

Fixed& Fixed::operator--()
{
	this->value = this->value - (1 << 8);
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed result = *this;
	this->setRawBits(this->getRawBits() - ( 1 << 8));
	return result;
}

Fixed Fixed::operator++(int)
{
	Fixed result = *this;
	this->setRawBits(this->getRawBits() + 1);
	return (result);
}

Fixed& Fixed::min(Fixed& obj1, Fixed& obj2)
{
	if (obj1 > obj2)
		return obj2;
	return obj1;
}

Fixed& Fixed::max(Fixed& obj1, Fixed& obj2)
{
	if (obj1 > obj2)
		return obj1;
	return obj2;
}

const Fixed& Fixed::min(const Fixed& obj1, const Fixed& obj2)
{
	if (obj1 > obj2)
		return obj2;
	return obj1;
}

const Fixed& Fixed::max(const Fixed& obj1, const Fixed& obj2)
{
	if (obj1 > obj2)
		return obj1;
	return obj2;
}