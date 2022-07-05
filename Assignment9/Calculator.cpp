#include <iostream>
#include <string>
#include <cmath>

using namespace std;


/*
Here is the Calculator super class.  I did set up accessors and mutators but don't actually need them.  
The destructor must be virtual.  
*/
class Calculator
{
	protected:  //  These all need to be accessed from the subclasses but not externally.
		double x,y;
		double getx() const;
		double gety() const;
		void setx(double x);
		void sety(double y);
		Calculator(){};
		Calculator(double x, double y);
		virtual ~Calculator(){};
};
double Calculator::getx() const
{
	return this->x;
}
double Calculator::gety() const
{
	return this->y;
}
void Calculator::setx(double x)
{
	this->x = x;
	return;
}
void Calculator::sety(double y)
{
	this->y = y;
	return;
}

Calculator::Calculator(double x, double y)
{
	this->x = x;
	this->y = y;
}

/*  
All four of the "operations" subclasses do basically the same thing.  The 
constructor creates an instance of the Calculator class for the current subclass 
to be a subclass of.  The construction of the instance of the subclass includes 
calculating the result of the operation.  In general I prefer to separate the 
definitions from the declarations.

This program interests me because I have worked with Finite Fields in the past.
They are important in cryptography (and other more obscure areas of mathematics.)  
One could define a Finite Field as a subclass of a Calculator with each of the 
field operations as subclasses of these operations.  Thus, a virtual destructor 
in all of them.  (The downside of doing it that way is that the whole thing would
have to be constructed every time an operation is performed.  This can be time 
consuming for large fields.  Addition tables are generally easy but multiplication
tables can be non-trivial and depend on a polynomial which is somewhat arbitrary.)
If I were going to create a FiniteField class, I would not do it this way.
*/
// ................................................................
class Add : public Calculator  // Addition
{
	private: 
		double sum;
	public: 
		Add(double x, double y);
		
		double getSum() const;
		void setSum();
		virtual ~Add(){};
};
Add::Add(double x, double y) : Calculator(x, y)
{
	this->sum = x+y;
};
double Add::getSum() const
{
	return this->sum;
}
void Add::setSum()
{
	this->sum = (this->x) + (this->y);
	return;
}
// ................................................................
class Sub : public Calculator  // Subtraction
{
	private: 
		double diff;
	public: 
		
		Sub(double x, double y);
		double getDiff() const;
		void setDiff();
		virtual ~Sub(){};
};
Sub::Sub(double x, double y) : Calculator(x, y)
{
	this->diff = x-y;
}
double Sub::getDiff() const
{
	return this->diff;
}
void Sub::setDiff()
{
	this->diff = (this->x) - (this->y);
	return;
}
// ................................................................
class Mult : public Calculator //  Multiplication.
{
	private: 
		double prod;
	public: 
		
		Mult(double x, double y);
		double getProd() const;
		void setProd();
		virtual ~Mult(){};
};
Mult::Mult(double x, double y) : Calculator(x, y)
{
	this->prod = x*y;
}
double Mult::getProd() const
{
	return this->prod;
}
void Mult::setProd()
{
	this->prod = (this->x) * (this->y);
	return;
}
// ................................................................
class Div : public Calculator  // Division
{
private: 
		double quot;
	public: 
		
		Div(double x, double y);
		double getQuot() const;
		void setQuot();
		virtual ~Div(){};
};
Div::Div(double x, double y) : Calculator(x, y)
{
	this->setQuot();
}
double Div::getQuot() const
{
	return this->quot;
}
void Div::setQuot()
{
	if((this->y) == 0.0)  //  catch a divide by zero error.
	{
		cout << "No division by zero" << endl;
		this->quot = INFINITY;
		return ;
	}
	else
	{
		this->quot = (this->x)/(this->y);
		return;
	}
	
}

int main()
{
	double x,y;
	bool done = false;
	char doneChar,opChar;
	while (!done)
	{
		cout << "Please input the first number: ";
		cin >> x;
		cout << "Please enter the second number: ";
		cin >> y;
		cin.get();  // have to strip the eol from the input stream.
		cout << "Which operation would you like?"  << endl <<  "Add, Subtract, Multiply and Divide are available. ";
		cin >> opChar;
		cin.get();
		opChar = toupper(opChar);
		switch(opChar)
		{
			case 'A':
				{
					Add* thisSum = new Add(x,y);
					cout << "The Sum is: " << thisSum->getSum() << endl;
					break;
				}
			case 'S':
				{
					Sub* thisDiff = new Sub(x,y);
					cout << "The Difference is: " << thisDiff->getDiff() << endl;
					break;
				}
			case 'M':
				{
					Mult* thisProd = new Mult(x,y);
					cout << "The Product is: " << thisProd->getProd() << endl;
					break;
				}
			case 'D':
				{
					Div* thisQuot = new Div(x,y);
					cout << "The Quotient is: " << thisQuot->getQuot() << endl;
					break;
				}
			default:
				{	
					cout << "I don't recognize that operation." << endl;
					break;
				}
		}
		cout << "Would you like to try again? (Yes or No) " << endl;
		doneChar = cin.get();
		if(toupper(doneChar) == 'Y'){done = false;}
		else{done = true;}  // default is done.
		
	}
}
/*
What follows is the test program I used to debug the classes.  It
inputs two numbers and does all four operations.

int main()
{
	double x,y;
	bool done = false;
	char doneChar;
	while (!done)
	{
		cout << "Please input the first number: ";
		cin >> x;
		cout << "Please enter the second number: ";
		cin >> y;
		cin.get();
		Add* thisSum = new Add(x,y);
		cout << "The Sum is: " << thisSum->getSum() << endl;
		Sub* thisDiff = new Sub(x,y);
		cout << "The Difference is: " << thisDiff->getDiff() << endl;
		Mult* thisProd = new Mult(x,y);
		cout << "The Product is: " << thisProd->getProd() << endl;
		Div* thisQuot = new Div(x,y);
		cout << "The Quotient is: " << thisQuot->getQuot() << endl;
		cout << "Would you like to try again? (Y or N) " << endl;
		doneChar = cin.get();
		if(toupper(doneChar) == 'Y'){done = false;}
		else{done = true;}  // default is done.
		
	}
}
*/