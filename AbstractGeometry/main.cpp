﻿#include <iostream>
#include <Windows.h>
#include <string>
#include <math.h>
using namespace std;



//создаем тип данных Color
enum Color
{
	red =	0x000000FF,
	green = 0x0000FF00,
	blue =	0x00FF0000,

	consol_defaulf = 0x07,
	consol_blue = 0x99,
	consol_green = 0xAA,
	consol_red = 0xCC	
};
double pi = 3.14;
class Shape
{
protected:
	Color color;
	unsigned int start_x;
	unsigned int start_y;
	unsigned int line_width;

public:
	void set_start_x(unsigned int start_x)
	{
		if (start_x>300)
		{
			start_x = 300;
		}
		this->start_x = start_x;
	}
	void set_start_y(unsigned int start_y)
	{
		if (start_y > 300)
		{
			start_y = 300;
		}
		this->start_y = start_y;
	}
	void set_line_width(unsigned int sline_width)
	{
		if (line_width > 20)
		{
			line_width = 20;
		}
		this->line_width = line_width;
	}


	Shape(	Color color, 
			unsigned int start_x, 
			unsigned int start_y, 
			unsigned int line_width): color(color)
	{
		set_start_x(start_x);
		set_start_y(start_y);
		set_line_width(line_width);
	}
	virtual ~Shape(){}
	virtual double get_area()const = 0;
	virtual double get_perimeter()const = 0;
	virtual void draw()const = 0;
};

class Square : public Shape
{
	double side;
public:
	double get_side()const
	{
		return side;
	}
	void set_side(double side)
	{
		if (side<=0)side = 10;
		this->side = side;
	}

	Square(	
			double side, 
			Color color, 
			unsigned int start_x,
			unsigned int start_y,
			unsigned int line_width) :Shape(color, start_x, start_y, line_width)
	{
		set_side(side);
	}
	~Square(){}
	double get_area()const
	{
		return side * side;
	}
	double get_perimeter()const
	{
		return side * 4;
	}
	void draw()const
	{
		/*HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, color);
		for (size_t i = 0; i < side; i++)
		{
			for (size_t i = 0; i < side; i++)
			{
				cout << "  ";
			}
			cout << endl;
		}
		SetConsoleTextAttribute(hConsole, Color::consol_defaulf);*/
		HWND hConsole = GetConsoleWindow();//получаем окно консоли чтобы к нему можно было обратиться
		HDC hdc = GetDC(hConsole);
		HPEN hPen = CreatePen(PS_SOLID, line_width, color);//color=RBG(255,0,0)
		SelectObject(hdc, hPen);
		HBRUSH hBrysh = CreateSolidBrush(color);
		SelectObject(hdc, hBrysh);
		Rectangle(hdc, start_x, start_y, start_x + side, start_y + side);
		DeleteObject(hBrysh);
		DeleteObject(hPen);
		ReleaseDC(hConsole, hdc);
	}
};
class Rectangl: Shape
{
	double width;
	double height;
public:
	double get_width()const
	{
		return width;
	}
	void set_width(double width)
	{
		if (width <= 0)width = 10;
		this->width = width;
	}
	double get_height()const
	{
		return height;
	}
	void set_height(double height)
	{
		if (height <= 0)height = 10;
		this->height = height;
	}

	Rectangl(
		double width,
		double height,
		Color color,
		unsigned int start_x,
		unsigned int start_y,
		unsigned int line_width) :Shape(color, start_x, start_y, line_width)
	{
		set_width(width);
		set_height(height);
	}
	Rectangl(
		double width,
		Color color,
		unsigned int start_x,
		unsigned int start_y,
		unsigned int line_width) :Shape(color, start_x, start_y, line_width)
	{
		set_width(width);
		set_height(width);
	}
	~Rectangl(){};
	double get_area()const
	{
		return width * height;
	}
	double get_perimeter()const
	{
		return width * 2 + height * 2;
	}
	void draw()const
	{
		HWND hConsole = GetConsoleWindow();//получаем окно консоли чтобы к нему можно было обратиться
		HDC hdc = GetDC(hConsole);
		HPEN hPen = CreatePen(PS_SOLID, line_width, color);//color=RBG(255,0,0)
		SelectObject(hdc, hPen);
		HBRUSH hBrysh = CreateSolidBrush(color);
		SelectObject(hdc, hBrysh);
		Rectangle(hdc, start_x, start_y, start_x + width, start_y + height);
		DeleteObject(hBrysh);
		DeleteObject(hPen);
		ReleaseDC(hConsole, hdc);
	}
	
}; 
class Ellips : public Shape
{
	double radius;
public:
	double get_radius()const
	{
		return radius;
	}
	void set_radius(double radius)
	{
		if (radius <= 0)radius = 10;
		this->radius = radius;
	}

