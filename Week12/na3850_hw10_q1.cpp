//File Name: na3850_hw10_q1.cpp
//Author: Nik Aberle
//Email Address: na3850@nyu.edu
//Assignment Number: Week 12 - HW10 - Q1
//Description: Intakes a sentence that outputs an array of individuals words and the word count.
//Last Change: 3/15/2024

#include<iostream>
#include<string>
using namespace std;

string* createWordsArray(string sentence, int &outWordsArrSize);

int main()
{
    string userInput;

    cout<<"Please enter a sentence with words separated by only a single space: "<<endl;
    getline(cin, userInput);
    int wordCount = 0;

    string* wordArray = createWordsArray(userInput, wordCount);

    cout<<endl;
    cout<<"That sentence has "<<wordCount<<" words in it and they are: "<<endl;
    cout<<"[";
    for(int i = 0; i < wordCount; i++)
    {
        if(i == wordCount - 1)
            cout<<"\""<<wordArray[i]<<"\"";
        else
            cout<<"\""<<wordArray[i]<<"\" , ";
    }
    cout<<"]"<<endl;

    delete[] wordArray; 
    return 0;
}

string* createWordsArray(string sentence, int &outWordsArrSize)
{
    int wordCount = 1;
    int spacesIndex = 0;
    int wordLenIndex = 0;
    int wordIndex = 0;
    int letterCount = 0;

    while(sentence.front() == 32)
        sentence.erase(0, 1);

    while(sentence.back() == 32)
        sentence.erase(sentence.length() - 1);

    for(int i = 0; i < sentence.length(); i++)
        if(sentence[i] == 32)
            wordCount++;

    outWordsArrSize = wordCount;
    string* wordArr = new string[wordCount];
    int* spaceLocs = new int[wordCount];
    int* wordLengths = new int[wordCount];

    for(int i = 0; i < sentence.length(); i++)
        if(i == 0)
            spaceLocs[spacesIndex++] = i;
        else if(sentence[i] == 32)
            spaceLocs[spacesIndex++] = i + 1;

    for(int i = 0; i < sentence.length(); i++)
    {
        if(sentence[i] != 32)
            if(i == sentence.length() - 1)
            {
                letterCount++;
                wordLengths[wordLenIndex++] = letterCount;
            }
            else
                letterCount++;
        else if(sentence[i] == 32)
        {
            wordLengths[wordLenIndex++] = letterCount;
            letterCount = 0;
        }
    }

    for(int i = 0; i < wordCount; i++)
    {
        wordArr[i] = sentence.substr(spaceLocs[i], wordLengths[i]);
    }

    delete[] spaceLocs;
    delete[] wordLengths;
    return wordArr;
}