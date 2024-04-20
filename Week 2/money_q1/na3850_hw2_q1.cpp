#include<iostream>
using namespace std;

const int QUARTER = 25;
const int DIME = 10;
const int NICKEL = 5;
const int PENNY = 1;

int main ()
{

    int q, d, n, p;
    int sum, dollar, cents;

    cout<<"Please enter the number of coins:"<<endl;
    cout<<"# of quarters:";
    cin>>q;
    cout<<"# of dimes: ";
    cin>>d;
    cout<<"# of nickels:";
    cin>>n;
    cout<<"# of pennies: ";
    cin>>p;

    q = q * QUARTER;
    d = d * DIME;
    n = n * NICKEL;
    p = p * PENNY;

    sum = q + d + n + p;
    dollar = sum/100;
    cents = sum % 100;

    cout<<"The total is "<<dollar<<" dollars and "<<cents<<" cents";

    return 0;

}