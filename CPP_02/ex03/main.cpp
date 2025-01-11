/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:38:56 by aaghla            #+#    #+#             */
/*   Updated: 2025/01/11 21:57:45 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main(void)
{
    // Define triangle vertices
    Point a(0.0f, 0.0f);
    Point b(10.0f, 0.0f);
    Point c(5.0f, 10.0f);

    // Test cases
    Point insidePoint(5.0f, 5.0f);   // Inside the triangle
    Point edgePoint1(5.0f, 0.0f);   // On edge AB
    Point edgePoint2(7.5f, 5.0f);   // On edge BC
    Point edgePoint3(2.5f, 5.0f);   // On edge CA
    Point vertexPoint(0.0f, 0.0f);  // On vertex A
    Point outsidePoint(10.0f, 10.0f); // Outside the triangle
    Point collinearPoint(15.0f, 15.0f); // Collinear but outside
    Point   inside(5.0f, 3.0f);

    // Run tests and display results
    std::cout << "Point (5, 5) inside triangle: " << bsp(a, b, c, insidePoint) << std::endl;
    std::cout << "Point (5, 0) on edge AB: " << bsp(a, b, c, edgePoint1) << std::endl;
    std::cout << "Point (7.5, 5) on edge BC: " << bsp(a, b, c, edgePoint2) << std::endl;
    std::cout << "Point (2.5, 5) on edge CA: " << bsp(a, b, c, edgePoint3) << std::endl;
    std::cout << "Point (0, 0) on vertex A: " << bsp(a, b, c, vertexPoint) << std::endl;
    std::cout << "Point (10, 10) outside triangle: " << bsp(a, b, c, outsidePoint) << std::endl;
    std::cout << "Point (15, 15) collinear but outside: " << bsp(a, b, c, collinearPoint) << std::endl;
    std::cout << "inside: " << bsp(a, b, c, inside) << std::endl;

    return 0;
}