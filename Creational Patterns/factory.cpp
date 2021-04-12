#include <unordered_map>
#include <iostream>
using namespace std;

class Animal
{
public:
    virtual void talk() = 0;
};

class Hemi : public Animal
{
public:
    void talk()
    {
        cout << "Oink Oink!" << endl;
    }
};
class Tzvika : public Animal
{
public:
    void talk()
    {
        cout << "Moooooooooo MOOOOOO!" << endl;
    }
};

class Creator
{
public:
    virtual Animal *create() = 0;
};

class HemiCreator : public Creator
{
public:
    Animal *create()
    {
        return new Hemi();
    }
};
class TzvikaCreator : public Creator
{
public:
    Animal *create()
    {
        return new Tzvika();
    }
};
class AnimalFactory
{
private:
    unordered_map<string, Creator *> animals;

public:
    AnimalFactory()
    {
        animals["Hemi"] = new HemiCreator();
        animals["Tzvika"] = new TzvikaCreator();
    }
    Animal *createAnimal(string name)
    {
        Creator *c = animals[name];
        if (c != nullptr)
        {
            return c->create();
        }
        return nullptr;
    }
};

int main(int argc, char const *argv[])
{
    AnimalFactory *f = new AnimalFactory();
    Animal *hemi = f->createAnimal("Hemi");
    Animal *tzvi = f->createAnimal("Tzvika");
    hemi->talk();
    tzvi->talk();
    return 0;
}
