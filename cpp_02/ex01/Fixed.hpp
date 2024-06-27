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
		Fixed();
		~Fixed();
		Fixed(const int i);
		Fixed(const float f);
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);	

		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat( void ) const;
		int toInt( void ) const;
};
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif