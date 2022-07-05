#include <string>


class Mother
{
	protected:
		std::string hairColor, faceShape;
		bool earLobes;
	public:
		Mother(){};
		Mother(std::string thisHairColor, std::string thisFaceShape, bool thisLobes);
		virtual ~Mother(){};
		std::string getHairColor() const;
		std::string getFaceShape() const;
		bool getEarLobes() const;
		void setHairColor(std::string newHairColor);
		void setFaceShape(std::string newFaceShape);
		void setEarLobes(bool newLobes);
		void printMother();
		
};

class Father
{
	protected:
		std::string eyeColor;
		double height;
		char bloodType;
	public:
		Father(){};
		Father(std::string thisEye, double thisHeight, char thisType);
		virtual ~Father(){};
		std::string getEyeColor() const;
		double getHeight() const;
		char getType() const;
		void setEyeColor(std::string newEyeColor);
		void setHeight(double newHeight);
		void setType(char newType);
		void printFather();
		
};
	
class Child : public Mother, public Father
{
	protected:
		Mother* M;
		Father* F;
	public:
		Child(){};
		Child(Mother* M, Father* F);
/*		I don't need these methods for the assignment so I'm not going to write them.
		Mother* getMother() const;
		Father* getFather() const;
		void setMother(Mother* M);
		void setFather(Father* F);  */ 
		~Child(){};
		void print();
		
};
