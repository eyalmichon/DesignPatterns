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
    virtual void sort()
    {
        std::cout << "This is the Common Sorter" << std::endl;
    }
};

class BubbleSorter : public CommonSorter
{
public:
    void sort()
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
class BubbleSorterTask : public Task, public BubbleSorter
{
    BubbleSorter *bs;

public:
    BubbleSorterTask(BubbleSorter *bs) : bs(bs) {}
    virtual void doTask()
    {
        bs->sort();
    }
};

/////////////////////////////////////MAIN////////////////////////////////////
int main(int argc, char const *argv[])
{
    Task *t = new BubbleSorterTask(new BubbleSorter());
    t->doTask();

    return 0;
}
