//File Name: na3850_hw8_q3.cpp
//Author: Nik Aberle
//Email Address: na3850@nyu.edu
//Assignment Number: Week 10 - HW8 - Q3
//Description: Program to manipulate arrays in various ways.
//Last Change: 3/8/2024

#include<iostream>
using namespace std;

void reverseArray(int arr[], int arrSize);
void removeOdd(int arr[], int& arrSize);
void splitParity(int arr[], int arrSize);
void printArray(int arr[], int arrSize);

int main()
{
    int arr1[10] = {9, 2, 14, 12, -3};
    int arr1Size = 5;

    int arr2[10] = {21, 12, 6, 7, 14};
    int arr2Size = 5;

    int arr3[10] = {3, 6, 4, 1, 12};
    int arr3Size = 5;

    reverseArray(arr1, arr1Size);
    printArray(arr1, arr1Size);

    removeOdd(arr2, arr2Size);
    printArray(arr2, arr2Size);

    splitParity(arr3, arr3Size);
    printArray(arr3, arr3Size);

    return 0;
}

void reverseArray(int arr[], int arrSize)
{
    int temp;

    for(int i = 0, j = arrSize - 1; i < j; i++, j--)
    {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void removeOdd(int arr[], int& arrSize)
{
    int position = 0;
    for(int i = 0; i < arrSize; i++)
    {
        if(arr[i] % 2 == 0)
        {
            arr[position++] = arr[i];
        }
    }

    arrSize = position;
}

void splitParity(int arr[], int arrSize)
{
    int oddPos = 0;
    int evenPos = 0;

    for(oddPos, evenPos; evenPos < arrSize; evenPos++)
    {
        if(arr[evenPos] % 2 != 0)
        {
            int temp = arr[evenPos];
            arr[evenPos] = arr[oddPos];
            arr[oddPos] = temp;
            oddPos++;
        }
    }
}

void printArray(int arr[], int arrSize)
{
    int i;

    for (i = 0; i < arrSize; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}