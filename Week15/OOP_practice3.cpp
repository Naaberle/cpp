#include<iostream>
using namespace std;

class Money
{

private:
    int dollars;
    int cents;

public:

    Money(int d, int c) : dollars(d), cents(c) {}

    int getDollars() const
    {
        return dollars;
    }

    int getCents() const
    {
        return cents;
    }

    void printValue()
    {
        cout<<"You have $"<<dollars<<"."<<cents<<" in your account"<<endl;
    }

    void deposit(int addDollar, int addCents)
    {
        int bulkCents = (addDollar * 100) + addCents + cents; // 244
        int wholeDollar = bulkCents / 100; // 2
        int remainCents = bulkCents % 100; // 

        cents = remainCents;
        dollars += wholeDollar;
    }

    void withdrawal(int takeDollars, int takeCents)
    {
        int currentTotal = (dollars * 100) + cents;
        int withdrawalTotal = (takeDollars * 100) + takeCents;

        if(withdrawalTotal > currentTotal)
            cout<<"Sorry you don't have enough funds."<<endl;
        else
        {
            if(takeCents > cents)
            {
                dollars--;
                cents += 100;
            }

            cents -= takeCents;
            dollars -= takeDollars;
        }

    }
};

int main()
{
    Money tuesday(13, 76);

    tuesday.printValue();

    cout<<endl;

    tuesday.deposit(1, 68);

    tuesday.printValue();

    cout<<endl;

    tuesday.withdrawal(100, 1);

    tuesday.printValue();

    return 0;
}

/*
Building on the concepts from the level 1 problem, a level 2 problem could incorporate more interactions with the Money class,
including using mutator functions (setters).

Level 2 Problem: Extend the Money class with mutator functions and implement basic transactions.

    Add mutator (setter) methods to the Money class that allow the user to set the dollars and cents.
    Create a method that can add to the current money amount (a deposit).
    Create a method that can subtract from the current money amount (a withdrawal), making sure the result doesn't go negative.

This problem is slightly more complex as it requires handling the internal state changes in the object, which involves more
logic (e.g., dealing with overflow from cents to dollars and ensuring the balance doesn't go negative). It's a step towards
the management of a financial balance as required in the checkbook assignment.

*/