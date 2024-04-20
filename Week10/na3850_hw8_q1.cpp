//File Name: na3850_hw8_q1.cpp
//Author: Nik Aberle
//Email Address: na3850@nyu.edu
//Assignment Number: Week 10 - HW8 - Q1
//Description: Program that returns the lowest value and index locations from 20 integers.
//Last Change: 3/8/2024


#include<iostream>
using namespace std;

int minInArray(int arr[], int arrSize);

int main()
{
    int size = 20;
    int arr[20];
    int lowest_value = 0;

    cout<<"Please enter 20 integers separated by a space: "<<endl;
    
    for(int i = 0; i < size; i++)
    {
        cin>>arr[i];
    }

    lowest_value = minInArray(arr, size);

    cout<<"The minimum value is "<<lowest_value<<", and it is located in the following indices: ";

    for(int i = 0; i < size; i++)
    {
        if(arr[i] == lowest_value)
        {
            cout<<i<<"  "; 
        }
    }
    cout<<endl;

    return 0; 
}

int minInArray(int arr[], int arrSize)
{
    int lowest = arr[0];

    for(int i = 0; i < arrSize; i++)
    {
        if(arr[i] < lowest)
        {
            lowest = arr[i];
        }
    }
    return lowest;
}
