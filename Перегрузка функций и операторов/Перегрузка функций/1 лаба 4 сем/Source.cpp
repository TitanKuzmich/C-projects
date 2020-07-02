/******************************************************
 *	                                                  *
 *	      Информатика и Вычислительная техника        *
 *	                                                  *
 ******************************************************
 *	Progect type: Win32 Console Application1          *
 *	Progect name: Laba2                               *
 *	File name:    Laba2.cpp                           *
 *	language:     cpp, MSVS 2010 and above	          *
 *	Programmer:   M3O-107Б-18                         *
 *	              Кривонос Александр Александрович    *
 *	Created:      21.02.2020 Last revision:21.02.2020 *
 *	Comment:      Программы разделены комментариями   *
 *                "TASK..."                           *
 ******************************************************/

//************TASK 1**************/
//ЯВЛЯЕТСЯ ЛИ ЧИСЛО КВАДРАТОМ КАКОГО-ЛИБО ЦЕЛОГО ЧИСЛА
#include <iostream>
using namespace std;

//*ПРОТОТИПЫ ФУНКЦИЙ*/
template <typename xType>			//шаблон
void sqroot(xType &x);			//Прототип функции

/*ОСНОВНАЯ ПРОГРАММА*/
int main() {
	setlocale(LC_ALL, "RUSSIAN");
	system("color F0");
	int a = 121;
	double b = 129;
	sqroot(a);
	sqroot(b);

	system("pause");
	return 0;
}

/*РЕАЛИЗАЦИЯ ФУНКЦИИ*/
template <typename xType>			//Повторное объявление шаблона
void sqroot(xType &x) {			//реализация функции
	xType sqrx = 1;
	while (sqrx*sqrx < x) {
		sqrx = sqrx + 1;
	}
	cout << "Value of sqrt(): " << sqrx-0.5 << endl;  //вывод значения корня
}


///************TASK 2**************/
//ОПРЕДЕЛЕНИЕ МИНИМУМА ИЗ ЧИСЕЛ С ПОМОЩЬЮ ШАБЛОНА
//#include <iostream>
//using namespace std;
//
///*ПРОТОТИПЫ ФУНКЦИЙ*/
//template <typename xType>			//Шаблон
//xType Min(xType, xType);			//Прототип функции
//
//
///*ОСНОВНАЯ ПРОГРАММА*/
//int main() {
//	//стандартная молитвва
//	setlocale(LC_ALL, "RUSSIAN");
//	system("color F0");
//	int ia = 10, ib = 20;						//Целочисленные переменные
//	float f3 = 1.732f, f2=1.4142f;				//sqrt(3),sqrt(2)
//	double de = 2.718281828, dpi = 3.1457;		//e, pi
//	cout << "\tOOPEx01_01_Перегрузка_Функций.cpp\n";
//	cout << "\t\tПЕРЕГРУЗКА ФУНКЦИЙ\n";
//	//вызов перегруженных функций
//	cout << "\tInt \tia=" << ia << "  \tib= " << ib << "\t\tMax int = " << Min(ia, ib) << endl;
//	cout << "\tDouble \tde=" << de << "  \tdpi= " << dpi << "\t\tMax double = " << Min(de, dpi) << endl;
//	cout << endl;
//	system("pause");
//	return 0;
//}//main
//
//
///*РЕАЛИЗАЦИЯ ФУНКЦИЙ*/
//template <typename xType>
//xType Min(xType x, xType y) {
//	if (x < y)
//		return x;
//	else
//		return y;
//}




///************TASK 3**************/
//ВЫЧИСЛЕНИЕ ПРИМЕРНОГО ЗНАЧЕНИЯ КВАДРАТНОГО КОРНЯ С ПОМОЩЬЮ ЗАДАНИЯ ШАБЛОНА
//#include <iostream>
//using namespace std;
//
//
//template <typename xType>			//Шаблон
//void sqroot(xType &x);			//Прототип функции
//int main() {
//	setlocale(LC_ALL, "RUSSIAN");
//	system("color F0");
//	int a = 121;
//	int b = 129;
//	int c = 144;
//
//	//double f;
//
//	sqroot(a);
//	sqroot(b);
//	sqroot(c);
//
//	system("pause");
//	return 0;
//}
//template <typename xType>
//void sqroot(xType &x) {			//реализация функции вычисления корня
//	xType sqrx = 1;
//	int flag = 0;
//	while (sqrx < x/2) {
//		if (sqrx*sqrx == x)
//			break;
//		sqrx++;
//	}
//	if (sqrx + 1 > x/2)
//	{	
//		flag=1;
//	}
//	if (flag!=1)
//	cout << "Value of sqrt(): " << sqrx << endl;
//	else cout << "Error\n";
//}



