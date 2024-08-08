#include <iostream>

class Person
{
    public:
        Person();
        Person(std::string name);
        std::string name;
        ~Person();
};

Person::Person() // default constructor
{
    std::cout << "Hello from the default condtructor" << std::endl;
}

Person::Person(std::string name) //asyn constructor
{
   this->name = name;
}

Person::~Person() //destructor
{
    std::cout << "Good bye" << std::endl;
}

int main()
{
    Person aboubakr("Zombie");
    Person second;
    aboubakr.name = "hello";
    std::cout << aboubakr.name << std::endl;
}