#include<iostream>
#include<Windows.h>
#include<String>
#include <cstring>
#include<string.h>

using namespace std;
using std::cout;
using std::cin;
using std::endl;


#define HUMAN_TAKE_PARAMETRS const std::string& last_name,const std::string& first_name,unsigned int age
#define HUMAN_GIVE_PARAMETRS last_name, first_name, age
#define EMPOLOYEE_TAKE_PARAMETRS const std::string&  position
#define EMPOLOYEE_GIVE_PARAMETRS position
#define PERMANENT_TAKE_PARAMETRS double salary
#define HAURLY_EMPOLOYEE_GIVE_PARAMETRS rate, hours
#define HAURLY_EMPOLOYEE_TAKE_PARAMETRS double rate, int hours
class Human;



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
	Human(HUMAN_TAKE_PARAMETRS)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		cout << "HConstructor" << this << endl;
	}
	//-----------Destructor---------------------
	virtual ~Human()
	{
		cout << "HDestructor: " << this << endl;
	}
	//----------------Methods:--------------------
	virtual void print()const
	{
		cout << last_name << " " << first_name << "  " << age << " лет" << endl;
	}
	/*friend ostream& operator << (ostream os, const Human& obj)
	{
		return os << obj.get_last_name() << obj.get_first_name() << obj.get_age() << endl;
	}*/
	virtual string txt()const
	{
		char* age_p;		
		itoa(age, age_p, 10);
		string age_s = (string)age_p;
		//const size_t size = first_name.length() + last_name.length() + age_s.length()+3;
		char bufer[256];
		
		strcpy(bufer, first_name.c_str());
		strcat(bufer, " ");
		strcat(bufer, last_name.c_str());
		strcat(bufer, age_s.c_str());
		strcat(bufer, " лет\n");
		return bufer;
	}
};



class Employee :public Human
{
	std::string position;
public:
	const std::string& get_position()const
	{
		return position;
	}
	void set_position(const std::string& position)
	{
		this->position = position;
	}
	virtual double get_salary()const = 0;
	//-----Construction-----
	Employee(HUMAN_TAKE_PARAMETRS, EMPOLOYEE_TAKE_PARAMETRS): Human(HUMAN_GIVE_PARAMETRS)
	{
		set_position(position);
		cout << "EConstructor" << this << endl;
	}
	//-----Destructor-----
	~Employee()
	{
		cout << "EDestructor: " << this << endl;
	}
	void print()const
	{
		Human::print();		
		cout << position;
		cout << endl;		
	}
	/*friend ostream& operator << (ostream os, const Employee& obj)
	{
		return os << obj.get_position() << endl;
	}*/
	//string txt()const
	//{
	//	Human::txt;
	//	//const size_t size = position.length();
	//	char bufer[256];

	//	strcpy(bufer, position.c_str());
	//	strcat(bufer, " \n");
	//	
	//	return bufer;
	//}
};



class PermanentEmployee : public Employee
{
	double salary;//зарплата
public:
	double get_salary()const
	{
		return salary;
	}
	void set_salary(double salary)
	{
		this->salary = salary;
	}
	PermanentEmployee(HUMAN_TAKE_PARAMETRS, 
					  EMPOLOYEE_TAKE_PARAMETRS, 
					  PERMANENT_TAKE_PARAMETRS) : 
		Employee(HUMAN_GIVE_PARAMETRS, 
				 EMPOLOYEE_GIVE_PARAMETRS)
	{
		set_salary(salary);
		cout << "PEConstructor" << this << endl;
	}
	//-----Destructor-----
	~PermanentEmployee()
	{
		cout << "PEDestructor: " << this << endl;
	}
	void print()const
	{
		Employee::print();
		cout << salary;
		cout << endl;
	}
	/*friend ostream& operator << (ostream os, const PermanentEmployee& obj)
	{
		return os << obj.get_salary() << endl;
	}*/
	//string txt()const
	//{
	//	Employee::txt;
	//	char* salary_p;
	//	itoa(salary, salary_p, 10);
	//	string salary_s = (string)salary_p;
	//	//const size_t size = first_name.length() + last_name.length() + age_s.length()+3;
	//	char bufer[256];

	//	strcpy(bufer, salary_s.c_str());
	//	strcat(bufer, " рублей");
	//	
	//	return bufer;
	//}

};



class HourlyEmpoloyee :public Employee
{
	double rate;//тариф
	int hours;//часы
public:
	double  get_rate()const
	{
		return rate;
	}
	int  get_hours()const
	{
		return hours;
	}
	double  get_salary()const
	{
		return rate* hours;
	}
	void set_rate(double rate)
	{
		this->rate = rate;
	}
	void set_hours(int hours)
	{
		this->hours = hours;
	}
	HourlyEmpoloyee(HUMAN_TAKE_PARAMETRS,
		EMPOLOYEE_TAKE_PARAMETRS,
		HAURLY_EMPOLOYEE_TAKE_PARAMETRS) :
		Employee(HUMAN_GIVE_PARAMETRS,
			EMPOLOYEE_GIVE_PARAMETRS)
	{
		set_rate(rate);
		set_hours(hours);
		cout << "PEConstructor" << this << endl;
	}
	//-----Destructor-----
	~HourlyEmpoloyee()
	{
		cout << "HEDestructor: " << this << endl;
	}
	void print()const
	{
		Employee::print();
		cout <<"Тариф " << rate <<" ,отработано " << hours;
		cout << endl;
	}
	/*friend ostream& operator << (ostream os, const HourlyEmpoloyee& obj)
	{
		return os << obj.get_rate() << obj.get_hours() << endl;
	}*/
	//virtual string txt()const
	//{
	//	Employee::txt;
	//	char* rate_p;
	//	itoa(rate, rate_p, 10);
	//	string rate_s = (string)rate_p;
	//	char* hours_p;
	//	itoa(hours, hours_p, 10);
	//	string hours_s = (string)hours_p;

	//	//const size_t size = first_name.length() + last_name.length() + age_s.length()+3;
	//	char bufer[256];

	//	strcpy(bufer, rate_s.c_str());
	//	strcat(bufer, " рублей, отработано ");
	//	strcat(bufer, hours_s.c_str());
	//	
	//	strcat(bufer, " часов\n");
	//	return bufer;
	//}
};
//ostream& operator << (ostream os, const Human& obj)
//{
//	return os << obj.txt() << endl;
//}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Employee* department[] =
	{
		new PermanentEmployee("Rosenberg", "Ken", 30, "Lawyer", 2000),
		new PermanentEmployee("Diaz", "Rikardo", 30, "Boss", 50000),
		new HourlyEmpoloyee("Vercetty", "Tomas", 30, "Security", 100, 8)
	};
	double total_salary=0;
	for (size_t i = 0; i < sizeof(department)/ sizeof(Employee*); i++)
	{
		cout << "\n------------------------------------\n";
		//department[i]->print();
		cout << department[i]->txt() << endl;
		total_salary += department[i]->get_salary();
	}
	cout << "\n-----------------------------------------\n";
	cout << "Общяя зарплата : " << total_salary << endl;
	cout << "\n-----------------------------------------\n";
	for (size_t i = 0; i < sizeof(department) / sizeof(Employee*); i++) 
		delete department[i];





	return 0;
}