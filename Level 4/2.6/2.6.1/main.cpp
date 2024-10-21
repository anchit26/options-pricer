#include <iostream>
#include "array.hpp"
#include "circle.hpp"
#include "line.hpp"
#include "point.hpp"

int main() {
    // Full namespace for Point
    AnchitAgarwal::CAD::Point p1(1, 2);
    AnchitAgarwal::CAD::Point p2(3, 4);
    std::cout << "Points: " << p1 << " and " << p2 << std::endl;

    // Using declaration for Line
    using AnchitAgarwal::CAD::Line;
    Line l1(p1, p2);
    std::cout << l1 << std::endl;

    // Using declaration for complete namespace
    using namespace AnchitAgarwal::Containers;
    Array arr(2);
    arr[0] = p1;
    arr[1] = p2;
    std::cout << arr << std::endl;

    // Using alias for circle
    namespace MyCAD = AnchitAgarwal::CAD;
    MyCAD::Circle circle(p1, 2);
    std::cout << circle << std::endl;

    return 0;
}