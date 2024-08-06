/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-brah <eel-brah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 18:29:54 by eel-brah          #+#    #+#             */
/*   Updated: 2024/08/05 18:29:54 by eel-brah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Constructors & Destructor
Fixed::Fixed() : nb(0)
{
	// std::cout << "Default constructor called\n";
}
Fixed::~Fixed()
{
	// std::cout << "Destructor called\n";
}

Fixed::Fixed(const int i) : nb(i<<fractional)
{
	// std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float f) : nb(roundf(f * (1 << fractional)))
{
	// std::cout << "Float constructor called\n";
}

Fixed::Fixed(const Fixed& other)
{
	// std::cout << "Copy constructor called\n";
	*this = other;
}

// Convertion
float Fixed::toFloat( void ) const
{
	return static_cast<float>(nb) / (1 << fractional);
}

int Fixed::toInt( void ) const
{
	return static_cast<unsigned int>(nb) >> fractional;
}

// Assignment
Fixed& Fixed::operator=(const Fixed& other)
{
	// std::cout << "Copy assignment operator called\n";
	if (this != &other)
		nb = other.getRawBits();
	return *this;
}

// Insertion
std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return os;
}

// Getter & Setter
int Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called\n";
	return nb;
}

void Fixed::setRawBits(int const raw)
{
	// std::cout << "setRawBits member function called\n";
	nb = raw;
}

// Comparison
bool Fixed::operator>(const Fixed &fixed) const
{
    return this->getRawBits() > fixed.getRawBits();
}

bool Fixed::operator<(const Fixed &fixed) const
{
    return this->getRawBits() < fixed.getRawBits();
}

bool Fixed::operator>=(const Fixed &fixed) const
{
    return this->getRawBits() >= fixed.getRawBits();
}

bool Fixed::operator<=(const Fixed &fixed) const
{
    return this->getRawBits() <= fixed.getRawBits();
}

bool Fixed::operator==(const Fixed &fixed) const
{
    return this->getRawBits() == fixed.getRawBits();
}

bool Fixed::operator!=(const Fixed &fixed) const
{
    return this->getRawBits() != fixed.getRawBits();
}

// Arithmetic
Fixed Fixed::operator+(const Fixed &fixed)
{
	Fixed tmp;
	tmp.setRawBits(nb + fixed.getRawBits());
	return tmp;
}

Fixed Fixed::operator-(const Fixed &fixed)
{
	Fixed tmp;
	tmp.setRawBits(nb - fixed.getRawBits());
	return tmp;
}

Fixed Fixed::operator*(const Fixed &fixed)
{
	Fixed tmp;
	tmp.setRawBits((static_cast<unsigned long>(nb) * fixed.getRawBits()) >> fractional);
	return tmp;	
}

Fixed Fixed::operator/(const Fixed &fixed)
{
	Fixed tmp;
	tmp.setRawBits((nb << fractional) / fixed.getRawBits());
	return tmp;	
}

// Increment/Decrement
Fixed Fixed::operator++()
{
	this->nb++;
    return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed old(*this);
	operator++();
	return old;
}

Fixed Fixed::operator--()
{
	this->nb++;
    return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed old(*this);
	operator--();
	return old;
}

// Min & Max
Fixed& Fixed::min(Fixed &x, Fixed &y)
{
	return (x <= y) ? x : y;
}
const Fixed& Fixed::min(const Fixed &x, const Fixed &y)
{
	return (x <= y) ? x : y;
}
Fixed& Fixed::max(Fixed &x, Fixed &y)
{
	return (x >= y) ? x : y;
}
const Fixed& Fixed::max(const Fixed &x, const Fixed &y)
{
	return (x >= y) ? x : y;
}