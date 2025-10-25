#include "triangle.h"

Triangle::Triangle(const std::vector<Point>& verts) : vertices(verts) {
    if (verts.size() != 3) {
        throw std::invalid_argument("Triangle must have 3 vertices");
    }
}

Triangle::Triangle(const Triangle& other) : vertices(other.vertices) {}

Triangle& Triangle::operator=(const Triangle& other) {
    if (this != &other) {
        vertices = other.vertices;
    }
    return *this;
}

Triangle::Triangle(Triangle&& other) noexcept : vertices(std::move(other.vertices)) {}

Triangle& Triangle::operator=(Triangle&& other) noexcept {
    if (this != &other) {
        vertices = std::move(other.vertices);
    }
    return *this;
}

Point Triangle::geometricCenter() const {
    double sumX = 0, sumY = 0;
    for (const auto& vertex : vertices) {
        sumX += vertex.x;
        sumY += vertex.y;
    }
    return Point(sumX / 3, sumY / 3);
}

double Triangle::area() const {
    const Point& a = vertices[0];
    const Point& b = vertices[1];
    const Point& c = vertices[2];
    
    return std::abs((a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y)) / 2.0);
}

void Triangle::printVertices(std::ostream& os) const {
    os << "Triangle vertices: ";
    for (size_t i = 0; i < vertices.size(); ++i) {
        os << "(" << vertices[i].x << ", " << vertices[i].y << ")";
        if (i != vertices.size() - 1) os << ", ";
    }
}

void Triangle::readFromStream(std::istream& is) {
    vertices.clear();
    for (int i = 0; i < 3; ++i) {
        double x, y;
        if (!(is >> x >> y)) {
            throw std::runtime_error("Failed to read triangle vertex");
        }
        vertices.emplace_back(x, y);
    }
}

bool Triangle::operator==(const Figure& other) const {
    const Triangle* tri = dynamic_cast<const Triangle*>(&other);
    if (!tri) return false;
    
    if (vertices.size() != tri->vertices.size()) return false;
    
    for (size_t i = 0; i < vertices.size(); ++i) {
        if (!(vertices[i] == tri->vertices[i])) {
            return false;
        }
    }
    return true;
}