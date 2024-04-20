#include <iostream>
#include <cstdlib>
#include <cctype>
#include <vector>

using namespace std;

class Money
{
public:
    friend Money operator +(const Money& amount1, const Money& amount2);
    //Returns the sum of the values of amount1 and amount2.

    friend Money operator -(const Money& amount1, const Money& amount2);
    //Returns amount 1 minus amount2.

    friend Money operator -(const Money& amount);
    //Returns the negative of the value of amount.

    friend bool operator ==(const Money& amount1, const Money& amount2);
    //Returns true if amount1 and amount2 have the same value; false otherwise.

    friend bool operator < (const Money& amount1, const Money& amount2);
    //Returns true if amount1 is less than amount2; false otherwise.

    friend Money add(Money amount1, Money amount2);

    Money(long dollars, int cents);
    //Initializes the object so its value represents an amount with
    //the dollars and cents given by the arguments. If the amount
    //is negative, then both dollars and cents should be negative.

    Money(long dollars);
    //Initializes the object so its value represents $dollars.00.

    Money( );
    //Initializes the object so its value represents $0.00.


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
};

Money::Money(long dollars, int cents)
{
    if(dollars*cents < 0) //If one is negative and one is positive
    {
        cout << "Illegal values for dollars and cents.\n";
        exit(1);
    }
    all_cents = dollars*100 + cents;
}

Money::Money(long dollars) : all_cents(dollars*100)
{
    //Body intentionally blank.
}

Money::Money( ) : all_cents(0)
{
    //Body intentionally blank.
}

Money operator +(const Money& amount1, const Money& amount2)
{
    Money temp;
    temp.all_cents = amount1.all_cents + amount2.all_cents;
    return temp;
}

bool operator ==(const Money& amount1, const Money& amount2)
{
    return (amount1.all_cents == amount2.all_cents);
}

Money operator -(const Money& amount1, const Money& amount2)
{
    Money temp;
    temp.all_cents = amount1.all_cents - amount2.all_cents;
    return temp;
}

Money operator -(const Money& amount)
{
    Money temp;
    temp.all_cents = -amount.all_cents;
    return temp;
}

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


bool operator < (const Money& amount1, const Money& amount2)
{
    return (amount1.all_cents < amount2.all_cents);
}

class Check {
public:

   //set up constructors for Check Class
    Check();
    Check(int checkNum, long dollars, int cents, bool checkCash);
    Check(int checkNum, long dollars, bool checkCash);

    //Set up accessors
    int getCheckNum() const;
    bool isCheckCashed() const;
    Money getAmount() const;

    //Set up mutators
    void setCheckNum(int newCheckNum);
    void setCheckCashed(bool newCheckCash);
    void setAmount(long dollars, int cents);

    //set up input and output

    friend istream& operator>>(istream& ins, Check& check);

    friend ostream& operator<<(ostream& outs, const Check& check);

private:
    int checkNum;
    Money checkAmt;
    bool checkCash;
};

istream& operator>>(istream& ins, Check& check) {
    ins >> check.checkNum;
    ins >> check.checkAmt;
    ins >> check.checkCash;
    return ins;
}

ostream& operator<<(ostream& outs, const Check& check) {
    outs << "Check Number: " << check.checkNum << endl
         << "Amount: " << check.checkAmt << endl
         << "Cashed: " << (check.checkCash ? "Yes" : "No");
    return outs;
}
// Member functions for construction and initialization

Check::Check()
{
//left blank
}
Check::Check(int checkNum, long dollars, int cents, bool checkCash) : checkAmt(dollars, cents), checkNum(checkNum), checkCash(checkCash)
{
//left blank
}
Check::Check(int checkNum, long dollars, bool checkCash) : checkAmt(dollars), checkNum(checkNum), checkCash(checkCash)
{
//left blank
}

// Accessor functions

int Check::getCheckNum() const
{
    return checkNum;
}

