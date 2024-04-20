//File Name: na3850_hw8_q2.cpp
//Author: Nik Aberle
//Email Address: na3850@nyu.edu
//Assignment Number: Week 10 - HW8 - Q2
//Description: Program to check if a string is a palindrome.
//Last Change: 3/8/2024

#include<iostream>
#include<string>
using namespace std;

bool isPalindrome(string str);

int main()
{
    string userInput;

    cout<<"Please enter a word: ";
    cin>>userInput;

    if(isPalindrome(userInput))
        cout<<userInput<<" is a palindrome";
    else
        cout<<userInput<<" is not a palindrome";

    return 0;
}

bool isPalindrome(string str)
{
    string temp = "";

    for(int i = str.length() - 1; i >= 0; i--)
    {
        temp += str[i];
    }

    if(str == temp)
        return true;
    else
        return false;
}