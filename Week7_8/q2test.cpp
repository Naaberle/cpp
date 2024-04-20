#include<iostream>
using namespace std;

void printShiftedTriangle(int n, int m, char symbol);

int main()
{

    printShiftedTriangle(3, 5, '*');



    return 0;
}


void printShiftedTriangle(int n, int m, char symbol){
    int i, j;
    for (i = 1; i <= n; i++){
        for (j = i; j < (n + m); j++){
            cout<<"-";
        }
        for (j = i; j > 0; j--){
            cout<<symbol;
        }
        for (j = 1; j < i; j++){
            cout<<symbol;
        }
        cout<<endl;
    }
    return;
}