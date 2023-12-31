#include <iostream>

using namespace std;

class Shape
{
public:
    Shape()
    {
        cout << "Constructor Shape"
            << endl;
    }

    virtual ~Shape() {
        cout << "Destructor Shape" << endl;
    }
    virtual void draw()
    {
        cout << "Draw Shape" << endl;
    }
};

class Circle : public Shape
{
public:
    Circle()
    {
        cout << "Constructor Circle"
            << endl;
    }

    ~Circle() {
        cout << "Destructor Circle" << endl;
    }

    void draw()
    {
        Shape::draw();
        cout << "Draw Circle" << endl;
    }
};

class Polygon : public Shape
{
public:
    Polygon()
    {
        cout << "Constructor Polygon"
            << endl;
    }

    ~Polygon() {
        cout << "Destructor Polygon"
            << endl;
    }
    void draw()
    {
        Shape::draw();
        cout << "Draw Polygon" << endl;
    }
};

class Triangle : public Polygon
{
public:
    Triangle()
    {
        cout << "Constructor Triangle"
            << endl;
    }

    ~Triangle() {
        cout << "Destructor Triangle"
            << endl;
    }
    void draw()
    {
        Polygon::draw();
        cout << "Draw Triangle" << endl;
    }
};





int main()
{
    Shape* shapes[] = { new Circle(),
                        new Triangle() };
    shapes[0]->draw();
    shapes[1]->draw();
    delete shapes[0];
    delete shapes[1];
    return 0;
}
