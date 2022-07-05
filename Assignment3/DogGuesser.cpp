#include <iostream>

using namespace std;

string size, hairLength, doneString;
int sizeInt, hairInt, index;
bool done = false;

int main()
{
	while(!done)
	{
		cout << "Is it a big or a small dog?" << endl;
		getline(cin, size);
		if(size[0] == 'b' || size[0] == 'B'){sizeInt = 0;}
		else if(size[0] == 's' || size[0] == 'S'){sizeInt = 1;}
		else
		{
			cout << "Please try again! Must enter small or big" << endl;
			continue;
		}
		cout << "Is it long or short haired?" << endl;
		getline(cin, hairLength);
		if(hairLength[0] == 'l' || hairLength[0] == 'L'){hairInt = 0;}
		else if(hairLength[0] == 's' || hairLength[0] == 'S'){hairInt = 1;}
		else
		{
			cout << "Please try again! Must enter short or long" << endl;
			continue;
		}
	/* The value of index is between 0 and 3 depending on which dog is the result */
		index = 2*sizeInt + hairInt;
		
		switch(index)
		{
			case 0:
				cout <<  "The dog is an Irish Wolfhound" << endl;
				break;
			case 1:
				cout <<  "The dog is a Great Dane" << endl;
				break;
			case 2:
				cout <<  "The dog is a Yorkshire Terrier" << endl;
				break;
			case 3:
				cout <<  "The dog is a Chihuahua" << endl;
				break;	
		}
		cout <<  "Would you like to try again?" << endl;
		getline(cin, doneString);
		if(doneString[0] == 'y' || doneString[0] == 'Y'){done = false;}
		else if(doneString[0] == 'n' || doneString[0] == 'N'){done = true;}
		else {return EXIT_FAILURE;}
	}
}