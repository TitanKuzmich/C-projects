#include <iostream>
#include <ctime>
#include "Time.h"
using namespace std;
int main()
{
	setlocale(LC_ALL, "RUS");
	Time ATime;			//пустой конструктор
	Time BTime(3, 21);	//конструктор с параметрами
	Time CTime(4, 55);	//конструктор с параметрами

	cout << "\n\tИСХОДНЫЕ ДАННЫЕ\n";
	cout << "ATime = ";
	ATime.Show();
	cout << "BTime = ";
	BTime.Show();
	cout << "CTime = ";
	CTime.Show();
	cout << endl;

	//Сложение через перегруженную функцию
	cout << "Сумма времен\n";
	ATime = BTime + CTime;
	cout << "BTime+CTime: ";
	ATime.Show();

	//3 Умножение через перегруженную функцию
	double Scale;		//множитель
	cout << "\nУмножить время на число\n";
	cout << "Введите число = ";
	cin >> Scale;
	ATime = ATime.operator*(Scale);
	cout << "ATime = ATime.operator*(" << Scale << "): ";
	ATime.Show();
	ATime = CTime * Scale;
	cout << "АTime = CTime *" << Scale << ": ";
	ATime.Show();

	//4 Разность
	cout << "\n Разность времён\n";
	ATime = BTime.operator-(CTime);
	ATime = BTime - CTime;
	cout << "\nATime = BTime-CTime: ";
	ATime.Show();

	//5 Деление на число
	cout << "\nРазделить время на число\n";
	cout << "Введите число = ";
	cin >> Scale;
	ATime = ATime.operator/(Scale);
	cout << "ATime = ATime.operator/(" << Scale << "): ";
	ATime.Show();
	ATime = CTime / Scale;
	cout << "ATime = CTime /" << Scale << ": ";
	ATime.Show();
	system("PAUSE");
	return 0;
}
