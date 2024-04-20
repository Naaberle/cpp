//OOP Practice guided by ChatGPT

#include<iostream>
#include<string>
using namespace std;

class Person
{
    public:
        string name;
        int age;
        string hair;

    //Person(string n, int a) : name(n), age(a) {}
    Person() {}
    
    void setHairColor(string newColor)
    {
        hair = newColor;
    }

    void setName(string n)
    {
        name = n;
    }

    void setAge(int a)
    {
        age = a;
    }

    void introduce()
    {
        cout<<"Hello, my name is "<<name<<" and I am "<<age<<" years old."<<endl;
    }

    void hairColor()
    {
        cout<<"And my hair color is "<<hair<<endl;
    }

};

int main()
{
    string hair;
    string name;
    int age;

    Person person1;

    cout<<"Please enter your name: ";
    cin>>name;

    person1.setName(name);

    cout<<endl;

    cout<<"Please enter your age: ";
    cin>>age;

    person1.setAge(age);

    cout<<endl;

    cout<<"Please enter your hair color: ";
    cin>>hair;

    person1.setHairColor(hair);

    person1.introduce();
    person1.hairColor();

    return 0;
}