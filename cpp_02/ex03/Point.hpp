/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-brah <eel-brah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 18:30:22 by eel-brah          #+#    #+#             */
/*   Updated: 2024/08/05 18:30:22 by eel-brah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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