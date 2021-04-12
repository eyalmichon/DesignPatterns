#include <iostream>
#include <list>
using namespace std;

class Observable;
class Observer
{
public:
    virtual void update(Observable &o, int temp) = 0;
};
class Observable
{
protected:
    list<Observer *> observers;

public:
    void addObserver(Observer &o)
    {
        observers.push_back(&o);
    }
    virtual void notify() = 0;
    ~Observable()
    {
        for (Observer *o : observers)
            delete o;
    }
};

class WeatherStation : public Observable
{
    int temp = 6;
    int getTemperture()
    {
        return temp;
    }

public:
    void notify()
    {
        for (Observer *o : observers)
        {
            o->update(*this, temp);
        }
    }
    void setTemp(int newTemp)
    {
        temp = newTemp;
        notify();
    }
};

class PhoneDisplay : public Observer
{
    int temp = 0;

public:
    void update(Observable &o, int newTemp)
    {
        temp = newTemp;
    }
    void display()
    {
        cout << "The temperture on the PhoneDisplay is: " << temp << endl;
    }
};
class TouchDisplay : public Observer
{
    int temp = 45;

public:
    void update(Observable &o, int newTemp)
    {
        temp = newTemp;
    }
    void display()
    {
        cout << "The temperture on the TouchDisplay is: " << temp << endl;
    }
};

int main(int argc, char const *argv[])
{
    WeatherStation *w = new WeatherStation();
    PhoneDisplay *p = new PhoneDisplay();
    TouchDisplay *t = new TouchDisplay();
    p->display();
    t->display();
    w->addObserver(*p);
    w->addObserver(*t);
    w->notify();
    p->display();
    t->display();
    w->setTemp(35);
    p->display();
    t->display();

    return 0;
}
