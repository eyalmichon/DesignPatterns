#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Employee
{
protected:
    string name;
    int age;

public:
    Employee(string name, int age) : name(name), age(age) {}
    virtual void doWork() = 0;
};

class Manager : public Employee
{
private:
    vector<Employee *> vec;
    bool check = false;

public:
    Manager(string name, int age) : Employee(name, age) {}
    void doWork()
    {
        if (!check)
        {
            check = true;
            cout << "I'm doing Manager's work!" << endl;
            for (Employee *e : vec)
                e->doWork();
        }
    }
    void addEmployee(Employee *empl)
    {
        if (empl != this)
        {

            vec.push_back(empl);
        }
    }
};
class Engineer : public Employee
{
public:
    Engineer(string name, int age) : Employee(name, age) {}
    void doWork()
    {
        cout << "I'm doing Engineer's work!" << endl;
    }
};
class Architect : public Employee
{
public:
    Architect(string name, int age) : Employee(name, age) {}
    void doWork()
    {
        cout << "I'm doing Architect's work!" << endl;
    }
};

int main(int argc, char const *argv[])
{
    Manager *m = new Manager("Eli", 55);
    Manager *m2 = new Manager("Elihau", 55);
    m->addEmployee(new Architect("Gal", 23));
    m->addEmployee(new Engineer("Aflalo", 400));
    m->addEmployee(m2);
    m2->addEmployee(m);
    m->addEmployee(m);
    m->doWork();
    return 0;
}
