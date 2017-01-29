#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>  
using namespace std;

int main()
{
    srand (time(NULL));
    int number = rand() % 100 + 1; 
    int guess = -1;
    int trycount = 8;
    bool isNumber = false;
    bool win = false;
    string input = "";

    cout << "Guess a Number! Any Number!" << endl;
    while(guess != number && trycount > 0){
        cin >> input;
        while(isNumber == false){
            if(input.length() == 1){
                if(!isdigit(input[0])){
                        cout << "please enter a number: ";
                        cin >> input;
                }else{
                    isNumber = true;
                }
            }
            else if(input.length() > 1){
                int check = input.length();
                for(int i = 0; i < input.length(); i++){
                    if(!isdigit(input[i])){
                        check--;
                        cout << "please enter a number: ";
                        cin >> input;
                    }
                }
                if(check == input.length())
                    //cout << check <<" z ";
                    isNumber = true;
            }
        }
        int in = atoi(input.c_str());
        guess = in; 

        if(guess < number)
            cout << "Too low" << endl;

        if (guess > number)
            cout << "Too high" << endl;

        trycount--;

        if(trycount > 1)
            cout << "You have " << trycount << " guesses left!!" << endl;
        else if(trycount == 1)
            cout << "You have " << trycount << " guess left!!" << endl;
    }

    if(guess==number){
        cout << "You guessed the number" << endl;
        win = true;
    }
    if (trycount == 0)
        cout << "You ran out of guesses :( " << endl;

    if(!win)
        cout << "The number was " << number << "! " << endl << "game over" << endl;
    else
        cout << "gg" << endl;
        
    cout << "press Q to quit" << endl;
    string quit = "";
    while(quit != "q" && quit != "Q")
        cin >> quit;
    0;
}
