#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Shape
{
public:
    virtual Shape *clone() = 0;
};

class Circle : public Shape
{
private:
    int radius, x, y;

public:
    Circle(int radius, int x, int y) : radius(radius), x(x), y(y) {}
    Shape *clone() { return new Circle(*this); }
};

class Square : public Shape
{
private:
    int x, y, width, height;

public:
    Square(int x, int y, int width, int height) : x(x), y(y), width(width), height(height) {}
    Shape *clone() { return new Square(*this); }
};

int main(int argc, char const *argv[])
{
    vector<Shape *> shapes;
    vector<Shape *> shapesClone;
    shapes.push_back(new Circle(2, 3, 4));
    shapes.push_back(new Square(1, 2, 3, 4));
    cout << shapes.size() << " reg" << endl;
    cout << shapesClone.size() << " clone" << endl;

    for_each(shapes.begin(), shapes.end(), [&shapesClone](Shape *shape) {
        shapesClone.push_back(shape->clone());
    });

    cout << shapes.size() << " reg" << endl;
    cout << shapesClone.size() << " clone" << endl;
    return 0;
}
