#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string inputString ="";
bool done = false;
char doneChar;
double length, width, area;

double CalculateArea(double length, double width)  //  This has to be declared before the main() method.
{
	return length*width;
}

int main()
{
	while(!done)
	{
		cout << "Welcome to the area calculator." << endl <<  "Please enter any length unit (plural is preferred): " << endl;
		getline(cin, inputString);
		std::transform(inputString.begin(),inputString.end(),inputString.begin(), ::tolower);
		cout << "Please enter the length in " << inputString << ": " << endl;
		cin >> length;
		cout << "Please enter the width: " << endl;
		cin >> width;
		cin.get();  //  strip the eol character.  Doesn't work right without this.
		area = CalculateArea(length, width);  // call the area calculator function
		cout << "The area is: " << area << " square " << inputString << "." << endl;
		cout << "Would you like to try again?" << endl;
		doneChar = cin.get();
		cin.get();  //  strip the eol character.  Seems to be needed whenever the next cin is a char or string. 
					// According to StackExchange this is because I am using get() or getline().  Not needed
					// if using cin >> .
		if(toupper(doneChar) == 'Y'){done = false;}
		else{done = true;}  // default is done.
	}
}


