//File Name: na3850_hw7_q1.cpp
//Author: Nik Aberle
//Email Address: na3850@nyu.edu
//Assignment Number: Week 9 - HW7 - Q1
//Description: Program to print out a calendar for a full year.
//Last Change: 3/1/2024

#include<iostream>
#include<string>
using namespace std;

const int JANUARY = 31;
const int FEBRUARY = 28;
const int MARCH = 31;
const int APRIL = 30;
const int MAY = 31;
const int JUNE = 30;
const int JULY = 31;
const int AUGUST = 31;
const int SEPTEMBER = 30;
const int OCTOBER = 31;
const int NOVEMBER = 30;
const int DECEMBER = 31;
const int MONTHS = 12;

int printMonthCalendar(int numOfDays, int startingDay);
bool checkLeap(int year);
void printYearCalendar(int year, int startingDay);

int main()
{
    int year;
    int startingDay;

    cout<<"Please enter the year for the calendar you'd like to see: ";
    cin>>year;
    cout<<endl;

    cout<<"With 1 representing Monday and 7 representing Sunday, please enter 1 - 7 for what day 1/1 falls on for the above year: ";
    cin>>startingDay;
    cout<<endl;

    printYearCalendar(year, startingDay);

    return 0;
}

int printMonthCalendar(int numOfDays, int startingDay)
{
    int dayOfMonth = 1;
    int weeklyCounter = 1;
    int endDay = (numOfDays + startingDay) - 1;
    string daysOfWeek = "Mon\tTue\tWed\tThr\tFri\tSat\tSun\n";

    cout<<daysOfWeek;

    for(int i = 1; i < startingDay + numOfDays; i++)
    {   
        while(startingDay > 1)
        {
            cout<<" \t";
            startingDay--;
            weeklyCounter++;
        } 

        cout<<dayOfMonth<<"\t";
        weeklyCounter++;
        dayOfMonth++;
        
        if (weeklyCounter > 7 && dayOfMonth < (numOfDays + startingDay))
        {
            cout<<"\n";
            weeklyCounter = 1;
        }

    }

    cout<<endl;
    if(endDay % 7 == 0)
    {
        return 1;
    }
    else
    {
        return (endDay % 7) + 1;
    }
}

bool checkLeap(int year)
{
    if(year % 4 == 0)
    {
        if(year % 100 == 0 && year % 400 != 0)
            return false;
        else
            return true;    
    }
    else
        return false;
}

void printYearCalendar(int year, int startingDay)
{
    int firstDay = startingDay;

    for(int month = 1; month <= MONTHS; month++)
    {
        switch(month)
        {
            case 1:
                cout<<"January "<<year<<endl;
                firstDay = printMonthCalendar(JANUARY, firstDay);
                cout<<endl;
                break;
            case 2:
                cout<<"February "<<year<<endl;
                if(checkLeap(year)) {
                    firstDay = printMonthCalendar(FEBRUARY + 1, firstDay);
                    cout<<endl;
                }
                else {
                    firstDay = printMonthCalendar(FEBRUARY, firstDay);
                    cout<<endl;
                }
                break;
            case 3:
                cout<<"March "<<year<<endl;
                firstDay = printMonthCalendar(MARCH, firstDay);
                cout<<endl;
                break;
            case 4:
                cout<<"April "<<year<<endl;
                firstDay = printMonthCalendar(APRIL, firstDay);
                cout<<endl;
                break;
            case 5:
                cout<<"May "<<year<<endl;
                firstDay = printMonthCalendar(MAY, firstDay);
                cout<<endl;
                break;
            case 6:
                cout<<"June "<<year<<endl;
                firstDay = printMonthCalendar(JUNE, firstDay);
                cout<<endl;
                break;
            case 7:
                cout<<"July "<<year<<endl;
                firstDay = printMonthCalendar(JULY, firstDay);
                cout<<endl;
                break;
            case 8:
                cout<<"August "<<year<<endl;
                firstDay = printMonthCalendar(AUGUST, firstDay);
                cout<<endl;
                break;
            case 9:
                cout<<"September "<<year<<endl;
                firstDay = printMonthCalendar(SEPTEMBER, firstDay);
                cout<<endl;
                break;
            case 10:
                cout<<"October "<<year<<endl;
                firstDay = printMonthCalendar(OCTOBER, firstDay);
                cout<<endl;
                break;
            case 11:
                cout<<"November "<<year<<endl;
                firstDay = printMonthCalendar(NOVEMBER, firstDay);
                cout<<endl;
                break;
            case 12:
                cout<<"December "<<year<<endl;
                firstDay = printMonthCalendar(DECEMBER, firstDay);
                cout<<endl;
                break;
        }
    }
}