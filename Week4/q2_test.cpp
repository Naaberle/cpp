#include<iostream>
#include<string>
using namespace std;

int main() 
{
    int user_input;
    string holder = "";
    cout<<"Please enter a positive integer: ";
    cin>>user_input;
    while(user_input > 0)
    {
        if(user_input >= 1000)
        {
            holder += "M";
            user_input -= 1000;
        }
        else if(user_input >= 500)
        {
            holder += "D";
            user_input -= 500;
        }

        else if(user_input >= 100)
        {
            holder += "C";
            user_input -= 100;
        }
        else if(user_input >= 50)
        {
            holder += "L";
            user_input -= 50;
        }
        else if(user_input >= 10)
        {
            holder += "X";
            user_input -= 10;
        }
        else if(user_input >= 5)
        {
            holder += "V";
            user_input -= 5;
        }
        else if(user_input >= 1)
        {
            holder += "I";
            user_input -= 1;
        }
    }
    cout<<holder;
    return 0;
}
