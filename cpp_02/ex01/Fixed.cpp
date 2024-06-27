#include "Fixed.hpp"

Fixed::Fixed() : nb(0)
{
	std::cout << "Default constructor called\n";
}
Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

Fixed::Fixed(const int i) : nb(i<<fractional)
{
	std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called\n";
	nb = roundf(f * (1 << fractional));
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called\n";
	*this = other;
}

float Fixed::toFloat( void ) const
{
	return static_cast<float>(nb) / (1 << fractional);
}

// fix this it
int Fixed::toInt( void ) const
{
	return static_cast<unsigned int>(nb) >> fractional;
}


Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &other)
		nb = other.getRawBits();
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return os;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return nb;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called\n";
	nb = raw;
}
