#include <iostream>
using namespace std;

class GUIItem
{
public:
    virtual void paint() = 0;
};

class Canvas : public GUIItem
{
public:
    void paint()
    {
        cout << "Painting Canvas!" << endl;
    }
};
class TextView : public GUIItem
{
public:
    void paint()
    {
        cout << "Painting TextView!" << endl;
    }
};
class ListView : public GUIItem
{
public:
    void paint()
    {
        cout << "Painting ListView!" << endl;
    }
};
class Decorator : public GUIItem
{
protected:
    GUIItem *item;

public:
    Decorator(GUIItem *item) : item(item) {}
    void paint()
    {
        item->paint();
    }
};
class Scrollbars : public Decorator
{
protected:
    GUIItem *item;

public:
    using Decorator::Decorator;
    void paint()
    {
        Decorator::paint();
        cout << "adding scrollbars!" << endl;
    }
};
class Title : public Decorator
{
protected:
    GUIItem *item;

public:
    using Decorator::Decorator;
    void paint()
    {
        Decorator::paint();
        cout << "adding Title!" << endl;
    }
};
class Border : public Decorator
{
protected:
    GUIItem *item;

public:
    using Decorator::Decorator;
    void paint()
    {
        Decorator::paint();
        cout << "adding Border!" << endl;
    }
};

int main(int argc, char const *argv[])
{
    GUIItem *g1 = new Title(new Title(new ListView()));
    g1->paint();
    delete g1;

    return 0;
}
