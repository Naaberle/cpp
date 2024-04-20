//File Name: na3850_hw9_q4.cpp
//Author: Nik Aberle
//Email Address: na3850@nyu.edu
//Assignment Number: Week 11 - HW9 - Q4
//Description: Program to reorder the elements of an array by parity.
//Last Change: 3/15/2024

#include<iostream>
using namespace std;

void oddsKeepEvensFlip(int arr[], int arrSize);

int main()
{
    int arr[] = {5, 2, 11, 7, 6, 4};
    int arrSize = 6;

    oddsKeepEvensFlip(arr, arrSize);

    for(int i = 0; i < arrSize; i++)
        cout<<arr[i]<<endl; 
    
    return 0;
}

void oddsKeepEvensFlip(int arr[], int arrSize)
{
    int oddCount = 0;
    int evenCount = 0;
    int oddIndex = 0, evenIndex = 0;

    for(int i = 0; i < arrSize; i++)
    {
        if(arr[i] % 2 != 0)
            oddCount++;
        else
            evenCount++;
    }

    int* oddArrPtr = new int[oddCount];
    int* evenArrPtr = new int[evenCount];

    for(int i = 0; i < arrSize; i++)
    {
        if(arr[i] % 2 != 0)
        {
            oddArrPtr[oddIndex++] = arr[i];
        }
        else
        {
            evenArrPtr[evenIndex++] = arr[i];
        }
    }

    for(int i = 0; i < oddCount; i++)
    {
        arr[i] = oddArrPtr[i];
    }

    for(int i = oddCount, j = evenCount - 1; i < arrSize; i++, j--)
    {
        arr[i] = evenArrPtr[j];
    }

    delete[] oddArrPtr;
    delete[] evenArrPtr;
}