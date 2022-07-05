#include <iostream>
#include <cstdlib>

using namespace std;

string inString;
bool doneGuessing = false;
int key, guess;
int main()
{
	
	int elapsedSeconds = time(nullptr);
	srand(elapsedSeconds);  // seed the random number generator.
	key = (rand() % 100) + 1;  //  get the number to guess.

	while(!doneGuessing)
	{
		
		cout << "Please guess a number between 1 and 100." << endl;
		cin >> guess;
		cout << "The new guess is " << guess << endl;
		if(guess == key)
		{ 
			cout <<  "Congratulations!  The key was " << key  << endl;
			doneGuessing = true;
			return EXIT_SUCCESS;
		}
		else
		{
			cout << "Sorry, wrong number.  Would you like to try another guess?  (Y or N)" << endl;
			cin >> inString;
			if(inString[0] == 'y' || inString[0] == 'Y')
			{
				doneGuessing = false;
			}
			else if(inString[0] == 'n' || inString[0] == 'N')
			{
				doneGuessing = true; 
				cout << "The Correct answer is " << key <<endl;
			}
			else return EXIT_FAILURE;
		}
		
	}
}