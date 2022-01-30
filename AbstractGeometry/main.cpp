#define _USE_MATH_DEFINES //для числа Pi
#include <iostream>
#include <Windows.h>
#include <string>
#include <math.h>

using namespace std;



//создаем тип данных Color
double pi = 3.14;
namespace Geometry
{
	enum Color
	{
		red = 0x000000FF,
		green = 0x0000FF00,
		blue = 0x00FF0000,

		consol_defaulf = 0x07,
		consol_blue = 0x99,
		consol_green = 0xAA,
		consol_red = 0xCC
	};
	
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
			if (start_x > 300)
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
		void set_line_width(unsigned int line_width)
		{
			if (line_width > 20)
			{
				line_width = 1;
			}
			this->line_width = line_width;
		}


		Shape(Color color,
			unsigned int start_x,
			unsigned int start_y,
			unsigned int line_width) : color(color)
		{
			set_start_x(start_x);
			set_start_y(start_y);
			set_line_width(line_width);
		}
		Shape()
		{
			this->color = red;
			this->start_x = 0;
			this->start_y = 0;
			this->line_width = 1;
		}
		virtual ~Shape() {}
		virtual double get_area()const = 0;
		virtual double get_perimeter()const = 0;
		virtual void draw()const = 0;
		virtual void info()const
		{
			cout << "Площадь :\t" << get_area() << endl;
			cout << "Периметр :\t" << get_perimeter() << endl;
			draw();
		}
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
			if (side <= 0)side = 10;
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
		
