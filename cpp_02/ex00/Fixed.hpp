#ifndef FIXED_H_
#define FIXED_H_

#include <iostream>

class Fixed
{
	private:
		int					nb;
		static const int	fractional = 8;
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);

		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif