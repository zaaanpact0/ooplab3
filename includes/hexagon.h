#ifndef HEXAGON_H
#define HEXAGON_H

#include "figure.h"

class Hexagon : public Figure {
private:
    std::vector<Point> vertices;
    
public:
    Hexagon() = default;
    Hexagon(const std::vector<Point>& verts);
    Hexagon(const Hexagon& other);
    Hexagon& operator=(const Hexagon& other);
    Hexagon(Hexagon&& other) noexcept;
    Hexagon& operator=(Hexagon&& other) noexcept;
    
    Point geometricCenter() const override;
    double area() const override;
    void printVertices(std::ostream& os) const override;
    void readFromStream(std::istream& is) override;
    bool operator==(const Figure& other) const override;
};

#endif