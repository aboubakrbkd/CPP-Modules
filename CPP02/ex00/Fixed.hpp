#ifndef FIXED_HPP
#define FIXED_HPP


#include <iostream>

// Fixed::bits
class Fixed
{
    private:
        int fixed_store;
        static const int bits;
    public:
        Fixed();
        Fixed(Fixed &a);
        ~Fixed();
        Fixed &operator=(const Fixed &a);
        int getRawBits(void) const;
        void setRawBits(int const raw);
};

#endif