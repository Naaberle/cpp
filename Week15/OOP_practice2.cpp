#include<iostream>
using namespace std;

void printValue(int dollars, int cents);

class Money 
{

private:
    int dollars;
    int cents;

public:

    Money(int d, int c) : dollars(d), cents(c) {}

    int getDollars() const {
        return dollars;
    }

    int getCents() const {
        return cents;
    }


};

int main()
{
    Money monday(11, 34);

    int dollars = monday.getDollars();
    int cents = monday.getCents(); 

    printValue(dollars, cents);

    return 0;
}

void printValue(int dollars, int cents)
    {
        cout<<"You have $"<<dollars<<"."<<cents<<" in your account."<<endl;
    }


    
/*
class Person {
private:
    std::string name;
    int age;

public:
    // Constructor to initialize the Person object
    Person(std::string n, int a) : name(n), age(a) {}

    // Accessor function for the name member variable
    std::string getName() const {
        return name;
    }

    // Accessor function for the age member variable
    int getAge() const {
        return age;
    }
};


*/