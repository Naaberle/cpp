//File Name: na3850_hw7_q2.cpp
//Author: Nik Aberle
//Email Address: na3850@nyu.edu
//Assignment Number: Week 9 - HW7 - Q2
//Description: Program to calculate the perfect numbers and amicable pairs from 2 to an entered number.
//Last Change: 3/1/2024

#include<iostream>
#include<cmath>
using namespace std;

void analyzeDividors(int num, int& outCountDivs, int& outSumDivs);
bool isPerfect(int num);

int main()
{
    int num;

    cout<<"Please enter a number greater than or equal to 2: ";
    cin>>num;
    cout<<endl;

    cout<<"All of the perfect numbers between 2 and "<<num<<" are: "<<endl;

    for(int i = 2; i <= num; i++)
    {
        if(isPerfect(i))
            cout<<i<<endl;
    }    

    cout<<endl;

    cout<<"All of the amicable pairs between 2 and "<<num<<" are: "<<endl;

    for(int i = 2; i <= num; i++)
    {
        int tempSum = 1;
        int amicCountDivs = 1, amicSumDivs = 1;

        analyzeDividors(i, amicCountDivs, tempSum);

        amicCountDivs = 1;

        analyzeDividors(tempSum, amicCountDivs, amicSumDivs);

        if(i == amicSumDivs && tempSum <= num && i != tempSum && i < tempSum)
        {
            cout<<i<<" and "<<tempSum<<endl;
        }
    }
    return 0;
}

void analyzeDividors(int num, int& outCountDivs, int& outSumDivs)
{
    for(int i = 2; i <= sqrt(num); i++)
    {
        if(num % i == 0)
        {
            outCountDivs++;
            outSumDivs += i;
            if(i < sqrt(num))
                outSumDivs += (num / i);
                outCountDivs++;
        }
    }
}

bool isPerfect(int num)
{
    int boolCountDivs = 1, boolSumDivs = 1;

    analyzeDividors(num, boolCountDivs, boolSumDivs);

    if(num == boolSumDivs)
        return true;
    else
        return false;

}