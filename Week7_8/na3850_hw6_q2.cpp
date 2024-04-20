#include<iostream>
using namespace std;

void printShiftedTriangle(int rows, int shift, char symbol);
void printPineTree(int n, char symbol);

int main()
{
    int segments;
    char symbol;

    cout<<"Enter segments"<<endl;
    cin>>segments;
    cout<<"Enter symbol"<<endl;
    cin>>symbol;

    printPineTree(segments, symbol);

    return 0;
}

void printPineTree(int segments, char symbol)
{
    for(int i = 2; i <= segments + 1; i++)
        printShiftedTriangle(i, segments - (i - 1), symbol);

}

void printShiftedTriangle(int rows, int shift, char symbol)
{
    for(int i = 1; i <= rows; i++)
    {
        for(int j = 1; j <= shift; j++)
            cout<<" ";
        for(int j = i; j < rows; j++)
            cout<<" ";
        for(int j = 1; j <= (2 * i) - 1; j++)
            cout<<symbol;

    cout<<endl;
    }
    
}
