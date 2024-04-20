//File Name: na3850_hw10_q2.cpp
//Author: Nik Aberle
//Email Address: na3850@nyu.edu
//Assignment Number: Week 12 - HW10 - Q2
//Description: Intakes a sentence that outputs an array of individuals words and the word count.
//Last Change: 3/15/2024

#include<iostream>
#include<vector>
using namespace std;

int* findMissing(int arr[], int n, int &resArrSize);

int main()
{
    int arr[] = {3, 1, 3, 0, 6, 4};
    int arrSize = 6;
    int resArrSize = 0;

    int* missingNums = findMissing(arr, arrSize, resArrSize);

    cout<<"The numbers missing from the array are: "<<endl;
    for(int i = 0; i < resArrSize; i++)
        cout<<missingNums[i]<<endl;

    return 0;
}

int* findMissing(int arr[], int n, int &resArrSize)
{
    int maxNum = -1;

    for(int i = 0; i < n; i++)
    {
        if(arr[i] > maxNum)
            maxNum = arr[i];
    }

    vector<bool> includedNums(maxNum + 1, false);
    for(int i = 0; i < n; i++)
    {
        if(arr[i] >= 0)
        {
            includedNums[arr[i]] = true;
        }
    }

    vector<int> missingNums;
    for(int i = 0; i <= maxNum; i++)
    {
        if(!includedNums[i])
            missingNums.push_back(i);
    }

    resArrSize = missingNums.size();
    int* missingNumsArr = new int[resArrSize];
    for(int i = 0; i < resArrSize; i++)
    {
        missingNumsArr[i] = missingNums[i];
    }

    return missingNumsArr;
}