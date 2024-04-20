//File Name: na3850_hw9_q3.cpp
//Author: Nik Aberle
//Email Address: na3850@nyu.edu
//Assignment Number: Week 11 - HW9 - Q3
//Description: Four variations of getPosNum function
//Last Change: 3/15/2024

#include<iostream>
using namespace std;

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize);
int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr);
void getPosNums3(int* arr, int arrSize, int* &outPosArr, int &outPosArrSize);
void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr);

int main()
{
    cout<<"Function 1 variation"<<endl;
    int arr1[] = {3, -1, -3, 0, 6, 4};
    int arr1Size = 6;

    int* arr1ptr = getPosNums1(arr1, arr1Size, arr1Size);

    for(int i = 0; i < arr1Size; i++)
        cout<<arr1ptr[i]<<endl;
    delete[] arr1ptr;
    //Function 1 end.
    
    cout<<endl<<endl;

    cout<<"Function 2 variation"<<endl;
    int arr2[] = {3, -1, -3, 0, 6, 4};
    int arr2Size = 6;
    int* arr2SizePtr = &arr2Size;

    int* arr2ptr = getPosNums2(arr2, arr2Size, arr2SizePtr);

    for(int i = 0; i < arr2Size; i++)
        cout<<arr2ptr[i]<<endl;
    delete[] arr2ptr;    
    //Function 2 end. 

    cout<<endl<<endl;

    cout<<"Function 3 variation"<<endl;
    int arr3[] = {3, -1, -3, 0, 6, 4};
    int arr3Size = 6;
    int* arr3Addr = arr3;

    getPosNums3(arr3, arr3Size, arr3Addr, arr3Size);

    for(int i = 0; i < arr3Size; i++)
        cout<<arr3Addr[i]<<endl;
    delete[] arr3Addr;
    //Function 3 end.

    cout<<endl<<endl;

    cout<<"Function 4 variation"<<endl;
    int arr4[] = {3, -1, -3, 0, 6, 4};
    int arr4Size = 6;
    int* arr4SizePtr = &arr4Size;
    int* arr4Loc = nullptr;

    getPosNums4(arr4, arr4Size, &arr4Loc, arr4SizePtr);

    for(int i = 0; i < arr4Size; i++)
        cout<<arr4Loc[i]<<endl;

    delete[] arr4Loc;
    //Function 4 end.

    return 0;
}

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize)
{
    int newTempSize = 0;

    for(int i = 0; i < arrSize; i++)
        if(arr[i] > 0)
            newTempSize++;

    outPosArrSize = newTempSize;
    int* tempArrPtr = new int[newTempSize];
    int posIndex = 0;

    for(int i = 0; i < arrSize; i++)
    {
        if(arr[i] > 0)
        {
            tempArrPtr[posIndex] = arr[i];
            posIndex++;
        }
    }
    return tempArrPtr;
}

int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr)
{
    int newTempSize = 0;

    for(int i = 0; i < arrSize; i++)
        if(arr[i] > 0)
            newTempSize++;

    *outPosArrSizePtr = newTempSize;
    int* tempArrPtr = new int[newTempSize];
    int posIndex = 0;

    for(int i = 0; i < arrSize; i++)
    {
        if(arr[i] > 0)
        {
            tempArrPtr[posIndex] = arr[i];
            posIndex++;
        }
    }
    return tempArrPtr;
}

void getPosNums3(int* arr, int arrSize, int* &outPosArr, int &outPosArrSize)
{
    int newTempSize = 0;

    for(int i = 0; i < arrSize; i++)
        if(arr[i] > 0)
            newTempSize++;

    outPosArrSize = newTempSize;
    int* tempArrPtr = new int[newTempSize];
    int posIndex = 0;

    for(int i = 0; i < arrSize; i++)
    {
        if(arr[i] > 0)
        {
            tempArrPtr[posIndex] = arr[i];
            posIndex++;
        }
    }

    outPosArr = tempArrPtr;
}

void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr)
{
    int newTempSize = 0;

    for(int i = 0; i < arrSize; i++)
        if(arr[i] > 0)
            newTempSize++;

    *outPosArrSizePtr = newTempSize;
    int* tempArrPtr = new int[newTempSize];
    int posIndex = 0;

    for(int i = 0; i < arrSize; i++)
    {
        if(arr[i] > 0)
        {
            tempArrPtr[posIndex] = arr[i];
            posIndex++;
        }
    }
    *outPosArrPtr = tempArrPtr;
}
