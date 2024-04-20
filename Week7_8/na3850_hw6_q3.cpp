#include<iostream>
using namespace std;

double eApprox(int n);

int main()
{
    cout.precision(30);

    for(int n = 1; n <= 15; n++)
    {
        cout<<"n = "<<n<<'\t'<<eApprox(n)<<endl;
    }
    
    return 0;
}

double eApprox(int n)
{
    double product = 1.0;
    double e = 1;

    for(int i = 1; i <= n; i++)
    {
        product *= i;
        e += 1 / product;
    }
    return e;
}