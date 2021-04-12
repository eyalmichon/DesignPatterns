#include <unordered_map>
#include <iostream>
using namespace std;

class CalcFactorial
{
public:
    virtual int factor(int x) = 0;
};

class Factorial : public CalcFactorial
{
public:
    int factor(int x)
    {
        int fact = 1;
        for (size_t i = x; i > 0; i--)
        {
            fact *= i;
        }
        return fact;
    }
};

class Proxy : public CalcFactorial
{
private:
    unordered_map<int, int> factors;
    Factorial *fact;

public:
    Proxy(Factorial *f)
    {
        fact = f;
    }
    int factor(int x)
    {

        if (factors[x])
        {
            return factors[x];
        }
        factors[x] = fact->factor(x);
        return factors[x];
    }
};

int main(int argc, char const *argv[])
{
    Factorial *f = new Factorial();
    CalcFactorial *n = new Proxy(f);
    cout << n->factor(5) << endl;
    delete f, n;

    return 0;
}
