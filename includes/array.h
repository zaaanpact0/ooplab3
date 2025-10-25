#ifndef ARRAY_H
#define ARRAY_H

#include "figure.h"
#include "triangle.h"
#include "hexagon.h"
#include "octagon.h"

class FigureArray {
private:
    std::vector<std::unique_ptr<Figure>> figures;
    
public:
    void addFigure(std::unique_ptr<Figure> fig);
    void removeFigure(int index);
    void printAllInfo() const;
    double totalArea() const;
    size_t size() const;
    const std::vector<std::unique_ptr<Figure>>& getFigures() const { return figures; }
};

#endif