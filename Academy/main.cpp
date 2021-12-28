#include <iostream>
#include<Windows.h>
#include<string>
using namespace std;
class Human
{
	std::string last_name;
	std::string first_name;
	unsigned int age;

public:
	const std::string& get_last_name()const
	{
		return last_name;
	}
	const std::string& get_first_name()const
	{
		return first_name;
	}
	unsigned int  get_age()const
	{
		return age;
	}

	void set_last_name(const std::string& last_name)
	{
		this->last_name = last_name;
	}
	void set_first_name(const std::string& first_name)
	{
		this->first_name = first_name;
	}
	void set_age(unsigned int age)
	{
		this->age = age;
	}

	//-------------Constractors----------------
	Human(	const std::string& last_name,
			const std::string& first_name,
			unsigned int age)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		cout << "HConstructor" << this << endl;
	}
	//-----------Destructor---------------------
	~Human()
	{
		cout << "HDestructor: " << this << endl;
	}
	//----------------Methods:--------------------
	void print()const
	{
		cout << last_name << " " << first_name << "  " << age << " лет" << endl;
	}
};
class Stuent :public Human
{
	std::string speciality;
	std::string group;
	double rating;
	double attendance;
public:
	//--get
	const std::string& get_speciality()const
	{
		return speciality;
	}
	const std::string& get_group()const
	{
		return group;
	}
	double get_rating()const
	{
		return rating;
	}
	double get_attendance()const
	{
		return attendance;
	}

	//--set
	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	void set_group(const std::string& group)
	{
		this->group = group;
	}
	void set_rating(double rating)
	{
		this->rating = rating;
	}
	void set_attendance(double attendance)
	{
		this->attendance = attendance;
	}
	//-------------Constractors----------------
	Stuent(	const std::string& last_name,
			const std::string& first_name,
			unsigned int age,
			const std::string& speciality,
			const std::string& group,
			double rating,
			double attendance)
			:Human(last_name, first_name, age)
	{
		set_speciality(speciality);
		set_group(group);
		set_rating(rating);
		set_attendance(attendance);
		cout << "SConstructor :\t" << this << endl;
	}
	~Stuent()
	{
		cout << "SDestructor: " << this << endl;
	}
	void print()const
	{
		Human::print();
		cout << speciality << " " << group << "  " 
			<< rating << "  "<< attendance << endl;
	}
};
class Teacher :public Human
{
	std::string speciality;
	unsigned int xperience;
	double evil;

public:
	const std::string& get_speciality()const
	{
		return speciality;
	}
	unsigned int get_xperience()const
	{
		return xperience;
	}
	double get_evil()const
	{
		return evil;
	}

	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	void set_xperience(unsigned int xperience)
	{
		this->xperience = xperience;
	}
	void set_evil(double evil)
	{
		this->evil = evil;
	}
	//-------------Constractors----------------
	Teacher(const std::string& last_name,
		const std::string& first_name,
		unsigned int age,
		const std::string& speciality,
		unsigned int xperience,
		double evil)
		:Human(last_name, first_name, age)
	{
		set_speciality(speciality);
		set_xperience(xperience);
		set_evil(evil);
		
		cout << "TConstructor :\t" << this << endl;
	}
	~Teacher()
	{
		cout << "HDestructor: " << this << endl;
	}
	void print()const
	{
		Human::print();
		cout << speciality << " " << xperience << "  "
			<< evil << endl;
	}
};
class Graduate : public Stuent
{
	std::string diplom;

public:
	const std::string& get_diplom()const
	{
		return diplom;
	}
	void set_diplom(const std::string& diplom)
	{
		this->diplom = diplom;
	}
	Graduate(const std::string& last_name,
		const std::string& first_name,
		unsigned int age,
		const std::string& speciality,
		const std::string& group,
		double rating,
		double attendance,
		const std::string& diplom)
		:Stuent(last_name, first_name, age, speciality, group, rating, attendance)
	{
		set_diplom(diplom);
		cout << "GConstructor :\t" << this << endl;
	}
	~Graduate()
	{
		cout << "GDestructor: " << this << endl;
	}
	void print()const
	{
		Stuent::print();
		cout << diplom << endl;
	}

};



int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Human human("Connor", "John", 18);
	human.print();
	Stuent stud("Pinkman", "Jessie", 25, "Chmistry", "WW_123", 85, 95);
	stud.print();
	Teacher techer("Ivan","Ivanov",45, "matematika", 1, 1.1);
	techer.print();
	Graduate grad("Petr", "Petrov", 25, "Chmistry", "WW_456", 96, 100, "ingenering");
	grad.print();
	return 0;
}