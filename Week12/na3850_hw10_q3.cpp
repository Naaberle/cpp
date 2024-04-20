//File Name: na3850_hw10_q3.cpp
//Author: Nik Aberle
//Email Address: na3850@nyu.edu
//Assignment Number: Week 12 - HW10 - Q3
//Description: Program to search for a specific integer within an array of integers.
//Last Change: 3/21/2024

#include<iostream>
#include<vector>
using namespace std;

void main1();
void main2();
void resizeArray(int* &arr, int currentSize, int newSize);
void searchVector(vector<int> inputVector, vector<int> &lineNums, int searchNum);

int main()
{
    main1();
    main2();

    return 0;
}

void main1()
{
    int arrayInput = 0, searchNum;
    int size = 1;
    int* arr = new int[size];

    cout<<"Please enter a sequence of positive integers, each in a separate line."<<endl;
    cout<<"End your input by typing -1."<<endl;

    while(arrayInput >= 0)
    {   
        cin>>arrayInput;

        if(arrayInput >= 0)
        {
            arr[size - 1] = arrayInput;
            int newSize = size + 1;
            resizeArray(arr, size, newSize);
            size = newSize;
        }      
    }

    cout<<"Please enter a number you want to search."<<endl;
    cin>>searchNum;

    int counter = 0;

    for(int i = 0; i < size - 1; i++)
    {        
        if(arr[i] == searchNum)
        {
            counter++;
        }
    }

    if(counter == 0)
        cout<<searchNum<<" does not show in the sequence."<<endl;
    else
        cout<<searchNum<<" shows in lines ";
        for(int i = 0; i < size - 1; i++)
        {
            if(arr[i] == searchNum)
            {
                cout<<i + 1;
                counter--;
                if(counter > 0)
                    cout<<", ";
                else
                    cout<<".";
            }
        }

    delete[] arr;
}

void resizeArray(int* &arr, int currentSize, int newSize)
{
    int* temp = new int[newSize];
    for(int i = 0; i < currentSize; i++)
        temp[i] = arr[i];
    delete[] arr;
    arr = temp;
}

void main2()
{
    vector<int> main2Vec;
    vector<int> lineNums;
    int vectorInput = 0, searchNum = 0;

    cout<<"Please enter a sequence of positive integers, each in a separate line."<<endl;
    cout<<"End your input by typing -1."<<endl;

    while(vectorInput >= 0)
    {   
        cin>>vectorInput;

        if(vectorInput >= 0)
        {
            main2Vec.push_back(vectorInput);
        }      
    }

    cout<<"Please enter a number you want to search."<<endl;
    cin>>searchNum;

    searchVector(main2Vec, lineNums, searchNum);

    if(lineNums.size() == 0)
        cout<<searchNum<<" does not show in the sequence."<<endl;
    else
        cout<<searchNum<<" shows in lines ";
        for(int i = 0; i < lineNums.size(); i++)
        {
            cout<<lineNums[i];
            if(i < lineNums.size() - 1)
                cout<<", ";
            else
                cout<<".";
        }
}

void searchVector(vector<int> inputVector, vector<int> &lineNums, int searchNum)
{
    for(int i = 0; i <inputVector.size(); i++)
    {
        if(inputVector[i] == searchNum)
            lineNums.push_back(i + 1);
    }
}
//