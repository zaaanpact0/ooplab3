#ifndef OCTAGON_H
#define OCTAGON_H

#include "figure.h"

class Octagon : public Figure {
private:
    std::vector<Point> vertices;
    
public:
    Octagon() = default;
    Octagon(const std::vector<Point>& verts);
    Octagon(const Octagon& other);
    Octagon& operator=(const Octagon& other);
    Octagon(Octagon&& other) noexcept;
    Octagon& operator=(Octagon&& other) noexcept;
    
    Point geometricCenter() const override;
    double area() const override;
    void printVertices(std::ostream& os) const override;
    void readFromStream(std::istream& is) override;
    bool operator==(const Figure& other) const override;
};

#endif