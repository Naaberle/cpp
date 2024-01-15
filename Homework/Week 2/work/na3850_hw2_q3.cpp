#include<iostream>
using namespace std;

const int HOURS_IN_DAY = 24;
const int MIN_IN_HOUR = 60;
const int MIN_IN_DAY = 1440;

int main()
{

    int days_worked, hours_worked, minutes_worked;
    int john_days, john_hours, john_minutes;
    int bill_days, bill_hours, bill_minutes;

    cout<<"Please enter the number of days John has worked: ";
    cin>>john_days;
    cout<<"Please enter the number of hours John has worked: ";
    cin>>john_hours;
    cout<<"Please enter the number of minutes John has worked: ";
    cin>>john_minutes;
    cout<<"\n";
    cout<<"Please enter the number of days Bill has worked: ";
    cin>>bill_days;
    cout<<"Please enter the number of hours Bill has worked: ";
    cin>>bill_hours;
    cout<<"Please enter the number of minutes Bill has worked: ";
    cin>>bill_minutes;

    days_worked = john_days + bill_days;
    hours_worked = john_hours + bill_hours;
    minutes_worked = john_minutes + bill_minutes;

    minutes_worked = ((days_worked * HOURS_IN_DAY) * MIN_IN_HOUR) + (hours_worked * MIN_IN_HOUR) + minutes_worked;

    days_worked = minutes_worked / MIN_IN_DAY;
    minutes_worked = minutes_worked % MIN_IN_DAY;

    hours_worked = minutes_worked / MIN_IN_HOUR;
    minutes_worked = minutes_worked % MIN_IN_HOUR;

    cout<<"The total time both of them worked together is: "<<days_worked<<" days, "<<hours_worked<<" hours and "<<minutes_worked<<" minutes.";

    return 0;

}