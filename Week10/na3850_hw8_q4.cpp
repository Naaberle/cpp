//File Name: na3850_hw8_q4.cpp
//Author: Nik Aberle
//Email Address: na3850@nyu.edu
//Assignment Number: Week 10 - HW8 - Q4
//Description: Program to implement a randomized challenge-response system for PINs.
//Last Change: 3/8/2024

#include<iostream>
using namespace std;

void randArr(int arr[], int arrSize);
void pinToArray(int arr[], int arrSize);
bool correctPIN(int arr[], int userInput);

const int PIN = 66345;

int main()
{
    int numArr[10] = {};
    int zeroToNine[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int arrSize = 10;
    int PINInput;

    randArr(numArr, arrSize);

    cout<<"Please enter your PIN according to the following mapping:"<<endl;

    cout<<"PIN: \t";
    for(int i = 0; i < arrSize; i++)
        cout<<zeroToNine[i]<<" ";
    cout<<endl;

    cout<<"NUM: \t";
    for(int i = 0; i < arrSize; i++)
        cout<<numArr[i]<<" ";

    cout<<endl;

    cin>>PINInput;

    if(correctPIN(numArr, PINInput))
        cout<<"Your PIN is correct";
    else
        cout<<"Your PIN is not correct";

    return 0;
}

void randArr(int arr[], int arrSize)
{
    srand(time(NULL));

    for(int i = 0; i < arrSize; i++)
    {
        int randDigit = rand() % 3 + 1;
        arr[i] = randDigit;
    }
}

void pinToArray(int arr[], int pinNeeded)
{
    int temp = pinNeeded;

    for(int i = 4; i >= 0; i--)
    {
        arr[i] = temp % 10;
        temp = temp / 10;
    }
}

bool correctPIN(int randArr[], int userInput)
{
    int count = 0;
    int pinArr[5] = {};
    int userInputArr[5] = {};
    pinToArray(pinArr, PIN);
    pinToArray(userInputArr, userInput);

    for(int i = 0; i < 5; i++)
    {
        if(randArr[pinArr[i]] == userInputArr[i])
            count++;
    }

    if(count == 5)
        return true;
    else 
        return false;
}


//aa