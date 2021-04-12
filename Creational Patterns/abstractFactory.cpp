#include <iostream>
using namespace std;

class Sword
{
public:
    virtual void makeNoise() = 0;
};

class PlainSword : public Sword
{
public:
    void makeNoise()
    {
        cout << "boing" << endl;
    }
};
class LightSaber : public Sword
{
public:
    void makeNoise()
    {
        cout << "Whoosh" << endl;
    }
};
class Shield
{
public:
    virtual void makeNoise() = 0;
};

class PlainShield : public Shield
{
public:
    void makeNoise()
    {
        cout << "Bing" << endl;
    }
};
class Deflector : public Shield
{
public:
    void makeNoise()
    {
        cout << "deflect" << endl;
    }
};

class Armory
{
public:
    virtual Sword *createSword() = 0;
    virtual Shield *createShield() = 0;
};

class StarWarsArmory : public Armory
{
public:
    Sword *createSword()
    {
        return new LightSaber();
    }
    Shield *createShield()
    {
        return new Deflector();
    }
};
class PlainArmory : public Armory
{
public:
    Sword *createSword()
    {
        return new PlainSword();
    }
    Shield *createShield()
    {
        return new PlainShield();
    }
};

int main(int argc, char const *argv[])
{
    Armory *a = new StarWarsArmory();
    Sword *s = a->createSword();
    Shield *shield = a->createShield();
    s->makeNoise();
    shield->makeNoise();
    return 0;
}
