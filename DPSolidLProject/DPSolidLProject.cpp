// DPSolidLProject.cpp 
//
#include <iostream>

using namespace std;


class Rectangle
{
protected:
    int width;
    int height;
public:
    virtual void Width(int width) { this->width = width; }
    virtual void Height(int height) { this->height = height; }

    Rectangle(int width = 0, int height = 0) : width{ width }, height{ height } {}

    int GetArea() { return width * height; }
};

class Square : public Rectangle
{
    void Width(int width) override
    {  
        this->height = this->width = width;
    }

    void Height(int height) override
    {
        this->width = this->height = height;
    }
};



void TestRectangle(Rectangle* rectangle)
{
    rectangle->Width(10);
    rectangle->Height(5);

    if (typeid(*rectangle) == typeid(Rectangle))
    {
        if (rectangle->GetArea() != 50)
            throw new exception("error in method GetArea");
    }
    else
        if (rectangle->GetArea() != 25)
            throw new exception("error in method GetArea");
}

#include <iostream>

int main()
{
    Rectangle rectangle;
    Square square;
    try
    {
        TestRectangle(&square);
        cout << "test is good\n";
    }
    catch (exception* e)
    {
        cout << e->what() << "\n";
    }
}
