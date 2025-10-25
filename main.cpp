#include "array.h"

int main() {
    FigureArray array;
    
    std::cout << "Figure input program\n";
    std::cout << "Available figures: Triangle (3 vertices), Hexagon (6 vertices), Octagon (8 vertices)\n";
    std::cout << "Enter 'q' to quit\n\n";
    
    while (true) {
        std::cout << "Choose figure type (t=triangle, h=hexagon, o=octagon, q=quit, d=delete, p=print, a=total area): ";
        char choice;
        std::cin >> choice;
        
        if (choice == 'q') {
            break;
        } else if (choice == 'p') {
            array.printAllInfo();
        } else if (choice == 'a') {
            std::cout << "Total area: " << array.totalArea() << "\n\n";
        } else if (choice == 'd') {
            int index;
            std::cout << "Enter index to delete: ";
            std::cin >> index;
            array.removeFigure(index);
            std::cout << "Figure deleted\n\n";
        } else if (choice == 't' || choice == 'h' || choice == 'o') {
            std::unique_ptr<Figure> fig;
            
            if (choice == 't') {
                fig = std::make_unique<Triangle>();
                std::cout << "Enter 3 vertices (x y for each): ";
            } else if (choice == 'h') {
                fig = std::make_unique<Hexagon>();
                std::cout << "Enter 6 vertices (x y for each): ";
            } else if (choice == 'o') {
                fig = std::make_unique<Octagon>();
                std::cout << "Enter 8 vertices (x y for each): ";
            }
            
            try {
                std::cin >> *fig;
                array.addFigure(std::move(fig));
                std::cout << "Figure added successfully!\n\n";
            } catch (const std::exception& e) {
                std::cout << "Error: " << e.what() << "\n\n";
                std::cin.clear();
                std::cin.ignore(10000, '\n');
            }
        } else {
            std::cout << "Invalid choice\n\n";
        }
    }
    
    return 0;
}