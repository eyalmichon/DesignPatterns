#include <iostream>
using namespace std;

class A
{
public:
    void doA()
    {
        cout << "testA" << endl;
    }
};

class B
{

public:
    void doB()
    {
        cout << "testB" << endl;
    }
};

class Facade
{
public:
    virtual void doShit() = 0;
};

class ActivateFacade : public Facade
{
private:
    A a;
    B b;

public:
    void doShit()
    {
        a.doA();
        b.doB();
    }
};

int main(int argc, char const *argv[])
{
    Facade *f = new ActivateFacade();
    f->doShit();
    delete f;

    return 0;
}
