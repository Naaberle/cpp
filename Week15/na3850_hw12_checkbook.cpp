//File Name: na3850_hw12_checkbook.cpp
//Author: Nik Aberle
//Email Address: na3850@nyu.edu
//Assignment Number: Week 15 - HW12 - Checkbook
//Description: Checkbook balancing program
//Last Change: 4/13/2024

#include <iostream>
#include <vector>
using namespace std;


class Money
{
public:
    friend class Check;

    friend Money operator +(const Money& amount1, const Money& amount2)     //Returns the sum of the values of amount1 and amount2.
    {
        Money temp;
        temp.all_cents = amount1.all_cents + amount2.all_cents;
        return temp;
    }

    friend Money operator -(const Money& amount1, const Money& amount2)     //Returns amount 1 minus amount2.
    {
        Money temp;
        temp.all_cents = amount1.all_cents - amount2.all_cents;
        return temp;
    }

    friend Money operator -(const Money& amount)                            //Returns the negative of the value of amount.
    {
        Money temp;
        temp.all_cents = -amount.all_cents;
        return temp;
    }

    friend bool operator ==(const Money& amount1, const Money& amount2)     //Returns true if amount1 and amount2 have the same value; false otherwise.
    {
        return (amount1.all_cents == amount2.all_cents);
    }

    friend bool operator < (const Money& amount1, const Money& amount2)     //Returns true if amount1 is less than amount2; false otherwise.
    {
        return (amount1.all_cents < amount2.all_cents);
    }

    Money(long dollars, int cents)
    {
        if(dollars*cents < 0) //If one is negative and one is positive
        {
            cout << "Illegal values for dollars and cents.\n";
            exit(1);
        }
        all_cents = dollars*100 + cents;
    }
    //Initializes the object so its value represents an amount with
    //the dollars and cents given by the arguments. If the amount
    //is negative, then both dollars and cents should be negative.

    Money(long dollars) : all_cents(dollars * 100) {}                        //Initializes the object so its value represents $dollars.00.
    
    Money( ) : all_cents(0) {}                                               //Initializes the object so its value represents $0.00.
    
    double get_value( ) const                                                //Returns the amount of money recorded in the data portion of the calling object.
    {
        return (all_cents * 0.01);
    }

    friend istream& operator >>(istream& ins, Money& amount);
    //Overloads the >> operator so it can be used to input values of type
    //Money. Notation for inputting negative amounts is as in -$100.00.
    //Precondition: If ins is a file input stream, then ins has already been
    //connected to a file.

    friend ostream& operator <<(ostream& outs, const Money& amount);
    //Overloads the << operator so it can be used to output values of type
    //Money. Precedes each output value of type Money with a dollar sign.
    //Precondition: If outs is a file output stream, then outs has already been
    //connected to a file.

private:
    long all_cents;
    long dollars;
    int cents;
};

class Check
{
private:
    int checkNumber;
    Money checkAmount;
    bool cashed;

public:
    friend class Money;

    Check(int checkNumber, long dollars, int cents, bool cashed) 
    : checkNumber(checkNumber), checkAmount(dollars, cents), cashed(cashed) {}



//The class for a check should have accessor and mutator
//functions as well as constructors and functions for both input and output of a check. 

};

int digit_to_int(char c)
{
    return ( static_cast<int>(c) - static_cast<int>('0') );
}

istream& operator >>(istream& ins, Money& amount)
{
    char one_char, decimal_point,
         digit1, digit2; //digits for the amount of cents
    long dollars;
    int cents;
    bool negative;//set to true if input is negative.

    ins >> one_char;
    if (one_char == '-')
    {
        negative = true;
        ins >> one_char; //read '$'
    }
    else
        negative = false;
    //if input is legal, then one_char == '$'

    ins >> dollars >> decimal_point >> digit1 >> digit2;

    if ( one_char != '$' || decimal_point != '.'
         || !isdigit(digit1) || !isdigit(digit2) )
    {
        cout << "Error illegal form for money input\n";
        exit(1);
    }

    cents = digit_to_int(digit1)*10 + digit_to_int(digit2);

    amount.all_cents = dollars*100 + cents;
    if (negative)
        amount.all_cents = -amount.all_cents;

return ins;
}

ostream& operator <<(ostream& outs, const Money& amount)
{
    long positive_cents, dollars, cents;
    positive_cents = labs(amount.all_cents);
    dollars = positive_cents/100;
    cents = positive_cents%100;

    if (amount.all_cents < 0)
        outs << "-$" << dollars << '.';
    else
        outs << "$" << dollars << '.';

    if (cents < 10)
        outs << '0';
    outs << cents;

    return outs;
}

//Read in a series of check given their number, amount, and whether or not they've been cashed.
//Will output the total of the checks cashed, the total of deposits, what the new balance should be
//and how much this figure differs from what the bank says the new balance is.
//Will also output two lists of check, those cashed since the last time it was balanced and those still not cashed.

int main( )
{
    vector<Check> depositedChecks;
    int checkNumber;
    Money checkAmount;
    bool cashed;

    Check check1(1, 1, 1, 1);

    /* cout<<"Please enter the check number, amount on check [exclude the dollar sign] and whether or not";
    cout<<" the check has been cashed (by typing 1(Yes) or 0(No): "<<endl<<endl;

    cout<<"Example input: 9 for the check number, 40.89 for amount and 1 for being cashed (9 40.89 1)"<<endl;
    cout<<"End output by entering 0 for check number, 0.00 for amount and 0 for being cashed (0 0.00 0)"<<endl<<endl; */




    return 0;
}


/* 
    Money amount[5], max;
    int i;

    cout << "Enter 5 amounts of money:\n";
    cin >> amount[0];
    max = amount[0];
    for (i = 1; i < 5; i++)
    {
        cin >> amount[i];
        if (max < amount[i])
            max = amount[i];
        //max is the largest of amount[0],..., amount[i].
    }

    Money difference[5];
    for (i = 0; i < 5; i++)
        difference[i] = max - amount[i];

    cout << "The highest amount is " << max << endl;
    cout << "The amounts and their\n"
         << "differences from the largest are:\n";

    for (i = 0; i < 5; i++)
    {
        cout << amount[i] << " off by "
             << difference[i] << endl;
    } */

//