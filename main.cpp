#include "array.h"
#include <iostream>
#include <string>

using namespace std;

int main() 
{
    FigureArray arr;
    
    cout << "=== Figure Program ===" << endl;
    cout << "Types: triangle (t), hexagon (h), octagon (o)" << endl;
    cout << "Commands: quit (q), delete (d), print (p), area (a)" << endl;
    cout << endl;
    
    char cmd;
    bool running = true;
    
    while (running) 
    {
        cout << "Enter command: ";
        cin >> cmd;
        
        if (cmd == 'q') 
        {
            running = false;
            cout << "Exiting..." << endl;
        }
        else if (cmd == 'p') 
        {
            if (arr.size() == 0) 
            {
                cout << "No figures in array" << endl;
            }
            else 
            {
                arr.printAllInfo();
            }
        }
        else if (cmd == 'a') 
        {
            double total = arr.totalArea();
            cout << "Total area of all figures: " << total << endl;
        }
        else if (cmd == 'd') 
        {
            if (arr.size() == 0) 
            {
                cout << "Array is empty" << endl;
                continue;
            }
            
            int idx;
            cout << "Enter index to delete (0-" << arr.size()-1 << "): ";
            cin >> idx;
            
            if (idx >= 0 && static_cast<size_t>(idx) < arr.size()) 
            {
                arr.removeFigure(idx);
                cout << "Figure " << idx << " deleted" << endl;
            }
            else 
            {
                cout << "Invalid index!" << endl;
            }
        }
        else if (cmd == 't' || cmd == 'h' || cmd == 'o') 
        {
            std::unique_ptr<Figure> newFig;
            
            if (cmd == 't') 
            {
                newFig = std::make_unique<Triangle>();
                cout << "Enter triangle vertices (3 points x y): ";
            }
            else if (cmd == 'h') 
            {
                newFig = std::make_unique<Hexagon>();
                cout << "Enter hexagon vertices (6 points x y): ";
            }
            else if (cmd == 'o') 
            {
                newFig = std::make_unique<Octagon>();
                cout << "Enter octagon vertices (8 points x y): ";
            }
            
            try 
            {
                cin >> *newFig;
                arr.addFigure(std::move(newFig));
                cout << "Figure added! Total figures: " << arr.size() << endl;
            }
            catch (const exception& e) 
            {
                cout << "Error reading figure: " << e.what() << endl;
                cin.clear();
                string temp;
                getline(cin, temp);
            }
        }
        else 
        {
            cout << "Unknown command: " << cmd << endl;
            cout << "Available: t,h,o,p,a,d,q" << endl;
        }
        
        cout << endl;
    }
    
    return 0;
}