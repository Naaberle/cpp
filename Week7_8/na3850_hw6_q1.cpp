#include<iostream>
using namespace std;

int fib(int n);

int main()
{
    int element;

    cout<<"Please enter a positive integer: ";
    cin>>element;

    cout<<fib(element);

    return 0;
}

int fib(int n)
{
    int f1 = 1;
    int f2 = 1;
    int sum = 0;

    if(n == 1 || n == 2)
        sum = 1;
    else  
    {  
        for(int i = 1; i <= n - 2; i++)
        {
            sum = f1 + f2;
            f1 = f2;
            f2 = sum;
        }
    }
    return sum;
}