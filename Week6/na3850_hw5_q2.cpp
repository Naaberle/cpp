#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main()
{
    int comp_number;
    int guesses = 5, counter = 0;
    int player_guess;
    int min_range = 1, max_range = 100;
 
    srand(time(0));
    comp_number = (rand() % 100) + 1;

    cout<<"I thought of a number between 1 and 100! Try to guess it."<<endl;

    while(guesses > 0)
    {

        cout<<"Range: ["<<min_range<<", "<<max_range<<"], Number of guesses left: "<<guesses<<endl;
        cout<<"Your guess: ";
        cin>>player_guess;
        counter++;

        if(guesses > 1)
        {
            if(player_guess == comp_number)
            {
                cout<<"Congrats! You guessed my number in "<<counter<<" guesses."<<endl;
                break;
            }

            else if(player_guess < comp_number)
            {
                if(player_guess < min_range)
                {
                    cout<<"Wrong! My number is bigger."<<endl;
                    guesses--;
                }
                else
                {
                    cout<<"Wrong! My number is bigger."<<endl;
                    min_range = player_guess + 1;
                    guesses--; 
                }
            }

            else if(player_guess > comp_number)
            {
                if(player_guess > max_range)
                {
                    cout<<"Wrong! My number is smaller."<<endl;
                    guesses--;
                }
                else
                {
                    cout<<"Wrong! My number is smaller."<<endl;
                    max_range = player_guess - 1;
                    guesses--;
                }
            }
        }
        else
        {
            if(player_guess == comp_number)
            {
                cout<<"Congrats! You guessed my number in "<<counter<<" guesses."<<endl;
                break;
            }

            else 
                cout<<"Out of guesses! My number is "<<comp_number<<endl;
                guesses--;
        }

    }

    return 0;
}