		~Square() {}
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
			::Rectangle(hdc, start_x, start_y, start_x + side, start_y + side);
			DeleteObject(hBrysh);
			DeleteObject(hPen);
			ReleaseDC(hConsole, hdc);
		}
		virtual void info()const
		{
			cout << typeid(*this).name() << endl;
			cout << "Длинна сторны :\t" << side << endl;
			Shape::info();
		}
	};
	class Rectangle : Shape
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

		Rectangle(
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
		Rectangle(
			double width,
			Color color,
			unsigned int start_x,
			unsigned int start_y,
			unsigned int line_width) :Shape(color, start_x, start_y, line_width)
		{
			set_width(width);
			set_height(width);
		}
		~Rectangle() {};
		double get_area()const
		{
			return width * height;
		}
		double get_perimeter()const
		{
			return (width + height) * 2;
		}
		void draw()const
		{
			HWND hConsole = GetConsoleWindow();//получаем окно консоли чтобы к нему можно было обратиться
			HDC hdc = GetDC(hConsole);
			HPEN hPen = CreatePen(PS_SOLID, line_width, color);//color=RBG(255,0,0)
			SelectObject(hdc, hPen);
			HBRUSH hBrysh = CreateSolidBrush(color);
			SelectObject(hdc, hBrysh);
			::Rectangle(hdc, start_x, start_y, start_x + width, start_y + height);
			DeleteObject(hBrysh);
			DeleteObject(hPen);
			ReleaseDC(hConsole, hdc);
		}
		virtual void info()const
		{
			cout << typeid(*this).name() << endl;
			cout << "Длинна сторон :\t" << width << " , " << height << endl;
			Shape::info();
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
			return radius * radius * M_PI;
		}
		double get_perimeter()const
		{
			return radius * 2 * M_PI;
		}
		void draw()const
		{
			HWND hConsole = GetConsoleWindow();//получаем окно консоли чтобы к нему можно было обратиться
			HDC hdc = GetDC(hConsole);
			HPEN hPen = CreatePen(PS_SOLID, line_width, color);//color=RBG(255,0,0)
			SelectObject(hdc, hPen);
			HBRUSH hBrysh = CreateSolidBrush(color);
			SelectObject(hdc, hBrysh);
			Ellipse(hdc, start_x, start_y, start_x + radius * 2, start_y + radius * 2);
			DeleteObject(hBrysh);
			DeleteObject(hPen);
			ReleaseDC(hConsole, hdc);
		}
		virtual void info()const
		{
			cout << typeid(*this).name() << endl;
			cout << "Радиус :\t" << radius << endl;
			Shape::info();
		}
	};

	class Triangl : public Shape
	{
		POINT a;
		POINT b;
		POINT c;
		double side_AB;
		double side_AC;
		double side_BC;
		double angle_ABC;
		double angle_ACB;
		double angle_BAC;
	public:

		//------get---------
		POINT get_point_a()const
		{
			return a;
		}
		POINT get_point_b()const
		{
			return b;
		}
		POINT get_point_c()const
		{
			return c;
		}
		double get_sideAB()const
		{
			return side_AB;
		}
		double get_sideAC()const
		{
			return side_AC;
		}
		double get_sideBC()const
		{
			return side_BC;
		}
		double get_angle_ABC()const
		{
			return angle_ABC;
		}
		double get_angle_ACB()const
		{
			return angle_ACB;
		}
		double get_angle_BAC()const
		{
			return angle_BAC;
		}
		//------set------
		void set_point_a(int x, int y)
		{
			a.x = x;
			a.y = y;
		}
		void set_point_b(int x, int y)
		{
			b.x = x;
			b.y = y;
		}
		void set_point_c(int x, int y)
		{
			c.x = x;
			c.y = y;
		}
		void set_side_AC(double side_AC)
		{
			this->side_AC = side_AC;
		}
		void set_side_BC(double side_BC)
		{
			this->side_BC = side_BC;
		}
		void set_side_AB(double side_AB)
		{
			this->side_AB = side_AB;
		}
		void set_angle_ABC(double angle_ABC)
		{
			this->angle_ABC = angle_ABC;
		}
		void set_angle_ACB(double angle_ACB)
		{
			this->angle_ACB = angle_ACB;
		}
		void set_angle_BAC(double angle_BAC)
		{
			this->angle_BAC = angle_BAC;
		}
		//-----metods-------
		double triangl_side(int a_x, int a_y, int b_x, int b_y)const
		{
			return sqrt(pow((a_x - b_x), 2) + pow((a_y - b_y), 2));
		}
		
		double triangl_angle(unsigned int side_AB, unsigned int side_AC, unsigned int side_BC)const
		{
			double a = acos((pow(side_AB, 2) + pow(side_AC, 2) - pow(side_BC, 2)) / (2 * side_AB * side_AC));
			return a;
		}

		//-----Constructor-----

		Triangl(
			Color color,
			unsigned int start_x,
			unsigned int start_y,
			unsigned int point_b_x,
			unsigned int point_b_y,
			unsigned int point_c_x,
			unsigned int point_c_y,
			unsigned int line_width) :Shape(color, start_x, start_y, line_width)
		{
			set_point_a(start_x, start_y);
			set_point_b(point_b_x, point_b_y);
			set_point_c(point_c_x, point_c_y);
			side_AB = triangl_side(start_x, start_y, point_b_x, point_b_y);
			side_AC = triangl_side(start_x, start_y, point_c_x, point_c_y);
			side_BC = triangl_side(point_b_x, point_b_y, point_c_x, point_c_y);
			angle_BAC = triangl_angle(side_AB, side_AC, side_BC);
			angle_ABC = triangl_angle(side_AB, side_BC, side_AC);
			angle_ACB = triangl_angle(side_AC, side_BC, side_AB);
		}
		Triangl()//defaut constructor
		{
			set_point_a(0, 0);
			set_point_b(0, 0);
			set_point_c(0, 0);
		}
		/*Triangl(
			Color color,
			unsigned int start_x,
			unsigned int start_y,
			int a,
			int b,
			int a_b,
			
			unsigned int line_width) :Shape(color, start_x, start_y, line_width)
		{
			set_point_a(start_x, start_y);
			set_point_b(start_x + a, start_y);
			set_point_c(start_x+sin(a_b)*b, start_y + b+sin(M_PI/2-a_b)*b );

		}*/
		//-----destructor-----
		~Triangl() {}

		double get_perimeter()const
		{
			return  triangl_side(a.x, a.y, b.x, b.y) +
				triangl_side(a.x, a.y, c.x, c.y) +
				triangl_side(b.x, b.y, c.x, c.y);
		}
		double get_area()const
		{
			double p = get_perimeter() / 2;
			return sqrt(p * (p - triangl_side(a.x, a.y, b.x, b.y)) *
				(p - triangl_side(a.x, a.y, c.x, c.y)) *
				(p - triangl_side(b.x, b.y, c.x, c.y)));
		}


		void draw()const
		{
			POINT point[3] = { a, b, c };
			HWND hConsole = GetConsoleWindow();//получаем окно консоли чтобы к нему можно было обратиться
			HDC hdc = GetDC(hConsole);
			HPEN hPen = CreatePen(PS_SOLID, line_width, color);//color=RBG(255,0,0)
			SelectObject(hdc, hPen);
			HBRUSH hBrysh = CreateSolidBrush(color);
			SelectObject(hdc, hBrysh);
			Polygon(hdc, point, 3);
			DeleteObject(hBrysh);
			DeleteObject(hPen);
			ReleaseDC(hConsole, hdc);
		}
		virtual void info()const
		{
			cout << typeid(*this).name() << endl;
			cout << "Сторона AB :\t" << get_sideAB() << endl;
			cout << "Сторона AC :\t" << get_sideAC() << endl;
			cout << "Сторона BC :\t" << get_sideBC() << endl;
			cout << "Угол ABC: \t" << angle_ABC * 180 / M_PI << endl;
			cout << "Угол BAC: \t" << angle_BAC * 180 / M_PI << endl;
			cout << "Угол ACB: \t" << angle_ACB * 180 / M_PI << endl;
			Shape::info();
		}
	};
	class EquilateralTriangle: public Triangl
	{
	public:
		EquilateralTriangle(
			Color color,
			unsigned int start_x,
			unsigned int start_y,
			double side,
			unsigned int line_width)
		{
			this->color = color;
			this->start_x = start_x;
			this->start_y = start_y;
			this->line_width = line_width;
			set_side_AB(side);
			set_side_AC(side);
			set_side_BC(side);
			set_point_a(start_x, start_y);
			set_point_b(start_x + side, start_y);
			set_point_c(start_x +side - sin(M_PI/6) * side, start_y  + sin(M_PI / 3) * side);
			set_angle_BAC (triangl_angle(side, side, side));
			set_angle_ABC (triangl_angle(side, side, side));
			set_angle_ACB (triangl_angle(side, side, side));

		}

		~EquilateralTriangle() {}
	};
	class IsoscalesTriangle : public Triangl
	{

	public:
		
		IsoscalesTriangle(
			Color color,
			unsigned int start_x,
			unsigned int start_y,
			double side,
			double base,
			unsigned int line_width)
		{
			this->color = color;
			this->start_x = start_x;
			this->start_y = start_y;
			this->line_width = line_width;
			set_side_AB(side);
			set_side_AC(side);
			set_side_BC(base);
			set_point_a(start_x, start_y);
			set_point_b(start_x + base / 2, start_y + sqrt(pow(side, 2) - pow(base / 2, 2)));
			set_point_c(start_x - base / 2, start_y + sqrt(pow(side, 2) - pow(base / 2, 2)));
			set_angle_BAC(triangl_angle(side, side, base));
			set_angle_ABC(triangl_angle(side, base, side));
			set_angle_ACB(triangl_angle(base, side, side));
		}
		~IsoscalesTriangle() {}
	};
	class RightTriangle : public Triangl
	{
	public:

		RightTriangle(
			Color color,
			unsigned int start_x,
			unsigned int start_y,
			double side1,
			double side2,

			unsigned int line_width)
		{
			this->color = color;
			this->start_x = start_x;
			this->start_y = start_y;
			this->line_width = line_width;
			set_side_AB(side1);
			set_side_AC(side2);
			set_side_BC(sqrt(pow(side1, 2) + pow(side2, 2)));
			set_point_a(start_x, start_y);
			set_point_b(start_x, start_y + get_sideAB());
			set_point_c(start_x + get_sideAC(), start_y + get_sideAB());
			set_angle_BAC(triangl_angle(get_sideAB(),get_sideBC(),get_sideAC()));
			set_angle_ABC(M_PI / 2);
			set_angle_ACB(triangl_angle(get_sideAC(), get_sideBC(), get_sideAB()));
		}
		~RightTriangle() {}
	};
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	/*Geometry::Square sq(50, Geometry::Color::blue,300,20,5);
	sq.info();
	Geometry::Rectangle rt(100, 50, Geometry::Color::green, 300, 80, 5);
	rt.info();
	Geometry::Ellips ell(25, Geometry::Color::red, 300, 140, 5);
	ell.info();*/
	Geometry::Triangl tri(Geometry::Color::blue, 350, 20, 320, 20, 300, 40, 1);
	tri.info();
	cout << "--------------------------" << endl;
	Geometry::EquilateralTriangle tri_E(Geometry::Color::red, 350, 200, 50, 1);
	tri_E.info();
	cout << "--------------------------" << endl;
	Geometry::IsoscalesTriangle tri_I(Geometry::Color::red, 350, 400, 50, 80, 1);
	tri_I.info();
	cout << "--------------------------" << endl;
	Geometry::RightTriangle tri_R(Geometry::Color::red, 350, 500, 50, 20, 1);
	tri_R.info();



	/*cout << endl;
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

	Triangl tri(Color::blue, 300, 220, 300, 240, 340, 240, 1);
	cout << tri.get_perimeter() << endl;
	cout << tri.get_area() << endl;
	tri.draw();
	cout << "\n\n\n\n";*/
	
	return 0;
}