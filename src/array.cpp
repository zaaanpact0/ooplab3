#include "array.h"

void FigureArray::addFigure(std::unique_ptr<Figure> fig) {
    figures.push_back(std::move(fig));
}

void FigureArray::removeFigure(int index) {
    if (index >= 0 && static_cast<size_t>(index) < figures.size()) {
        figures.erase(figures.begin() + index);
    }
}

void FigureArray::printAllInfo() const {
    for (size_t i = 0; i < figures.size(); ++i) {
        std::cout << "Figure " << i << ":\n";
        std::cout << "  " << *figures[i] << "\n";
        
        Point center = figures[i]->geometricCenter();
        std::cout << "  Geometric center: (" << center.x << ", " << center.y << ")\n";
        
        double area = figures[i]->area();
        std::cout << "  Area: " << area << "\n\n";
    }
}

double FigureArray::totalArea() const {
    double total = 0;
    for (const auto& fig : figures) {
        total += fig->area();
    }
    return total;
}

size_t FigureArray::size() const {
    return figures.size();
}