/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-brah <eel-brah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 18:30:16 by eel-brah          #+#    #+#             */
/*   Updated: 2024/08/05 18:30:16 by eel-brah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

void run_tests()
{
    Point A (0, 0);
    Point B (5, 0);
    Point C (0, 5);

	struct TestCase {
        Point P;
        bool expected;
        std::string description;
    };

	TestCase tests[] = {
		{Point(2, 2), true, "Inside the triangle"},
		{Point(5, 0), false, "On vertex B"},
		{Point(2.5f, 2.5f), false, "Outside the triangle"},
		{Point(2.5f, 1.25f), true, "Inside the triangle"},
		{Point(0, 0), false, "On vertex A"},
		{Point(0, 5), false, "On vertex C"},
		{Point(2.5f, 0), false, "On edge AB"},
		{Point(0, 2.5f), false, "On edge AC"},
		{Point(3, 2), false, "Inside the triangle near edge BC"},
		{Point(-1, -1), false, "Far outside the triangle"},
		{Point(1, 1), true, "Inside the triangle"},
		{Point(2, 1), true, "Inside the triangle"},
		{Point(1, 2), true, "Inside the triangle"},
		{Point(2, 2), true, "Inside the triangle"},
		{Point(3, 1), true, "Inside the triangle"},
		{Point(1, 3), true, "Inside the triangle"},
		{Point(3, 3), false, "Outside the triangle"},
		{Point(2, 3), false, "On edge BC"},
		{Point(1, 1.5f), true, "Inside the triangle"},
		{Point(2.5f, 2.5f), false, "On edge BC"},
    };

    for (int i = 0; i < 20; i++)
	{
        bool result = bsp(A, B, C, tests[i].P);
        std::cout << "Test " << i+1 << ": "<< tests[i].description << ": "
                  << (result == tests[i].expected ? "\033[0;32mPASSED\033[0m" : "\033[0;31mFAILED\033[0m")
                  << std::endl;
    }
}

int main()
{
    run_tests();
    return 0;
}