//File Name: na3850kw3579_hw14_minmax.cpp
//Author: Nik Aberle & Kristine Wetch
//Email Address: na3850@nyu.edu // kw3579@nyu.edu
//Assignment Number: Week 17 - HW14 - MinMax
//Description: Takes in a vector and uses a recursive function to return a vector with the lowest and highest
//Last Change: 4/21/2024

#include <iostream>
#include <vector>
using namespace std;

template <typename T>
vector<T> divConq(vector<T> vec)
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
    vector<T> firstHalf = divConq(vector<T>(vec.begin(), vec.begin() + (vec.size() / 2))); // creates a recursive call to operate on the first half of the vector passed To the function.
    vector<T> secondHalf = divConq(vector<T>(vec.begin() + (vec.size() / 2), vec.end())); // creates a recursive call to operate on the second half of the vector passed To the function.

    //Compares the results of firstHalf and secondHalf and returns the correct result.
    T minVal, maxVal;

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

int main() {
     
    vector<int> intInput = {11, 89, 79, 4, 13, 33, 73, 30, 69, 77, 48, 17, 42, 32, 98, 16, 69, 65, 14, 41};
    vector<int> intOutput = divConq(intInput);
    cout<<"Minimum Integer: "<<intOutput[0]<<", Maximum Integer: "<<intOutput[1]<<endl;

    cout<<endl<<endl;

    vector<double> dblInput = {12.345, 23.456, 34.567, 45.678, 56.789, 67.890, 78.901, 89.012, 92.123, 10.234, 21.345, 32.456, 43.567, 54.678, 65.789, 76.890, 87.901, 98.012, 99.123, 11.234};
    vector<double> dblOutput = divConq(dblInput);
    cout<<"Minimum Double: "<<dblOutput[0]<<", Maximum Double: "<<dblOutput[1]<<endl;

    cout<<endl<<endl;

    vector<float> fltInput = {1.2f, 23.5f, 45.7f, 67.9f, 89.1f, 10.3f, 12.4f, 34.6f, 56.8f, 78.0f, 99.2f, 11.1f, 33.3f, 55.5f, 77.7f, 20.2f, 40.4f, 60.6f, 80.8f, 90.9f};
    vector<float> fltOutput = divConq(fltInput);
    cout<<"Minimum Double: "<<fltOutput[0]<<", Maximum Double: "<<fltOutput[1]<<endl;

    cout<<endl<<endl;

    vector<char> chrInput = {'s', 'd', 'a', 't', 'm', 'h', 'e', 'p', 'r', 'b', 'i', 'n', 'o', 'c', 'k', 'f', 'g', 'l', 'q', 'j'};
    vector<char> chrOutput = divConq(chrInput);
    cout<<"Lowest Character: "<<chrOutput[0]<<", Largest Character: "<<chrOutput[1]<<endl;
 
/* 
    //Uncomment this out to test user inputted vectors
    //Be sure to adjust the type of userVec & userInput before running
    vector<int> userVec;   //<--- Change type of vector here
    int userInput;         //<--- Change type of input to match vector here.

    cout<<"Please enter your list of values. Enter any non-type value when you're finished."<<endl;

    while(cin>>userInput) {
        userVec.push_back(userInput);
    }

    cin.clear();

    vector<int> userOutput = divConq(userVec);   //<--- Change type of vector here to match userVec;
    cout<<"Minimum value: "<<userOutput[0]<<", Maximum Value: "<<userOutput[1]<<endl;
*/
    return 0;
}