#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<Windows.h>
#include<string>
#include<cstring>
#include<string.h>
#include<fstream>

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
//#define FREND



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
	virtual ostream& print(ostream& os=cout)const
	{
		
		os << left;
		os.width(20);
		os << last_name ;
		os.width(10);
		os << first_name;
		os.width(3);
		os << age << " лет";
		return os;
		
	}
	virtual ofstream& print(ofstream& of)const
	{		
		of << left;
		of.width(20);
		of << last_name;
		of.width(10);
		of << first_name;
		of.width(3);
		of << age;
		return of;
	}

	virtual istream& input(istream& in)
	{
		in >> last_name;
		in >> first_name;
		in >> age;
		return in;
	}

	virtual ifstream& scan(ifstream& is)
	{
		is >> last_name >> first_name >> age;
		return is;
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
	ostream&  print(ostream& os)const
	{
		Human::print(os);
		os.width(20);
		os << position;
		return os;
	}
	ofstream& print(ofstream& of)const
	{
		Human::print(of);
		of.width(20);
		of << position;
		return of;
	}

	istream& input(istream& in)
	{
		Human::input(in);
		in >> position;
		return in;
	}

	ifstream& scan(ifstream& is)
	{
		Human::scan(is);
		is >> position;
		return is;
	}

	
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
	ostream& print(ostream& os)const
	{
		Employee::print(os);
		os.width(10);

		os << salary ;
		return os;
	}
	ofstream& print(ofstream& of)const
	{
		Employee::print(of);
		of.width(20);
		of << right;
		of << salary<<" ";
		return of;
	}

	istream& input(istream& in)
	{
		Employee::input(in);
		in >> salary;
		return in;
	}

	ifstream& scan(ifstream& is)
	{
		Employee::scan(is);
		is >> salary;
		return is;
	}
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
	ostream& print(ostream& os)const
	{
		Employee::print(os);
		os.width(10);
		os << rate;
		os.width(10);
		os << hours;		
		 return os;
	}

	ofstream& print(ofstream& of)const
	{
		Employee::print(of);
		of.width(10);
		of << rate;
		of.width(10);
		of << hours;
		return of;
	}

	istream& input(istream& in)
	{
		Employee::input(in);
		in >> rate;
		in >> hours;
		return in;
	}

	ifstream& scan(ifstream& is)
	{
		Employee::scan(is);
		is >> rate >> hours;
		return is;
	}


	
};
std::ostream& operator << (std :: ostream& os, const Human& obj)
{
	return obj.print(os);
}
std::istream& operator >> (std::istream& in, Human& obj)
{
	return obj.input(in);
}


ofstream& operator << (std::ofstream& of, const Human& obj)
{
	return obj.print(of);
}
ifstream& operator >>(ifstream& is, Human& obj)
{	
	return obj.scan(is);
}

Employee* EmployeeFactory(const string& type)
{
	if (type.find("PermanentEmployee")!=string::npos)//наличие в строке
	{
		return new PermanentEmployee("","",0,"",0);
	}
	if (type.find("HourlyEmpoloyee") != string::npos)
	{
		return new HourlyEmpoloyee("", "", 0, "", 0, 0);
	}
}

//#define SAVE_TO_FILE

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

#ifdef SAVE_TO_FILE



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
		cout << *department[i] << endl;
		total_salary += department[i]->get_salary();
	}

	//работа с файлами
	ofstream fout("file.txt");
	for (size_t i = 0; i < sizeof(department) / sizeof(Employee*); i++)
	{
		fout.width(30);
		fout<<left;
		fout << string(typeid(*department[i]).name()) + ": ";
		fout << *department[i] << endl;
	}
	fout.close();
	system("start notepad file.txt");
	cout << "\n-----------------------------------------\n";
	cout << "Общяя зарплата : " << total_salary << endl;
	cout << "\n-----------------------------------------\n";
	for (size_t i = 0; i < sizeof(department) / sizeof(Employee*); i++) 
		delete department[i];
	/*PermanentEmployee pe();
	cout << "Введите информацию о сотруднике: ";
	cin >> pe;*/
#endif // 

	Employee** department = nullptr;
	int n = 0;//
	ifstream fin("file.txt");

	if (fin.is_open())
	{
		string employee_type;
		
		for(; !fin.eof(); n++)
		{
			getline(fin, employee_type);
		}
		n--;
		cout << n<<endl;
		department = new Employee * [n] {};
		//возвращаем курсор в начало файла
		cout << fin.tellg() << endl;
		fin.clear();//очищаем поток
		fin.seekg(0);//задаем расположение курсора
		cout << fin.tellg() << endl;
		//загружаем данне из файла в массив
		for (size_t i = 0; i < n; i++)
		{
			getline(fin, employee_type, ':');//чтение строки до пробела
			department[i] = EmployeeFactory(employee_type);
			fin >> *department[i];
		}
	}

	else
	{
		cerr << "Erorr: file non found" << endl;
	}

	for (size_t i = 0; i < n; i++)
	{
		cout << *department[i]<<endl;
	}

	for (size_t i = 0; i < n; i++)
	{
		delete department[i];
	}
	delete[] department;
	fin.close();
	return 0;
}