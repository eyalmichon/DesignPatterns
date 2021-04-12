#include <string>
#include <iostream>
using namespace std;

class Student
{
    const string name;
    const int age;
    const int GPA;

public:
    Student(string name, int age, int GPA) : name(name), age(age), GPA(GPA) {}
    friend ostream &operator<<(ostream &out, Student s)
    {
        out << s.name << ", age: " << s.age << ", GPA: " << s.GPA << endl;
        return out;
    }
};

class Builder
{
public:
    virtual Builder &setName(string name) = 0;
    virtual Builder &setAge(int age) = 0;
    virtual Builder &setGPA(int GPA) = 0;
    virtual Student build() = 0;
};

class StudentBuilder : public Builder
{
private:
    string name;
    int age;
    int GPA;

public:
    virtual Builder &setName(string newName)
    {
        name = newName;
        return *this;
    }
    virtual Builder &setAge(int newAge)
    {
        age = newAge;
        return *this;
    }
    virtual Builder &setGPA(int newGPA)
    {
        GPA = newGPA;
        return *this;
    }
    virtual Student build()
    {
        return Student(name, age, GPA);
    }
};

int main(int argc, char const *argv[])
{
    Builder *b = new StudentBuilder();
    Student s = b->setAge(3).setGPA(4).setName("Eyal").setAge(25).build();
    cout << s;
    return 0;
}
