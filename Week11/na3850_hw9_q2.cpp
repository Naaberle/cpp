//File Name: na3850_hw9_q2.cpp
//Author: Nik Aberle
//Email Address: na3850@nyu.edu
//Assignment Number: Week 11 - HW9 - Q2
//Description: Program to check if two strings are anagrams, punctuation and spaces excluded.
//Last Change: 3/14/2024
//ASCII values for a - z are 97 - 122 inclusive.

#include<iostream>
#include<string>
using namespace std;

void countLength(string& userInput, int& charCount);
void countChars(int userString[], string userInput);
bool isAnagram(string &firstString, string &secondString);

int main()
{
    string firstString, secondString;
    
    cout<<"Please enter the first string: "<<endl;
    getline(cin, firstString);

    cout<<endl;

    cout<<"Please enter the second string: "<<endl;
    getline(cin, secondString);

    if(isAnagram(firstString, secondString))
        cout<<"These two strings are anagrams."<<endl;
    else 
        cout<<"These two strings are not anagrams."<<endl;
                
    return 0;
}

void countLength(string& userInput, int& charCount)
{
    for(int i = 0; i < userInput.length(); i++)
    {
        userInput[i] = tolower(userInput[i]);
    }

    for(int i = 0; i < userInput.length(); i++)
    {
        if(((int)userInput[i] >= 97 && (int)userInput[i] <= 122))
            charCount++;
        else
            continue;
    }

}

void countChars(int userString[], string userInput)
{
    char alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    for(int i = 0; i < 26; i++)
    {
        for(int j = 0; j < userInput.length(); j++)
        {
            if(userInput[j] == alphabet[i])
            {
                userString[i]++;
            }
        }
    }
}

bool isAnagram(string &firstString, string &secondString)
{
    int firstStringArr[26] = {0};
    int secondStringArr[26] = {0};
    int firstStringCt = 0, secondStringCt = 0;

    countLength(firstString, firstStringCt);
    countLength(secondString, secondStringCt);

    if(firstStringCt != secondStringCt)
        return false;
    else 
        countChars(firstStringArr, firstString);
        countChars(secondStringArr, secondString);

        for(int i = 0; i < 26; i++)
            if(firstStringArr[i] != secondStringArr[i])
                return false;

    return true;
}

// 