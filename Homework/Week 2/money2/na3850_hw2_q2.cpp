#include<iostream>
using namespace std;

const int QUARTER = 25;
const int DIME = 10;
const int NICKEL = 5;
const int PENNY = 1;

int main()
{

    int quarters, dimes, nickels, pennies;
    int total, dollars, cents; 

    cout<<"Please enter your amount in the format of dollars and cents separated by a space:"<<endl;
    cin>>dollars>>cents;

    total = (dollars * 100) + cents;

    quarters = total/QUARTER;
    total = total % QUARTER;

    dimes = total/DIME;
    total = total % DIME;

    nickels = total/NICKEL;
    total = total % NICKEL;

    pennies = total;

    cout<<quarters<<" quarters, "<<dimes<<" dimes, "<<nickels<<" nickels and "<<pennies<<" pennies.";

    return 0;  

}