#include<iostream>
#include<string>
#include<vector>
using namespace std;

int countSpaces(string userInput);

int main()
{
    string lineOfText;

    cout<<"Please enter a line of text: "<<endl;
    getline(cin, lineOfText);

    int spaces = countSpaces(lineOfText);
    
    vector<string> words(spaces);

    for(int i = 0; i < spaces; i++)
        cout<<words.size()<<endl;
    
    return 0;
}

int countSpaces(string userInput)
{
    int spaces = 0;

    for(int i = 0; i < userInput.length(); i++)
    {
        if(userInput[i] == 32)
            spaces++;
    }
    return spaces;
}


//My userID is john17 and my 4 digit pin is 1234 which is secret