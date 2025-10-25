#include "array.h"
#include <cassert>
#include <sstream>

void runTests() {
    std::cout << "Running tests...\n";
    
    // Test Point
    Point p1(1, 2), p2(1, 2), p3(3, 4);
    assert(p1 == p2);
    assert(!(p1 == p3));
    
    // Test Triangle
    Triangle tri1({Point(0,0), Point(1,0), Point(0,1)});
    Triangle tri2({Point(0,0), Point(1,0), Point(0,1)});
    Triangle tri3({Point(0,0), Point(2,0), Point(0,2)});
    
    assert(tri1 == tri2);
    assert(!(tri1 == tri3));
    
    Point center = tri1.geometricCenter();
    assert(std::abs(center.x - 0.333) < 0.01);
    assert(std::abs(center.y - 0.333) < 0.01);
    
    double area = tri1.area();
    assert(std::abs(area - 0.5) < 0.001);
    
    // Test Hexagon
    Hexagon hex1({
        Point(0,0), Point(1,0), Point(1.5,0.866), 
        Point(1,1.732), Point(0,1.732), Point(-0.5,0.866)
    });
    
    double hexArea = hex1.area();
    assert(std::abs(hexArea - 2.598) < 0.01);
    
    // Test Octagon
    Octagon oct1({
        Point(0,1), Point(0.707,0.707), Point(1,0), Point(0.707,-0.707),
        Point(0,-1), Point(-0.707,-0.707), Point(-1,0), Point(-0.707,0.707)
    });
    
    double octArea = oct1.area();
    assert(std::abs(octArea - 2.828) < 0.01);
    
    // Test FigureArray
    FigureArray arr;
    arr.addFigure(std::make_unique<Triangle>(std::vector<Point>{Point(0,0), Point(1,0), Point(0,1)}));
    arr.addFigure(std::make_unique<Hexagon>(std::vector<Point>{
        Point(0,0), Point(1,0), Point(1.5,0.866), 
        Point(1,1.732), Point(0,1.732), Point(-0.5,0.866)
    }));
    
    assert(arr.size() == 2);
    assert(std::abs(arr.totalArea() - (0.5 + 2.598)) < 0.1);
    
    arr.removeFigure(0);
    assert(arr.size() == 1);
    
    // Test stream operators
    std::stringstream ss;
    ss << "0 0 1 0 0 1";
    Triangle tri4;
    ss >> tri4;
    assert(tri4 == tri1);
    
    std::cout << "All tests passed!\n";
}

// Для запуска тестов отдельно
#ifdef STANDALONE_TESTS
int main() {
    runTests();
    return 0;
}
#endif