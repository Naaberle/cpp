#include<iostream>
using namespace std;

int main()
{
    double value1, value2;

    cout<<"Please enter two positive integers, separated by a space: \n";
    cin>>value1>>value2;
    cout<<value1<<" + "<<value2<<" = "<<value1 + value2<<endl;
    cout<<value1<<" - "<<value2<<" = "<<value1 - value2<<endl;
    cout<<value1<<" * "<<value2<<" = "<<value1 * value2<<endl;
    cout<<value1<<" / "<<value2<<" = "<<(double)value1 / (double)value2<<endl;
    cout<<value1<<" div "<<value2<<" = "<<(int)value1 / (int)value2<<endl;
    cout<<value1<<" mod "<<value2<<" = "<<(int)value1 % (int)value2<<endl;
    
    return 0;

}