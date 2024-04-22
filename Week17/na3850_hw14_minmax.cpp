//File Name: na3850_hw14_minmax.cpp
//Author: Nik Aberle
//Email Address: na3850@nyu.edu
//Assignment Number: Week 17 - HW14 - MinMax
//Description: Takes in a vector and uses a recursive function to return a vector with the lowest and highest
//Last Change: 3/15/2024

#include <iostream>
#include <vector>
using namespace std;

vector<int> divConq(vector<int> vec);

int main() {
    vector<int> input = {2,1,5,3,4};
    vector<int> output = divConq(input);

    cout<<"Minimum: "<<output[0]<<", Maximum: "<<output[1]<<endl;

    return 0;
}

vector<int> divConq(vector<int> vec)
{ 
    //Base case for empty vector
    if(vec.size() <= 0) {
        return {0,0};
    }
    //Base case of 1
    if(vec.size() == 1) {
        return {vec[0],vec[0]};
    }

    //Base case of 2
    else if(vec.size() == 2) {
        if(vec[0] < vec[1]) {
            return {vec[0], vec[1]};
        }
        else {
            return {vec[1], vec[0]};
        }
    }

    //3+ elements
    vector<int> firstHalf = divConq(vector<int>(vec.begin(), vec.begin() + (vec.size() / 2))); // creates a recursive call to operate on the first half of the vector passed into the function.
    vector<int> secondHalf = divConq(vector<int>(vec.begin() + (vec.size() / 2), vec.end())); // creates a recursive call to operate on the second half of the vector passed into the function.

    //Compares the results of firstHalf and secondHalf and returns the correct result.
    int minVal, maxVal;

    if(firstHalf[0] < secondHalf[0]) {
        minVal = firstHalf[0];
    }
    else {
        minVal = secondHalf[0];
    }

    if(firstHalf[1] > secondHalf[1]) {
        maxVal = firstHalf[1];
    }
    else {
        maxVal = secondHalf[1];
    }

    return {minVal, maxVal};
}