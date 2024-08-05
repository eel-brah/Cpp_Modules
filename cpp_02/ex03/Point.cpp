/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-brah <eel-brah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 18:30:20 by eel-brah          #+#    #+#             */
/*   Updated: 2024/08/05 18:30:20 by eel-brah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(): x(0), y(0) {}
Point::~Point() {}

Point::Point(const float x, const float y): x(x), y(y) {}
Point::Point(const Point& other): x(other.x), y(other.y) {}

Point& Point::operator=(const Point& other)
{
	if (this != &other)
	{
		(Fixed) this->x = other.get_x();
		(Fixed) this->y = other.get_y();
	}
	return *this;
}

Fixed Point::get_x() const
{
	return x;
}

Fixed Point::get_y() const
{
	return y;
}