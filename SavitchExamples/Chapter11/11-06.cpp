//DISPLAY 11.6 Overloading a Unary Operator
//Class for amounts of money in U.S. currency.
class Money
{
public:
    friend Money operator +(const Money& amount1, const Money& amount2);

    friend Money operator -(const Money& amount1, const Money& amount2);
    //Precondition: amount1 and amount2 have been given values.
    //Returns amount 1 minus amount2.

    friend Money operator -(const Money& amount);
    //Precondition: amount has been given a value.
    //Returns the negative of the value of amount.

    friend bool operator ==(const Money& amount1, const Money& amount2);

    Money(long dollars, int cents);

    Money(long dollars);

    Money( );

    double get_value( ) const;

    void input(istream& ins);
    void output(ostream& outs) const;
private:
    long all_cents;
};

  //Any additional function declarations as well as the main part of the program go here.

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
           //The other function definitions are the same as in Display 11.5.
