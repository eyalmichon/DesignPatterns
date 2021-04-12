#include <iostream>
#include <string>

/////////////////////////////////////SORTER////////////////////////////////////
class Sorter
{
public:
    virtual void sort() = 0;
};

class CommonSorter : public Sorter
{
public:
    virtual void sort() override
    {
        std::cout << "This is the Common Sorter" << std::endl;
    }
};

class BubbleSorter : public CommonSorter
{
public:
    void sort() override
    {
        std::cout << "This is the BubbleSorter" << std::endl;
    }
};

/////////////////////////////////////TASK////////////////////////////////////
class Task
{
public:
    virtual void doTask() = 0;
};

/////////////////////////////////////ADAPTER/////////////////////////////////
class SorterTask : public Task
{
    Sorter *s;

public:
    SorterTask(Sorter *s) : s(s) {}
    void doTask() override
    {
        s->sort();
    }
};

/////////////////////////////////////MAIN////////////////////////////////////
int main(int argc, char const *argv[])
{
    Task *t = new SorterTask(new BubbleSorter());
    t->doTask();
    delete t;

    return 0;
}
