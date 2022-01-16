#include<iostream>
#include<fstream>
#include<Windows.h>
#include<string>

//#define WRITE_TO_FILE
#define RIDE_TO_FILE
using namespace std;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
#ifdef WRITE_TO_FILE
	
	cout << "Hello World" << endl;
	ofstream fout("file.txt",ios::app);//ios::app - дозапись в файл
	fout << "Hello World" << endl;
	fout.close();
	system("notepad file.txt");// открытие файла
#endif // WRITE_TO_FILE
#ifdef RIDE_TO_FILE
	const int SIZE = 10240;
	char buffer[SIZE]{};
	ifstream fin;
	fin.open("file.txt");
	if (fin.is_open())
	{
		while (!fin.eof())//пока не конец файла
		{
			//fin >> buffer;
			fin.getline(buffer,SIZE);
			cout << buffer << endl;
		}
	}
	else
	{
		cerr << "Error: file not found";
	}
	fin.close();
#endif // RIDE_TO_FILE



	/*const int n = 5;
	int arr[n];
	FILE* out;
	const char* path = "data.txt";
	for (int i = 0; i < n; i++)
	{
		arr[i] = i + 5;
	}
	if ((fopen_s(&out, path, "w")) != NULL)
		cout << "The file could not be created";
	else
	{
		for (int i = 0; i < n; i++)
		{
			fprintf(out, "%1d ", arr[i]);
			fprintf(out, "\n");
		}
		fclose(out);
	}*/
	return 0;
}