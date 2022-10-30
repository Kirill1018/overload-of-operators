#include <windows.h>
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <stdio.h>
#include <io.h>
#include <fstream>
#include <string>
/*
���������:
������ - write
������ - read, type also
*/
using namespace std;
enum ConsoleColor {
	Black, Blue, Green, Cyan, Red, Magenta, Brown, LightGray, DarkGray,
	LightBlue, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White
};
void SetColor(int text, int background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}
void GotoXY(int X, int Y)
{
	HANDLE hConsole;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord = { X, Y };
	SetConsoleCursorPosition(hStdOut, coord);
}
#include <stdio.h>
/*0 � ������
1 � �����
2 � �������
3 � �������
4 � �������
5 � �������
6 � ������
7 � �����
8 � �����
9 � ����� - �����
A � ������ - �������
B � ������ - �������
� � ������ - �������
E � ������ - ������
F � ���� - �����
system("color F0");*/  // ��������� ������ ���� � ������� ������
class Drob
{
	int ch = 0, zn = 1, _ch = 0, _zn = 1;//��������� � �����������
public:
	//void Set_drob(int _num1, int _num2)
	//{
	//	ch = _num1;
	//	zn = _num2;
	//	if (_num2 != 0) zn = _num2;
	//	else
	//	{
	//		//zn = 1;
	//		cout << "error" << endl;
	//	}
	//}
	//void Set_ch(int _num1)
	//{
	//	ch = _num1;
	//}
	//void Set_zn(int _num2)
	//{
	//	if (_num2 != 0) zn = _num2;
	//	else
	//	{
	//		//zn = 1;
	//		cout << "error" << endl;
	//	}
	//}
	//Drob()//��������� �����������
	//{
	//	ch = 0;
	//	zn = 1;
	//}
	Drob(int _num1, int _num2, int num1, int num2)//����������� � ����������
	{
		ch = _num1;
		zn = _num2;
		_ch = num1;
		_zn = num2;
	}
	Drob(int _num1, int num1)
	{
		ch = _num1;
		_ch = num1;
	}
	Drob(double division)
	{
		fraction_1 = division;
		fraction_2 = division;
		log_val = 0;//�������� ��������
	}
	int Get_ch()
	{
		return ch;
	}
	int Get_ch_()
	{
		return _ch;
	}
	int Get_zn()
	{
		return zn;
	}
	int Get_zn_()
	{
		return _zn;
	}
	void Print_drob()
	{
		SetColor(1, 0);
		cout << fraction_1 << endl;
		SetColor(2, 0);
		cout << fraction_2 << endl;
	}
	void value()
	{
		SetColor(3, 0);
		cout << log_val << endl;
	}
	void Convert_(Drob tmp)
	{
		double rez = (double)tmp.ch / tmp.zn, res = (double)tmp._ch / tmp._zn;
	}
	void add()
	{
		double sum = ch / zn + _ch / _zn;
		cout << sum << endl;
	}
	void cast()
	{
		if (ch > zn)
		{
			int splitting = ch / zn, subtraction = ch - zn;
			cout << splitting << setw(3) << subtraction << "/" << zn << endl;
		}
	}
	void multiplication()
	{
		double multiplier;
		cout << "���������=";
		cin >> multiplier;
		double factor = ch / zn * multiplier;
		cout << factor << endl;
	}
	Drob& operator++ ()
	{
		fraction_1 ++;
		fraction_2 ++;
		return *this;
	}
	Drob& operator-- ()
	{
		fraction_1 --;
		fraction_2 --;
		return *this;
	}
	Drob operator++ (int)
	{
		Drob prev_val = *this;
		++* this;
		return prev_val;
	}
	Drob operator-- (int)
	{
		Drob prev_val = *this;
		--* this;
		return prev_val;
	}
	double fraction_1 = ch / zn, fraction_2 = _ch / _zn;
	bool log_val;
};
Drob operator - (Drob dividing_1, Drob dividing_2)
{
	return Drob(dividing_1.fraction_1 - dividing_2.fraction_2);
}
Drob operator + (Drob dividing_1, Drob dividing_2)
{
	return Drob(dividing_1.fraction_1 + dividing_2.fraction_2);
}
Drob operator * (Drob dividing_1, Drob dividing_2)
{
	return Drob(dividing_1.fraction_1 * dividing_2.fraction_2);
}
Drob operator / (Drob dividing_1, Drob dividing_2)
{
	return Drob(dividing_1.fraction_1 / dividing_2.fraction_2);
}
Drob operator % (Drob dividing_1, Drob dividing_2)
{
	return Drob(dividing_1.fraction_1 / dividing_2.fraction_2 * 100);
}
Drob operator ^ (Drob dividing_1, Drob dividing_2)
{
	return Drob(dividing_1.fraction_1 / dividing_2.fraction_2 * 3);
}
bool operator > (Drob dividing_1, Drob dividing_2)
{
	return dividing_2.fraction_2 > dividing_1.fraction_1;
}
bool operator < (Drob dividing_1, Drob dividing_2)
{
	return dividing_1.fraction_1 < dividing_2.fraction_2;
}
bool operator == (Drob dividing_1, Drob dividing_2)
{
	return dividing_1.fraction_1 == dividing_2.fraction_2;
}
bool operator != (Drob dividing_1, Drob dividing_2)
{
	return dividing_1.fraction_1 != dividing_2.fraction_2;
}
void main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Drob dividing_1(1), dividing_2(2), dividing_3 = dividing_1 - dividing_2;
	SetColor(4, 0);
	cout << "���������=";
	dividing_3.Print_drob();
	dividing_3 = dividing_1 + dividing_2;
	SetColor(5, 0);
	cout << "�����=";
	dividing_3.Print_drob();
	dividing_3 = dividing_1 * dividing_2;
	SetColor(6, 0);
	cout << "������������=";
	dividing_3.Print_drob();
	dividing_3 = dividing_1 / dividing_2;
	SetColor(7, 0);
	cout << "�������=";
	dividing_3.Print_drob();
	dividing_3 = dividing_1 / dividing_2 * 100;
	SetColor(8, 0);
	cout << "������� � ��������=";
	dividing_3.Print_drob();
	dividing_3 = dividing_1 / dividing_2 * 3;
	SetColor(9, 0);
	cout << "�����, ���������� �� ������������� ���������=";
	dividing_3.Print_drob();
	SetColor(10, 0);
	cout << "������ ����� ������ ������=";
	bool log_val = dividing_2 > dividing_1;
	dividing_3.value();
	SetColor(11, 0);
	cout << "������ ����� ������ ������=";
	log_val = dividing_1 < dividing_2;
	dividing_3.value();
	SetColor(12, 0);
	cout << "������ ����� ����� ������=";
	log_val = dividing_1 == dividing_2;
	dividing_3.value();
	SetColor(13, 0);
	cout << "������ ����� ���������� �� ������=";
	log_val = dividing_1 != dividing_2;
	dividing_3.value();
	SetColor(14, 0);
	cout << "���������=";
	dividing_2 = dividing_1 + 1;
	dividing_2.Print_drob();
	SetColor(15, 0);
	cout << "���������=";
	dividing_1--;
	dividing_1.Print_drob();
}