#include <iostream>
#include <iomanip>

using namespace std;

class Car
{
	private:  // the whole point of encapsulation is that these variables are private.
		int originalPrice, age;
		
	public:
		// constructors
		Car(){}  // blank constructor
		Car(int P, int A)
		{
			this->originalPrice = P;
			this->age = A;
		}
		~Car(){} // deconstructor
	
		// accessors:
		int getAge() const {return this->age;}
		int getOriginalPrice() const {return this->originalPrice;}
	
		// mutators:
		void setAge(int A)
		{
			this->age = A;
			return;
		}
		void setOriginalPrice(int P) 
		{
			this->originalPrice = P; 
			return;
		}
	
		// the discount calculator:
		double calculateDiscountPrice() 
		{
			double doublePrice = static_cast<double>(this->getOriginalPrice());
			return (doublePrice/(this->getAge()));
		}
};
/*  
There are two different ways to accomplish the assigned task.  One is to use the 
constructor with parameters.  The other is to use the blank constructor and the set methods.
*/

int main()
{
	int originalPrice, age;
	cout << "Welcome to the car discount calculator" << endl;
	
	cout << "Please input the original price in dollars.  No decimals please. " << endl;
	cin >> originalPrice;
	cout << "Please input the age in years." << endl;
	cin >> age;
	Car* thisCar1 = new Car(originalPrice,age);  // construct an instance of the Car class.
	cout << "The discount price is (method 1): $" << fixed << setprecision(2) << (thisCar1->calculateDiscountPrice()) << endl;
	Car* thisCar2 =  new Car();
	thisCar2->setOriginalPrice(originalPrice);
	thisCar2->setAge(age);
	cout << "The discount price is (method 2): $" << fixed << setprecision(2) << (thisCar2->calculateDiscountPrice()) << endl;
}
