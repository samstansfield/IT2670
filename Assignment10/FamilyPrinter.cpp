#include <iostream>
#include <cmath>
#include "FamilyPrinter.h"

using namespace std;
/*
The thing I like best about object oriented programming is encapsulation.  To be certain that one
is not accessing the wrong variables.  It is also the worst thing about it.  It means writing dozens of 
accessor and mutator functions.  Fortunately, this program only has a few variables.
*/
// ----------------------------------------------------------------------------------------
Mother::Mother(std::string thisHairColor, std::string thisFaceShape, bool thisLobes)
{
	this->hairColor = thisHairColor;
	this->faceShape = thisFaceShape;
	this->earLobes = thisLobes;
}
std::string Mother::getHairColor() const
{
	return this->hairColor;
}
std::string Mother::getFaceShape() const
{
	return this->faceShape;
}
bool Mother::getEarLobes() const
{
	return this->earLobes;
}
void Mother::setHairColor(std::string newHairColor)
{
	this->hairColor = newHairColor;
	return;
}
void Mother::setFaceShape(std::string newFaceShape)
{
	this->faceShape = newFaceShape;
	return;
}
void Mother::setEarLobes(bool newLobes)
{
	this->earLobes = newLobes;
	return;
}
void Mother::printMother()
{
	cout << "The hair color is: " << (this->hairColor) << ".  The Face Shape is: " << (this->faceShape) <<
		".  Attached ear lobes is: " << (this->earLobes) << "." << endl;
	return;
}
// ----------------------------------------------------------------------------------------
Father::Father(std::string thisEye, double thisHeight, char thisType)
{
	this->eyeColor = thisEye;
	this->height = thisHeight;
	this->bloodType = thisType;
}

std::string Father::getEyeColor() const
{
	return this->eyeColor;
}
double Father::getHeight() const
{
	return this->height;
}
char Father::getType() const
{
	return this->bloodType;
}
void Father::setEyeColor(std::string newEyeColor)
{
	this->eyeColor =  newEyeColor;
	return;
}
void Father::setHeight(double newHeight)
{
	this->height =  newHeight;
	return;
}
void Father::setType(char newType)
{
	this->bloodType = newType;
	return;
}
void Father::printFather()
{
	cout << "The eye color is: " << (this->eyeColor) << ".  The Height is: " << (this->height) <<
		" cm.  Blood type is: " << (this->bloodType) << "." << endl;
	return;
}
// ----------------------------------------------------------------------------------------

Child::Child(Mother* M, Father* F)
{
	this->M = M;
	this->F = F;
}

void Child::print()
{
	(this->M)->printMother();
	(this->F)->printFather();
	return;	
}

// ----------------------------------------------------------------------------------------
int main()
{
	
	Mother* M = new Mother("brown","square",true);
	cout << "The Mother is: " << endl;;
	M->printMother();
	
	cout << "The Father is: " << endl;
	Father* F = new Father("blue",185,'B');
	F->printFather();
	cout << "-------------------------------------------" << endl;
	Child* C = new Child(M,F);
	cout << "The child is: " << endl;
	C->print();
	
}

