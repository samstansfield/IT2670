#include <iostream>
#include "AreaCalculator.h"
	
using namespace std;

std::string tempString = "";
char inChar;

Shape::Shape(){};
Shape::~Shape(){};
double Shape::getArea() const
{
	return this->area;
}
void Shape::setArea(double A)
{
	this->area = A;
	return;
}
double Shape::calculateArea()
{
	return 0.0;
}
void Shape::print()
{
	cout << "Area = " << (this->getArea()) << endl;
	return;
}
Rectangle::Rectangle(double length,double width)
{
	this->length = length;
	this->width = width;
	setArea(calculateArea());
}
double Rectangle::getLength()  const
{
	return this->length;
}
double Rectangle::getWidth() const
{
	return this->width;
}
double Rectangle::calculateArea()
{
	return (this->length)*(this->width);
}
void Rectangle::setLength(double length)
{
	this->length = length;
	return;
}
void Rectangle::setWidth(double width)
{
	this->width = width;
	return;
}
void  Rectangle::print()
{
	cout << "Rectangle:  Length = " << length << ", Width = " << width << ", area = " << (this->getArea()) <<"." << endl;
	return;
}

Triangle::Triangle(double base, double height):Shape()
{
	this->base = base;
	this->height = height;
	setArea(calculateArea());
}

double Triangle::getBase() const
{
	return this->base;
}
double Triangle::getHeight() const
{
	return this->height;
}
double Triangle::calculateArea()
{
	return (this->base)*(this->height)/2.0;
}
void Triangle::setBase(double base)
{
	this->base = base;
	return;
}
void Triangle::setHeight(double height)
{
	this->height = height;
	return;
}
void Triangle::print()
{
	cout << "Triangle:  Base = " <<base << ", Height = " << height<< ", area = " << (this->getArea()) <<"." << endl;
	return;
}

int main()
{
	double x1,x2;
	Rectangle* R;
	Triangle* T;
	bool done = false;
	while(!done)
	{
		cout << "What is the shape? (rectangle or triangle)";
		inChar = cin.get();
		cin.get();
		inChar = toupper(inChar);
		if(inChar == 'R')
		{
			cout << "Please enter the length: ";
			cin >> x1;
			cout << "Please enter the width: ";
			cin >> x2;
			cin.get();
			R =  new Rectangle(x1,x2);
			R->print();
	
		}
		else if(inChar == 'T')
		{
			cout << "Please enter the base: ";
			cin >> x1;
			cout << "Please enter the height: ";
			cin >> x2;
			cin.get();
			T =  new Triangle(x1,x2);
			T->print();
		}
			else
		{
			cout << "I don't recognize that." << endl;
		}
		cout << "Would you like to try again? (yes or no) ";
		inChar = cin.get();
		cin.get();
		if(toupper(inChar) == 'N'){done = true;}
		else {done = false;}
	}
	
	
}
