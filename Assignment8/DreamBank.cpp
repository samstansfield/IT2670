#include <iostream>


using namespace std;

class  BankAccount
{
	private:
		double balance = 100.;  // all class variables are private, the default balance is $100.
		std::string toString() const; //  no reason for this to be public.  
	public:
		BankAccount(){};
		BankAccount(double balance);  //  use this constructor for a different starting value.
		~BankAccount(){};  // deconstructor
		std::string getBalance() const;
		void setBalance(double newBalance);
		void print();
};
/*  
I think it's rather annoying that the default precision on the to_string(double) method defaults to six decimal
places and can't be changed.  The precision on the output string can be changed by using the stringstream header 
but that solution no longer uses the to_string(double) method which was required in the brief for the assignment.
*/
std::string BankAccount::toString() const 
{
	return to_string(balance);
}

BankAccount::BankAccount(double balance)  //  use this constructor for a different starting value.
{
	this->balance = balance;
}

std::string BankAccount::getBalance() const
{
	return toString();
}
void BankAccount::setBalance(double newBalance)
{
	this->balance = newBalance;
	return;
}
void BankAccount::print()
{
	cout << "The balance is: $" << (BankAccount::toString()) << endl;
}
int main()
{
	double newBalance;
	BankAccount* myAccount = new BankAccount();
	cout << "Welcome to the Dream Bank!  " ;
	myAccount->print();
	cout << "Please enter a new balance: $";
	cin >> newBalance;
	myAccount->setBalance(newBalance);
	cout << "The new balance is: " << (myAccount->getBalance()) << " THANK YOU!" << endl;
	
}