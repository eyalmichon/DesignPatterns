#include <iostream>

class HouseImp
{
public:
    virtual void paintDoor() = 0;
    virtual void paintWindow() = 0;
    virtual void paintRoof() = 0;
};

class StrawImp : public HouseImp
{
public:
    virtual void paintDoor()
    {
        std::cout << "Painted Door with straws" << std::endl;
    }
    virtual void paintWindow()
    {

        std::cout << "Painted Window with straws" << std::endl;
    }
    virtual void paintRoof()
    {
        std::cout << "Painted Roof with straws" << std::endl;
    }
};
class WoodImp : public HouseImp
{
public:
    virtual void paintDoor()
    {
        std::cout << "Painted Door with wood" << std::endl;
    }
    virtual void paintWindow()
    {

        std::cout << "Painted Window with wood" << std::endl;
    }
    virtual void paintRoof()
    {
        std::cout << "Painted Roof with wood" << std::endl;
    }
};
class BrickImp : public HouseImp
{
public:
    virtual void paintDoor()
    {
        std::cout << "Painted Door with brick" << std::endl;
    }
    virtual void paintWindow()
    {

        std::cout << "Painted Window with brick" << std::endl;
    }
    virtual void paintRoof()
    {
        std::cout << "Painted Roof with brick" << std::endl;
    }
};
class House
{
protected:
    HouseImp *hI;

public:
    House(HouseImp *hI) : hI(hI) {}
    virtual void paint() = 0;
};

class BigHouse : public House
{
public:
    BigHouse(HouseImp *hI) : House(hI) {}
    void paint()
    {
        std::cout << "This is a Big House " << std::endl;
        hI->paintDoor();
        hI->paintRoof();
        hI->paintWindow();
    }
};
class SmallHouse : public House
{
public:
    SmallHouse(HouseImp *hI) : House(hI) {}
    void paint()
    {
        std::cout << "This is a Small House" << std::endl;
        hI->paintDoor();
        hI->paintRoof();
        hI->paintWindow();
    }
};
class RoundHouse : public House
{
public:
    RoundHouse(HouseImp *hI) : House(hI) {}
    void paint()
    {
        std::cout << "This is a Round House" << std::endl;
        hI->paintDoor();
        hI->paintRoof();
        hI->paintWindow();
    }
};
//////////////////////////////////////////////////////////////////////////

int main(int argc, char const *argv[])
{
    House *h = new BigHouse(new WoodImp());
    h->paint();
    return 0;
}
