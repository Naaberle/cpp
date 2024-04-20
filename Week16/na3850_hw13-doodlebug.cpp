//File Name: na3850_hw13-doodlebug.cpp
//Author: Nik Aberle
//Email Address: na3850@nyu.edu
//Assignment Number: Week 16 - HW13 - doodlebug
//Description: A predator/prey board evolution on a 20x20 grid
//Last Change: 4/15/2024

#include <iostream>
#include <vector>
using namespace std;

class Animal
{
private:
    int Age;
    char Name;

public:
    

    Animal() {}

    Animal(char name, int age) : Name(name), Age(age) {}

    int getAge() const {
        return Age;
    } 

    int setAge() const {

    }

    char getName() const {
        return Name;
    }



};

int main()
{



    return 0;
}