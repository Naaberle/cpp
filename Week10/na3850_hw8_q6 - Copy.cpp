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

void iterateOverLine(string& userInput) {
    for (int i = 0; i < userInput.length(); i++) {
        if (isdigit(userInput[i])) {
            // Check if the current digit is part of a number that is alone or surrounded by spaces
            int start = i;
            int end = i;
            
            // Extend the start backwards to the beginning of the number
            while (start > 0 && isdigit(userInput[start - 1])) {
                start--;
            }
            
            // Extend the end forwards to the end of the number
            while (end < userInput.length() - 1 && isdigit(userInput[end + 1])) {
                end++;
            }
            
            // Check if the number is surrounded by non-letter characters (or is at the beginning/end of the string)
            bool isIsolatedNumber = (start == 0 || !isalpha(userInput[start - 1])) &&
                                    (end == userInput.length() - 1 || !isalpha(userInput[end + 1]));
            
            if (isIsolatedNumber) {
                // Replace all digits of the isolated number with '#'
                for (int j = start; j <= end; j++) {
                    userInput[j] = '#';
                }
                // Skip past the end of the current isolated number
                i = end;
            }
        }
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

