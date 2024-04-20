//File Name: na3850_hw9_q1.cpp
//Author: Nik Aberle
//Email Address: na3850@nyu.edu
//Assignment Number: Week 11 - HW9 - Q1
//Description: Program to count the words and individual letters.
//Last Change: 3/14/2024
//ASCII values for a - z are 97 - 122 inclusive.

#include<iostream>
#include<string>
using namespace std;

void formatText(string& userInput);
void countWords(int& count, string userInput);
void countLetters(string userInput, int stringCount[], char alphabet[]);

int main()
{
    string userInput;
    int wordCount = 0;
    int stringCount[26] = {0};
    char alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    
    cout<<"Please enter a line of text: "<<endl;
    getline(cin, userInput);

    formatText(userInput);
    countWords(wordCount, userInput);

    cout<<wordCount<<"\twords"<<endl;
    countLetters(userInput, stringCount, alphabet);

    for(int i = 0; i < 26; i++)
    {
        if(stringCount[i] > 0)
            cout<<stringCount[i]<<"\t"<<alphabet[i]<<endl;
    }

    return 0;
}

void formatText(string& userInput)
{
    for(int i = 0; i < userInput.length(); i++)
    {
        userInput[i] = tolower(userInput[i]);
        if((int)userInput[i] < 97)
            userInput[i] = '#';
    }
}

void countWords(int& count, string userInput)
{
    for(int i = 0; i < userInput.length(); i++)
    {
        if(i == 0 && userInput[i] >= 97)
            count++;
        else if(userInput[i] == 35 && userInput[i + 1] >= 97)
            count++;
        else
            continue;
    }
}

void countLetters(string userInput, int stringCount[], char alphabet[])
{   
    for(int i = 0; i < 26; i++)
    {
        for(int j = 0; j < userInput.length(); j++)
        {
            if(userInput[j] == alphabet[i])
            {
                stringCount[i]++;
            }
        }
    }
}

