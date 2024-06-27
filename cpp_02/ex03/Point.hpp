#ifndef POINT_H_
#define POINT_H_

#include "Fixed.hpp"

class Point
{
	private:
		const Fixed x;
		const Fixed y;
	public:
		Point();
		~Point();
		Point(const float x, const float y);
		Point(const Point& other);
		
		Point& operator=(const Point& other);

		Fixed get_x() const;
		Fixed get_y() const;
};

#endif