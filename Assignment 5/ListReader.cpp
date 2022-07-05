#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string inputString ="";
bool done = false;
int listNum;
char doneChar;

int main()
{
	string listArray[3][5]  {  {"Milk", "Eggs", "Bread", "Butter", "Ketchup"},
					{"Mow", "Paint", "Weed Garden", "Shop", "Fix Car"},
					{"Tom","Mary","Lee","Ahmad","Rose"}};
	while(!done)
	{
		cout << "Welcome to the list reader.  There are three lists, Shopping, ToDo and Friends.  Which would you like to read?" << endl; 
		getline(cin, inputString);
		std::transform(inputString.begin(),inputString.end(),inputString.begin(), ::toupper);  //  converts entire input string to upper case.
		if(inputString == "SHOPPING"){listNum = 0;}
		else if(inputString == "TODO"){listNum = 1;}
		else if(inputString == "FRIENDS"){listNum = 2;}
		else {listNum =3;}
		if(listNum == 3)
		{
			cout << endl;
			cout << "I don't have that kind of list"  << endl;
		}
		else
		{
			cout << endl;  //  Print a blank line before output.
			for(int i =0;i<5;i++)
			{
				cout << listArray[listNum][i] << endl;
			}
		}
		cout << endl;
		cout << "Would you like to see another list?" << endl;
		doneChar = cin.get();
		cin.get();  //  strip the eol character.
		if(toupper(doneChar) == 'Y'){done = false;}
		else{done = true;}  // default is done.
	}  //  end of while loop
}