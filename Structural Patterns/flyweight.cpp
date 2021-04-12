#include <iostream>
#include <unordered_map>

using namespace std;

// abstract class
class Character
{
protected:
    char charSymbol;
    int fontSize;
    int color;

public:
    virtual void display(char symbol) = 0;
};

class A : public Character
{
public:
    A()
    {
        charSymbol = 'A';
        fontSize = 10;
    }
};