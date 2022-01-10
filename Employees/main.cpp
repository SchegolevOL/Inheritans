#include<iostream>
#include<Windows.h>
#include<String>

using namespace std;

#define EMPOLOYEES_TAKE_PARAMETRS const string& first_name, const string& last_name, const string& specialization
#define EMPOLOYEES_GIVE_PARAMETRS first_name, last_name, specialization
#define PIECEWORKER_TAKE_PARAMETRS const unsigned int& rate, const unsigned int& number_parts
#define SALARY_TAKE_PARAMETRS double time_worked, unsigned int official_salary
#define LINE "--------------------------------------------------\n"
class Empoloyees
{
	string first_name;
	string last_name;
	string specialization;
public:
	//-----get-----
	const string get_first_name()const
	{
		return first_name;
	}
	const string get_last_name()const
	{
		return last_name;
	}
	const string get_specialization()const
	{
		return specialization;
	}
	//-----set-----
	void set_first_name(const string& first_name)
	{
		this->first_name = first_name;
	}
	void set_last_name(const string& last_name)
	{
		this->last_name = last_name;
	}
	void set_specialization(const string& specialization)
	{
		this->specialization = specialization;
	}
	//-----Construction-----
	Empoloyees(EMPOLOYEES_TAKE_PARAMETRS)
	{
		set_first_name(first_name);
		set_last_name(last_name);
		set_specialization(specialization);
		cout << "EConstructor" << this << endl;
	}
	//-----Destructor-----
	virtual ~Empoloyees()
	{
		cout << "EDestructor: " << this << endl;
	}
	virtual void print()const
	{
		cout << LINE;
		cout <<"Имя и фамилия сотрудника : "<< last_name << " " << first_name << endl;
		cout << "Специальность : " << specialization << endl;
		
	}
};
class Pieceworker:Empoloyees
{
	unsigned int rate;
	unsigned int number_parts;
public:
	//-----get-----
	const unsigned int get_rate()const
	{
		return rate;
	}
	const unsigned int get_number_parts()const
	{
		return number_parts;
	}
	//-----set-----
	void set_rate(const unsigned int& rate)
	{
		this->rate = rate;
	}
	void set_number_parts(const unsigned int& number_parts)
	{
		this->number_parts = number_parts;
	}
	//-----Construction-----
	Pieceworker(EMPOLOYEES_TAKE_PARAMETRS, PIECEWORKER_TAKE_PARAMETRS):Empoloyees(EMPOLOYEES_GIVE_PARAMETRS)
	{
		set_rate(rate);
		set_number_parts(number_parts);
	}
	//-----Destructor-----
	virtual ~Pieceworker()
	{
		cout << "PDestructor: " << this << endl;
	}
	virtual void print()const
	{
		Empoloyees::print();
		cout << "Оплата за изготовление 1 детали :  " << rate << " рублей/деталей " << endl;
		cout << "Колличество деталей  : " << number_parts << " деталей" << endl;

	}
};
class Salary:Empoloyees
{
	double time_worked;
	unsigned int official_salary;
public:
	//-----get-----
	double get_time_worked()const
	{
		return time_worked;
	}
	const unsigned int get_official_salary()const
	{
		return official_salary;
	}
	//-----set-----
	void set_time_worked(const double& time_worked)
	{
		this->time_worked = time_worked;
	}
	void set_official_salary(const unsigned int official_salary)
	{
		this->official_salary = official_salary;
	}
	//-----Construction-----
	Salary(EMPOLOYEES_TAKE_PARAMETRS, SALARY_TAKE_PARAMETRS) :Empoloyees(EMPOLOYEES_GIVE_PARAMETRS)
	{
		set_time_worked(time_worked);
		set_official_salary(official_salary);
	}
	//-----Destructor-----
	virtual ~Salary()
	{
		cout << "SDestructor: " << this << endl;
	}
	virtual void print()const
	{
		Empoloyees::print();
		cout << "Часовая ставка :  " << official_salary << " рублей/час" << endl;
		cout << "Колличество отработаных часов  : " << official_salary<< " часов" << endl;
	}
};



int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Empoloyees emp1("Schegolev", "Oleg", "Инженер");
	emp1.print();
	Pieceworker p_wor1("Иваннов", "Иан", "станочник", 10, 20);
	p_wor1.print();
	Salary sal1("Сидоров", "Павел", "техник", 200, 180);
	sal1.print();

	FILE* out;
	const char* path = "data.txt";
	if ((fopen_s(&out, path, "w")) != NULL)
		cout << "The file could not be created";
	else
	{
		fprintf(out, "%s ",emp1.get_last_name());
		fprintf(out, "%u ", sal1.get_time_worked());

		fclose(out);
	}
	

	return 0;
}