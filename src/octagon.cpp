#include "octagon.h"

Octagon::Octagon(const std::vector<Point>& verts) : vertices(verts) {
    if (verts.size() != 8) {
        throw std::invalid_argument("Octagon must have 8 vertices");
    }
}

Octagon::Octagon(const Octagon& other) : vertices(other.vertices) {}

Octagon& Octagon::operator=(const Octagon& other) {
    if (this != &other) {
        vertices = other.vertices;
    }
    return *this;
}

Octagon::Octagon(Octagon&& other) noexcept : vertices(std::move(other.vertices)) {}

Octagon& Octagon::operator=(Octagon&& other) noexcept {
    if (this != &other) {
        vertices = std::move(other.vertices);
    }
    return *this;
}

Point Octagon::geometricCenter() const {
    double sumX = 0, sumY = 0;
    for (const auto& vertex : vertices) {
        sumX += vertex.x;
        sumY += vertex.y;
    }
    return Point(sumX / 8, sumY / 8);
}

double Octagon::area() const {
    double area = 0;
    for (int i = 0; i < 8; ++i) {
        int j = (i + 1) % 8;
        area += vertices[i].x * vertices[j].y - vertices[j].x * vertices[i].y;
    }
    return std::abs(area) / 2.0;
}

void Octagon::printVertices(std::ostream& os) const {
    os << "Octagon vertices: ";
    for (size_t i = 0; i < vertices.size(); ++i) {
        os << "(" << vertices[i].x << ", " << vertices[i].y << ")";
        if (i != vertices.size() - 1) os << ", ";
    }
}

void Octagon::readFromStream(std::istream& is) {
    vertices.clear();
    for (int i = 0; i < 8; ++i) {
        double x, y;
        if (!(is >> x >> y)) {
            throw std::runtime_error("Failed to read octagon vertex");
        }
        vertices.emplace_back(x, y);
    }
}

bool Octagon::operator==(const Figure& other) const {
    const Octagon* oct = dynamic_cast<const Octagon*>(&other);
    if (!oct) return false;
    
    if (vertices.size() != oct->vertices.size()) return false;
    
    for (size_t i = 0; i < vertices.size(); ++i) {
        if (!(vertices[i] == oct->vertices[i])) {
            return false;
        }
    }
    return true;
}