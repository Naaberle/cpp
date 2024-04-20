//File Name: na3850_hw8_q6.cpp
//Author: Nik Aberle
//Email Address: na3850@nyu.edu
//Assignment Number: Week 10 - HW8 - Q6
//Description: Program that reads in a line of text and outputs the line with all integers replaced with 'x'.
//Last Change: 3/8/2024
// ASCII values for 0 - 9 are 48 - 57 inclusive.
// ASCII value for space is 32, # is 35
// ASCII value for Caps is 65 - 90
// ASCII value for lower is 97 - 122

#include<iostream>
#include<string>
using namespace std;

void iterateOverLine(string& userInput);
void replaceWithX(string& userInput);

int main()
{
    string lineOfText;

    cout<<"Please enter a line of text: "<<endl;
    getline(cin, lineOfText);
    iterateOverLine(lineOfText);
    replaceWithX(lineOfText);
    cout<<lineOfText;

    return 0;
}

void iterateOverLine(string& userInput)
{
    int tracker = 0;

    for(int i = 0; i < userInput.length(); i++)
    {
        if((int)userInput[i] > 57)
            tracker = 1;
        else if((int)userInput[i] == 32)
            tracker = 0;

        if((int)userInput[i] >= 48 && (int)userInput[i] <= 57 && tracker == 0)
        {
            if((int)userInput[i + 1] == 32) // Checking for next char is a space
                if(((int)userInput[i - 1] >= 33 && (int)userInput[i - 1] <= 57) || (int)userInput[i - 1] == 32) //Checking if previous is a digit or a space
                    userInput[i] = '#';
                else
                    continue;

            else if((int)userInput[i - 1] >= 57) //Checking if the previous char is a letter.
                continue;
            
            else if((int)userInput[i + 1] >= 57) //Checking if the next char is a letter.
                continue;

            else
                userInput[i] = '#';
        }
        else
            continue;
    } 
}

void replaceWithX(string& userInput)
{
    for(int i = 0; i < userInput.length(); i++)
    {
        if((int)userInput[i] == 35)
            userInput[i] = 'x';
        else
            continue;
    }
}

