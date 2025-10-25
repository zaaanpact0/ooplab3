#include "hexagon.h"

Hexagon::Hexagon(const std::vector<Point>& verts) : vertices(verts) {
    if (verts.size() != 6) {
        throw std::invalid_argument("Hexagon must have 6 vertices");
    }
}

Hexagon::Hexagon(const Hexagon& other) : vertices(other.vertices) {}

Hexagon& Hexagon::operator=(const Hexagon& other) {
    if (this != &other) {
        vertices = other.vertices;
    }
    return *this;
}

Hexagon::Hexagon(Hexagon&& other) noexcept : vertices(std::move(other.vertices)) {}

Hexagon& Hexagon::operator=(Hexagon&& other) noexcept {
    if (this != &other) {
        vertices = std::move(other.vertices);
    }
    return *this;
}

Point Hexagon::geometricCenter() const {
    double sumX = 0, sumY = 0;
    for (const auto& vertex : vertices) {
        sumX += vertex.x;
        sumY += vertex.y;
    }
    return Point(sumX / 6, sumY / 6);
}

double Hexagon::area() const {
    double area = 0;
    for (int i = 0; i < 6; ++i) {
        int j = (i + 1) % 6;
        area += vertices[i].x * vertices[j].y - vertices[j].x * vertices[i].y;
    }
    return std::abs(area) / 2.0;
}

void Hexagon::printVertices(std::ostream& os) const {
    os << "Hexagon vertices: ";
    for (size_t i = 0; i < vertices.size(); ++i) {
        os << "(" << vertices[i].x << ", " << vertices[i].y << ")";
        if (i != vertices.size() - 1) os << ", ";
    }
}

void Hexagon::readFromStream(std::istream& is) {
    vertices.clear();
    for (int i = 0; i < 6; ++i) {
        double x, y;
        if (!(is >> x >> y)) {
            throw std::runtime_error("Failed to read hexagon vertex");
        }
        vertices.emplace_back(x, y);
    }
}

bool Hexagon::operator==(const Figure& other) const {
    const Hexagon* hex = dynamic_cast<const Hexagon*>(&other);
    if (!hex) return false;
    
    if (vertices.size() != hex->vertices.size()) return false;
    
    for (size_t i = 0; i < vertices.size(); ++i) {
        if (!(vertices[i] == hex->vertices[i])) {
            return false;
        }
    }
    return true;
}