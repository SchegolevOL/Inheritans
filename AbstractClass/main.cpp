#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

class Vehicle
{
	int speed;
public:
	virtual void move() = 0;//чисто виртуальный метод
};
class GroundVehicle : private Vehicle
{

};
class Car : GroundVehicle
{
public:
	void move()
	{
		cout << "Машина едит на 4 колесах" << endl;
	}
};
class Bike:GroundVehicle
{
public:
	void move()
	{
		cout << "Мотоцикл едет на 2 колесах" << endl;
	}
	
};
class FloatTransport:Vehicle
{
};
class Speedboat :FloatTransport
{
public:
	void move()
	{
		cout << "Катер плывет" << endl;
	}
};
class Yacht : FloatTransport
{
public:
	void move()
	{
		cout << "Яхта плывет" << endl;
	}
};
class FlyTransport : Vehicle 
{
};
class Plane : FlyTransport
{
public:
	void move()
	{
		cout << "Самолет летает" << endl;
	}
};
class Helicopter : FlyTransport
{
public:
	void move()
	{
		cout << "Верталет летает" << endl;
	}
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//Vehicle v;
	Car bmv;
	bmv.move();
	Bike hd;
	hd.move();
	Speedboat sb;
	sb.move();
	Yacht ya;
	ya.move();
	Plane pl;
	pl.move();
	Helicopter hl;
	hl.move();



	return 0;
}