///************TASK 4**************/
//ПЕРЕГРУЗКА ФУНКЦИЙ СМЕНЫ РАЗНЫХ ТИПОВ ДАННЫХ
//#include <iostream>
//using namespace std;
//const int NMAX = 5;   //размер массива
//
///*ПРОТОТИПЫ ФУНКЦИЙ*/
////прототип шаблона функции
//template <typename xType>
//void Swap(xType &a, xType &b);
////перегруженный новый наблон
//template <typename XType>
//void Swap(XType *a, XType *b, int xN);
//template <typename XType>   //int, char, double
//void Show(XType a[], int xN); //печать массива
//struct Coord
//{
//	int x;
//	int y;
//};//struct coord
//
///*ОСНОВНАЯ ПРОГРАММА*/
//int main()
//{
//	setlocale(LC_ALL, "RUSSIAN");
//	system("color F0");
//	//	cout << "\t\tШАБЛОНЫ ФУНКЦИЙ\n";
//	//1-----------------------------
//	int n = 10, m = 20;
//	cout << "Before int Swap(): n = " << n << " m = " << m << endl;
//	Swap(n, m);
//	cout << "After int Swap(): n = " << n << " m = " << m << endl;
//
//	//2-----------------------------
//	
//	double  E = 2.71828, Pi = 3.14573;
//	cout << "Before double Swap(): E = " << E << " Pi = " << Pi << endl;
//	Swap(E, Pi);
//	cout << "After double Swap(): E = " << E << " Pi = " << Pi << endl;
//
//	//3-----------------------------
//	Coord A = { 11, 111 };
//	Coord B = { 22, 222 };
//	cout << "Before Coord Swap(): A = (" << A.x << " , " << A.y << ")\t" << "B = (" << B.x << " , " << B.y << ")\n";
//	Swap(A, B);
//	cout << "After Coord Swap(): A = (" << A.x << " , " << A.y << ")\t" << "B = (" << B.x << " , " << B.y << ")\n";
//	//------------------------------
//	//по новому шаблону
//	//объявление и инициализация массива
//	double XVec[NMAX]={11.11, 11.11, 11.11, 11.11, 11.11 };
//	double YVec[NMAX] = { 22.22,22.22,22.22,22.22,22.22 };
//	cout << "\n\tNEW TEMPLATE\n";
//	cout << "Before array Swap():\n XVec = ";
//	Show(XVec, NMAX);   //печать исходного массива
//	cout << "\n YVec = ";
//	Show(YVec, NMAX);   //печать исходного массива
//	cout << "\n";
//	Swap(XVec, YVec, NMAX); //перестановка массивов
//	cout << "After array Swap():\n XVec = ";
//	Show(XVec, NMAX);   //печать исходного массива
//	cout << "\n YVec = ";
//	Show(YVec, NMAX);   //печать исходного массива
//	cout << "\n";
//	system("pause");
//	return 0;
//}//main

///*РЕАЛИЗАЦИЯ ФУНКЦИЙ*/
////определение шаблона функции
//template <typename xType>
//void Swap(xType &a, xType &b) {
//	xType temp; 
//	temp = a;
//	a = b; 
//	b = temp;
//};//Swap()
//
////перегрузка шаблона функции
//template <typename XType>
//void Swap(XType *a, XType *b, int xN) {
//	XType temp;
//	for (int i = 0; i < xN; i++) {
//		temp = a[i];
//		a[i] = b[i];
//		b[i] = temp;
//	}
//};
//
////шаблон печати функции
//template <typename XType>
//void Show(XType a[], int n) {
//	for (int i = 0; i < n; i++) {
//		cout << i[a] << " ";
//	}
//}

///************TASK 5**************/
//ПЕРЕГРУЗКА ФУНКЦИИ ДЛЯ ВЫВОДА ДАТЫ
//#include <iostream>
//using namespace std;
//
///*ПРОТОТИПЫ ФУНКЦИЙ*/
//void Date(char *date);
//void Date(int day, int mounth, int year);
//
///*ОСНОВНАЯ ПРОГРАММА*/
//int main() {
//	setlocale(LC_ALL, "RUSSIAN");
//	system("color F0");
//
//	cout << "\t\tПЕРЕГРУЗКА ФУНКЦИЙ\n";
//	Date((char *) "09/05/1945");
//	Date(9, 05, 1945);
//
//	cout << endl;
//	system("pause");
//	return 0;
//}
//
///*РЕАЛИЗАЦИЯ ФУНКЦИЙ*/
//
///*ДАТА В ВИДЕ СТРОКИ*/
//void Date(char * date)
//{
//	cout << "Дата в виде строки : " << date << "\n";
//}//Date()
//
///*ДАТА В ВИДЕ ЦЕЛЫХ*/
//void Date(int day, int month, int year)
//{
//	cout << "Дата в виде целых: " << day << "/" << month << "/" << year << "\n";
//}//Date()