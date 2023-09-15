#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    int targetNumber, userGuess, numberOfTries = 0;
    srand(time(0)); // Seed the random number generator
    targetNumber = rand() % 100 + 1; // Generate a random number between 1 and 100
    cout << "Guess My Number Game\n\n";

    do
    {
        cout << "Enter a guess between 1 and 100: ";
        cin >> userGuess;
        numberOfTries++;

        if (userGuess > targetNumber)
            cout << "Too high!\n\n";
        else if (userGuess < targetNumber)
            cout << "Too low!\n\n";
        else
            cout << "\nCorrect! You got it in " << numberOfTries << " guesses!\n";
    } while (userGuess != targetNumber);

    return 0;
}
