#include "Fixed.hpp"
Fixed::Fixed() : fixed_store(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed &a) : fixed_store(a.fixed_store)
{
    std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &a)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &a)
        fixed_store = a.fixed_store;
    return *this;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return fixed_store;
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    fixed_store = raw;
}