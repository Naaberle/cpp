#include<iostream>
using namespace std;

int main()
{
    //cout<<27 % 7;
    int year;

    cout<<"Enter year: ";
    cin>>year;

    if(year % 4 == 0)
    {
        if(year % 100 == 0 && year % 400 != 0)
            cout<<"false";
        else
            cout<<"true";    
    }
    else
        cout<<"false";

    return 0;
}