//File Name: na3850_hw8_q5.cpp
//Author: Nik Aberle
//Email Address: na3850@nyu.edu
//Assignment Number: Week 10 - HW8 - Q5
//Description: Program to format the output of someones first, middle, and last name.
//Last Change: 3/8/2024

#include<iostream>
#include<string>
using namespace std;


int main()
{
    string firstName, middleName, lastName;

    cout<<"Please enter your first name, middle name, and last name all separated by spaces: "<<endl;
    cin>>firstName>>middleName>>lastName;

    cout<<lastName<<", "<<firstName<<" "<<middleName[0]<<". ";

    return 0;
}