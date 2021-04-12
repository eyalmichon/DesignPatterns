#include <iostream>
using namespace std;

class Satan
{
    static Satan *satan;

private:
    Satan() {}

public:
    static Satan *getInstance()
    {
        if (satan == nullptr)
        {
            satan = new Satan();
        }
        return satan;
    }
};

Satan *Satan::satan = nullptr;

int main(int argc, char const *argv[])
{
    Satan *s1 = Satan::getInstance();
    Satan *s2 = Satan::getInstance();
    cout << s1 << endl
         << s2 << endl;
    return 0;
}
