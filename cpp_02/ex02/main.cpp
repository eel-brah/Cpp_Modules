#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	Fixed d(5);
	Fixed f(5.7f);
	std::cout << d << std::endl;
	std::cout << ++f << std::endl;
	std::cout << f + d << std::endl;
	std::cout << f-d << std::endl;
	std::cout << f*d << std::endl;
	std::cout << f/d << std::endl;
	Fixed r =f/d;
	std::cout << ++r << std::endl;
	return 0;
}