	Ellips(
		double radius,
		Color color,
		unsigned int start_x,
		unsigned int start_y,
		unsigned int line_width) :Shape(color, start_x, start_y, line_width)
	{
		set_radius(radius);
	}
	~Ellips() {}
	double get_area()const
	{
		return radius * radius * pi;
	}
	double get_perimeter()const
	{
		return radius * 2 * pi;
	}
	void draw()const
	{
		HWND hConsole = GetConsoleWindow();//получаем окно консоли чтобы к нему можно было обратиться
		HDC hdc = GetDC(hConsole);
		HPEN hPen = CreatePen(PS_SOLID, line_width, color);//color=RBG(255,0,0)
		SelectObject(hdc, hPen);
		HBRUSH hBrysh = CreateSolidBrush(color);
		SelectObject(hdc, hBrysh);
		Ellipse(hdc, start_x, start_y, start_x + radius*2, start_y + radius*2);
		DeleteObject(hBrysh);
		DeleteObject(hPen);
		ReleaseDC(hConsole, hdc);
	}
};

class Triangl : public Shape
{
	POINT a;
	POINT b; 
	POINT c;
public:
	POINT get_point_a()const
	{
		return a;
	}
	void set_point_a(int x, int y)
	{
		a.x = x;
		a.y = y;
	}

	POINT get_point_b()const
	{
		return b;
	}
	void set_point_b(int x, int y)
	{
		b.x = x;
		b.y = y;
	}

	POINT get_point_c()const
	{
		return c;
	}
	void set_point_c(int x, int y)
	{
		c.x = x;
		c.y = y;
	}

	double triangl_side(int a_x, int a_y, int b_x, int b_y)const
	{
		return sqrt(pow((a_x - b_x), 2) + pow((a_y - b_y), 2));
	}
	
	Triangl(
		Color color,
		unsigned int start_x,
		unsigned int start_y,
		int point_b_x,
		int point_b_y,
		int point_c_x,
		int point_c_y,
		unsigned int line_width) :Shape(color, start_x, start_y, line_width)
	{
		set_point_a(start_x, start_y);
		set_point_b(point_b_x, point_b_y);
		set_point_c(point_c_x, point_c_y);

	}
	~Triangl() {}
	
	double get_perimeter()const
	{
		return  triangl_side(a.x, a.y, b.x, b.y)+ 
				triangl_side(a.x, a.y, c.x, c.y)+ 
				triangl_side(b.x, b.y, c.x, c.y);
	}
	double get_area()const
	{
		double p = get_perimeter() / 2;
		return sqrt(p*(p- triangl_side(a.x, a.y, b.x, b.y))*
					  (p- triangl_side(a.x, a.y, c.x, c.y))*
					  (p- triangl_side(b.x, b.y, c.x, c.y)));
	}


	void draw()const
	{
		POINT point [3] = {a, b, c};
		POINT* p = point;
		HWND hConsole = GetConsoleWindow();//получаем окно консоли чтобы к нему можно было обратиться
		HDC hdc = GetDC(hConsole);
		HPEN hPen = CreatePen(PS_SOLID, line_width, color);//color=RBG(255,0,0)
		SelectObject(hdc, hPen);
		HBRUSH hBrysh = CreateSolidBrush(color);
		SelectObject(hdc, hBrysh);
		Polygon(hdc, p, 3);
		DeleteObject(hBrysh);
		DeleteObject(hPen);
		ReleaseDC(hConsole, hdc);
	}
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Rectangl rec(100,50,Color::blue,300,20,5);
	cout << endl;
	cout << "Ширина :\t" << rec.get_width() << endl;
	cout << "Высота :\t" << rec.get_height() << endl;
	cout << "Площадь :\t" << rec.get_area() << endl;
	cout << "Периметр квадрата:\t" << rec.get_perimeter() << endl;
	rec.draw();
	cout << "\n\n\n\n";

	Ellips ell(25, Color::red, 300, 120, 5);
	cout << endl;
	cout << "Радиус :\t" << ell.get_radius() << endl;	
	cout << "Площадь :\t" << rec.get_area() << endl;
	cout << "Длинна окружности:\t" << rec.get_perimeter() << endl;
	ell.draw();
	cout << "\n\n\n\n";

	Triangl tri(Color::blue, 300, 220, 300, 240, 340, 240, 5);
	cout << tri.get_perimeter() << endl;
	cout << tri.get_area() << endl;
	tri.draw();
	cout << "\n\n\n\n";

	return 0;
}