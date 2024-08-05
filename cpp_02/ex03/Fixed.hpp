/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-brah <eel-brah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 18:30:14 by eel-brah          #+#    #+#             */
/*   Updated: 2024/08/05 18:30:14 by eel-brah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H_
#define FIXED_H_

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int					nb;
		static const int	fractional = 8;
	public:
		// Constructors & Destructor
		Fixed();
		~Fixed();
		Fixed(const int i);
		Fixed(const float f);
		Fixed(const Fixed& other);

		// Convertion
		float toFloat( void ) const;
		int toInt( void ) const;

		// Assignment
		Fixed& operator=(const Fixed& other);

		// Getter & Setter
		int getRawBits(void) const;
		void setRawBits(int const raw);

		// Comparison
		bool operator>(const Fixed &fixed) const;
		bool operator<(const Fixed &fixed) const;
		bool operator>=(const Fixed &fixed) const;
		bool operator<=(const Fixed &fixed) const;
		bool operator==(const Fixed &fixed) const;
		bool operator!=(const Fixed &fixed) const;

		// Arithmetic
		Fixed operator+(const Fixed &fixed);
		Fixed operator-(const Fixed &fixed);
		Fixed operator*(const Fixed &fixed);
		Fixed operator/(const Fixed &fixed);

		// Increment/Decrement
		Fixed operator++();
		Fixed operator++(int);
		Fixed operator--();
		Fixed operator--(int);

		// Min & Max
		static Fixed& min(Fixed &x, Fixed &y);
		static const Fixed& min(const Fixed &x, const Fixed &y);
		static Fixed& max(Fixed &x, Fixed &y);
		static const Fixed& max(const Fixed &x, const Fixed &y);

};
// Insertion
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif