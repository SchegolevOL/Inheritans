#include <iostream>
#include<Windows.h>
#include<string>
#include<fstream>
using namespace std;

#define HUMAN_TAKE_PARAMETRS const std::string& last_name,const std::string& first_name,unsigned int age
#define HUMAN_GIVE_PARAMETRS last_name, first_name, age
#define STUENT_TAKE_PARAMETRS const std::string& speciality,const std::string& group,double rating,double attendance
#define STUENT_GIVE_PARAMETRS speciality, group, rating, attendance
#define TEACHER_TAKE_PARAMETRS const std::string& speciality,unsigned int xperience,double evil
#define TEACHER_GIVE_PARAMETRS speciality, xperience, evil

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
	virtual ostream& print(ostream& os)const
	{
		os << last_name<<" ";
		os << first_name<<" ";
		os << age << endl;

		return os;
	}
	virtual istream& input(istream& in)
	{
		in >> last_name;
		in >> first_name;
		in >> age;
		return in;
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
	virtual ifstream& scan(ifstream& is)
	{
		is >> last_name >> first_name >> age;
		return is;
	}

};
class Student :public Human
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
	Student(HUMAN_TAKE_PARAMETRS,
			STUENT_TAKE_PARAMETRS)
			:Human(HUMAN_GIVE_PARAMETRS)
	{
		set_speciality(speciality);
		set_group(group);
		set_rating(rating);
		set_attendance(attendance);
		cout << "SConstructor :\t" << this << endl;
	}
	~Student()
	{
		cout << "SDestructor: " << this << endl;
	}
	ostream& print(ostream& os)const
	{
		Human::print(os);
		os << speciality<< " ";
		os << group << "  ";
		os << rating << "  ";
		os << attendance << endl;
		return os;
	}
	istream& input(istream& in)
	{
		Human::input(in);
		in >> speciality;
		in >> group;
		in >> rating;
		in >> attendance;
		return in;
	}
	ofstream& print(ofstream& of)const
	{
		Human::print(of);
		of.width(20);
		of << speciality;
		of.width(20);
		of.width(20);
		of << group;
		of.width(20);
		of << rating;
		of.width(20);
		of << attendance;
		return of;
	}
	ifstream& scan(ifstream& is)
	{
		Human::scan(is);
		is >> speciality;
		is >> group;
		is >> rating;
		is >> attendance;
		return is;
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
	Teacher(HUMAN_TAKE_PARAMETRS,
		TEACHER_TAKE_PARAMETRS)
		:Human(HUMAN_GIVE_PARAMETRS)
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
	ostream& print(ostream& os)const
	{
		Human::print(os);
		os << speciality << " ";
		os << xperience << "  ";
		os << evil << endl;
		return os;
	}
	istream& input(istream& in)
	{
		Human::input(in);
		in >> speciality;
		in >> xperience;
		in >> evil;
		return in;
	}
	ofstream& print(ofstream& of)const
	{
		Human::print(of);
		of << speciality;
		of.width(20);
		of << xperience;
		of.width(20);
		of << evil;
		return of;
	}
	ifstream& scan(ifstream& is)
	{
		Human::scan(is);
		is >> speciality;
		is >> xperience;
		is >> evil;
		return is;
	}
};
class Graduate : public Student
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
	Graduate(HUMAN_TAKE_PARAMETRS,
		STUENT_TAKE_PARAMETRS,
		const std::string& diplom)
		:Student(HUMAN_GIVE_PARAMETRS, STUENT_GIVE_PARAMETRS)
	{
		set_diplom(diplom);
		cout << "GConstructor :\t" << this << endl;
	}
	~Graduate()
	{
		cout << "GDestructor: " << this << endl;
	}
	ostream& print(ostream& os)const
	{
		Student::print(os);
		os << diplom << endl;
		return os;
	}
	istream& input(istream& in)
	{
		Student::input(in);
		in >> diplom;
		return in;
	}
	ofstream& print(ofstream& of)const
	{
		Student::print(of);
		of << diplom;
		return of;
	}
	ifstream& scan(ifstream& is)
	{
		Human::scan(is);
		is >> diplom;
		return is;
	}
};
ostream& operator << (ostream& os, const Human& obj)
{
	return obj.print(os);
}
istream& operator >>(istream& in, Human& obj)
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
Human* HumanFactory(const string& type)
{
	Human* human;
	if (type.find("Graduate") != string::npos)//наличие в строке
	{
		 human = new Graduate("", "", 0, "", "", 0, 0, "");
	}
	if (type.find("Student") != string::npos)
	{
		human = new Student(" ", " ", 0, "", "",  0, 0);
	}
	if (type.find("Teacher") != string::npos)
	{
		human =  new Teacher("", "", 0, "", 0, 0);
	}
	if (type.find("Human") != string::npos)
	{
		human = new Human("", "", 0);
	}
	return human;
}
//#define INHERITANS_CHEK

int main()
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
#ifdef INHERITANS_CHEK

	Human human("Connor", "John", 18);
	human.print();
	Stuent stud("Pinkman", "Jessie", 25, "Chmistry", "WW_123", 85, 95);
	stud.print();
	Teacher techer("Ivan","Ivanov",45, "matematika", 1, 1.1);
	techer.print();
	Graduate grad("Petr", "Petrov", 25, "Chmistry", "WW_456", 96, 100, "ingenering");
	grad.print();
#endif // INHERITANS_CHEK

	//generalisation(up-cast)
	Human* group[] =
	{
		new Student("Pinkman", "Jessie", 25, "Chmistry", "WW_123", 85, 95),
		new Teacher("Ivan","Ivanov",45, "matematika", 1, 1.1),
		new Graduate("Petr", "Petrov", 25, "Chmistry", "WW_456", 96, 100, "ingenering"),
		new Teacher("Gena","Frolov",46, "matematika", 1, 1.1),
		new Student("Sara", "Conar", 40, "Chmistry", "WW_145", 84, 96),
		new Graduate("Kol", "Kolotun", 25, "Chmistry", "WW_456", 96, 100, "ingenering")
	};
	cout << "\n------------------------------------------" << endl;
	for (size_t i = 0; i < sizeof(group)/sizeof(Human*); i++)
	{
		cout << typeid(*group[i]).name() << endl;//TRRI - Runtime
		cout << *group[i];
		cout << "\n------------------------------------------"<<endl;
	}
	for (size_t i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		delete group[i];
	}
	Student s1(" ", " ", 0, " ", " ", 0, 0);
	cin >> s1;
	cout << s1;

	Human** department = nullptr;
	int n = 0;
	ifstream fin("file.txt");

	if (fin.is_open())
	{
		string employee_type;

		for (; !fin.eof(); n++)
		{
			getline(fin, employee_type);
		}
		n--;
		cout << n << endl;
		department = new Human * [n] {};
		//возвращаем курсор в начало файла
		cout << fin.tellg() << endl;
		fin.clear();//очищаем поток
		fin.seekg(0);//задаем расположение курсора
		cout << fin.tellg() << endl;
		//загружаем данне из файла в массив
		for (size_t i = 0; i < n; i++)
		{
			getline(fin, employee_type, ':');//чтение строки до пробела
			department[i] = HumanFactory(employee_type);
			fin >> *department[i];
		}
		fin.close();

	}

	else
	{
		cerr << "Erorr: file non found" << endl;
	}

	for (size_t i = 0; i < n; i++)
	{
		cout << *department[i] << endl;
	}

	for (size_t i = 0; i < n; i++)
	{
		delete department[i];
	}
	delete[] department;
	




	return 0;
}