bool Check::isCheckCashed() const
{
    return checkCash;
}

Money Check::getAmount() const
{
    return checkAmt;
}

// Mutator Functions

void Check::setCheckNum(int newCheckNum)
{
    checkNum = newCheckNum;
}

void Check::setCheckCashed(bool newCheckCash)
{
    checkCash = newCheckCash;
}

void Check::setAmount(long dollars, int cents)
{
    dollars = dollars*100 + cents;
}

void checkSort(vector<Check> &checks) {
    for (int i = 0; i < checks.size(); ++i) {
        for (int j = 0; j < checks.size() - i - 1; ++j) {
            if (checks[j].getCheckNum() > checks[j+1].getCheckNum()) {
                Check temp = checks[j];
                checks[j] = checks[j+1];
                checks[j + 1] = temp;
            }
        }
    }
}

int main() {
    vector<Check> depositedChecks;
    vector<Money> deposits;
    Money tempDeposit;
    Money sumOfCashedChecks(0,0), sumOfUncashed(0,0);
    Check tempCheck;
    Money priorBalance, accountBalance;

    cout << "Please enter the check number, amount on check (with the dollar sign) and whether or not the check has been cashed(by typing 1(Yes) or 0(No):"<<endl<<endl;

    cout << "Example input: 9 for check number, $40.89 for amount and 1 for being cashed (9 $40.89 1)"<<endl;
    cout << "End output by entering 0 for check number, $0.00 for amount and 0 for being cashed (0 $0.00 0)"<<endl<<endl;

    while (true) {
        cin >> tempCheck;
        if (tempCheck.getCheckNum() == 0) {
            break;
        }
        depositedChecks.push_back(tempCheck);
    }

    checkSort(depositedChecks);

    for(const Check& check : depositedChecks) {
        if(check.isCheckCashed()) {
            sumOfCashedChecks = sumOfCashedChecks + check.getAmount();
        }
        else {
            sumOfUncashed = sumOfUncashed + check.getAmount();
        }
    }

    cout<<"The sum of the cashed checks is: "<<endl;
    cout<<sumOfCashedChecks << endl;

    cout<<"The sum of the un-cashed checks is: "<<endl;
    cout<<sumOfUncashed<<endl;

    cout<<"Please enter the deposits (end deposit input by typing $0.00):"<<endl;

    while (true) {
        cin >> tempDeposit;
        if (tempDeposit == 0.00) {
            break;
        }
        deposits.push_back(tempDeposit);
    }

    Money sumDeposits = 0;

    for(int i = 0; i < deposits.size(); i++) {
        sumDeposits = sumDeposits + deposits[i];
    }

    cout<<"The sum of the deposits is: "<<endl;
    cout<<sumDeposits<<endl;

    cout<<"Please enter the prior balance amount: "<<endl;
    cin>>priorBalance;

    cout<<"Please enter the new balance amount according to account holder:"<<endl;
    cin>>accountBalance;

    cout<<endl;
    Money bankBalance = (priorBalance - sumOfCashedChecks) + sumDeposits;


    cout<<"The balance according to the bank which includes only cleared checks is: "<<bankBalance<<endl;
    cout<<"The difference between the account holders balance of "<<accountBalance<<" and bank balance of "<<bankBalance<<" is: "<<bankBalance - accountBalance<<endl;
    cout<<endl;

    cout<<"The cashed checks are:"<<endl;

    for(const Check& check : depositedChecks) {
        if(check.isCheckCashed()) {
            cout<<"Check number: "<<check.getCheckNum()<<" with amount: "<<check.getAmount()<<endl;
        }
    }

    cout<<endl;

    cout<<"The un-cashed checks are:"<<endl;
    for(const Check& check : depositedChecks) {
        if(!check.isCheckCashed()) {
            cout<<"Check number: "<<check.getCheckNum()<<" with amount: "<<check.getAmount()<<endl;
        }
    }

    return 0;
}