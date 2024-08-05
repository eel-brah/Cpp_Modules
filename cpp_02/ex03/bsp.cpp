/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-brah <eel-brah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 18:30:09 by eel-brah          #+#    #+#             */
/*   Updated: 2024/08/05 18:30:09 by eel-brah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// The sign of areas technique 
// is a method involves calculating the signed areas of triangles 
// formed by the point in question and the vertices of the original triangle.

// Given a triangle with vertices a(x1,y1), b(x2,y2), and c(x3,y3), 
// and a point point(px,py), the signed area of a triangle 
// formed by any three points (x1,y1), (x2,y2), and (px,py) 
// can be computed as:
// Area = 1/2 [(x1⋅(y2−py)+x2⋅(py−y1)+px⋅(y1−y2))]

Fixed abs(Fixed x)
{
	return (x < 0) ? x * -1 : x;
}

Fixed signed_areas(Point a, Point b, Point c)
{
	return (a.get_x() * (b.get_y() - c.get_y()) + b.get_x() * (c.get_y() - a.get_y()) + c.get_x() * (a.get_y() - b.get_y())) / 2.0f;
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed triangle_area = abs(signed_areas(a, b, c));
	Fixed area_1 = abs(signed_areas(point, a, b));
	Fixed area_2 = abs(signed_areas(point, b, c));
	Fixed area_3 = abs(signed_areas(point, c, a));

	// std::cout << area_1 << "  " << area_2 << "  " << area_3 << " == " << triangle_area << " == " << area_1 + area_2 + area_3 <<  std::endl;

	bool A = !(area_1 == Fixed(0) || area_2 == Fixed(0) || area_3 == Fixed(0));
	bool B = (area_1 + area_2 + area_3) == triangle_area;

	return (A && B);
}