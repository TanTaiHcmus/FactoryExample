#include <iostream>
#include <string>

using namespace std;

enum TypeClass
{
	Chuyen_Toan,
	Chuyen_Ly
};

class Student
{
	public:
		virtual string getNameClass() = 0;
		Student() {};
		~Student() {};
};

class ChuyenToan : public Student
{
	private:
		static const int maxCountStudent = 3;
		static int currentCount;

	public:
		ChuyenToan()
		{
			currentCount++;
		}

		~ChuyenToan() {};

		static bool checkCondition()
		{
			return (currentCount < maxCountStudent);
		}

		string getNameClass()
		{
			return "Chuyen Toan";
		}
};

class ChuyenLy : public Student
{
private:
	static const int maxCountStudent = 2;
	static int currentCount;

public:
	ChuyenLy()
	{
		currentCount++;
	}

	~ChuyenLy() {};

	static bool checkCondition()
	{
		return (currentCount < maxCountStudent);
	}

	string getNameClass()
	{
		return "Chuyen Ly";
	}
};

class StudentFactory
{
	private:
		StudentFactory() {};

	public:
		static Student *addStudentToClass(TypeClass classname)
		{
			switch (classname)
			{
			case Chuyen_Toan:
				if (ChuyenToan::checkCondition()) 
					return new ChuyenToan();
				break;
			case Chuyen_Ly:
				if (ChuyenLy::checkCondition())
					return new ChuyenLy();
				break;
			default:
				return NULL;
				break;
			}
			return NULL;
		}
};

int ChuyenToan::currentCount = 0;

int ChuyenLy::currentCount = 0;

int main() {

	Student *student1 = StudentFactory::addStudentToClass(TypeClass::Chuyen_Toan);
	Student *student5 = StudentFactory::addStudentToClass(TypeClass::Chuyen_Toan);
	Student *student2 = StudentFactory::addStudentToClass(TypeClass::Chuyen_Toan);
	Student *student3 = StudentFactory::addStudentToClass(TypeClass::Chuyen_Ly);
	Student *student6 = StudentFactory::addStudentToClass(TypeClass::Chuyen_Ly);
	cout << student6->getNameClass() << " " << student1->getNameClass();
	system("pause");
	return 0;
}