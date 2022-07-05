#include <iostream>

using namespace std;

int main()
{
	int age;
	double health;
	string name;
	cout << "Please input your character's name." << endl;
	getline(cin,name);
	cout << "Please input your character's age." << endl;
	cin >> age;
	cout << "Please input your character's health." << endl;
	cin >> health;
	cout << "Your character's name is: " << name << endl
    	 << "Your character's age is: " << age << endl
		 << "Your character's health is: " << health << endl;
	return 0;
}