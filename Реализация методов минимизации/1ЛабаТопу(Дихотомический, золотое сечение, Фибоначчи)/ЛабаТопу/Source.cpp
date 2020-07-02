#include <cmath>
#include <stdio.h>
#include <iostream>
#include <iomanip>

using namespace std;

//метод дихотомии
void dichotomy(double eps, double l, double a, double b, double &aOpt, int &kCount, double          &bOpt, double(*func)(double));
//метод золотого сечения
void goldenRatio(double l, double a, double b, double &aOpt, double &bOpt, int &kCount, double(*func)(double));
//метод Фибоначи
void Fibonachi(double eps, double l, double a, double b, double &aOpt, int &kCount, double &bOpt, double(*func)(double));
//первая функция
double f1(double x);
//вторая функция
double f2(double x);
//число Фибоначи
double Fib(int i);
//вывод шапки
void shapka();
//вывод низа
void niz();
//инициализация переменных
void Initialization(double &eps, double &l, double &A, double &B);
//вывод информации после вычислений
void afterFunc(double aX, double bX, int Count, double(*func)(double x));


int main()
{
	double eps = 0.;		//константа различимости (точность)
	double l = 0.;			//длина интервала неопределенности
	double A = 0.;			//начало интервала
	double B = 0.;			//конец интервала
	double aX = 0.;		//оптимальное значение начала интервала
	double bX = 0.;		//оптимальное значение конца интервала
	int Count = 0;			//счетчик вычисления функций

	cout << "FOR F1(X)" << endl;
	Initialization(eps, l, A, B);    //инициализация переменных для функции 1

	cout << "\nTHE DICHOTOMY METHOD\n";
	dichotomy(eps, l, A, B, aX, Count, bX, (*f1));  //дихотомический метод
	afterFunc(aX, bX, Count, (*f1));				//вывод информации после вычислений

	cout << "\nTHE GOLDEN RATIO METHOD\n";
	goldenRatio(l, A, B, aX, bX, Count, (*f1));		//метод золотого сечения
	afterFunc(aX, bX, Count, (*f1));				//вывод информации после вычислений

	cout << "\nTHE FIBONACCI METHOD\n";
	Fibonachi(eps, l, A, B, aX, Count, bX, (*f1));	//метод Фибоначи
	afterFunc(aX, bX, Count, (*f1));				//вывод информации после вычислений

	cout << "*********************************************" << endl;

	cout << "FOR F2(X)" << endl;
	Initialization(eps, l, A, B);

	cout << "\nTHE DICHOTOMY METHOD\n";
	dichotomy(eps, l, A, B, aX, Count, bX, (*f2));	//дихотомический метод
	afterFunc(aX, bX, Count, (*f2));				//вывод информации после вычислений

	cout << "\nTHE GOLDEN RATIO METHOD\n";
	goldenRatio(l, A, B, aX, bX, Count, (*f2));		//метод золотого сечения
	afterFunc(aX, bX, Count, (*f2));				//вывод информации после вычислений

	cout << "\nTHE FIBONACCI METHOD\n";
	Fibonachi(eps, l, A, B, aX, Count, bX, (*f2));	//метод Фибоначи
	afterFunc(aX, bX, Count, (*f2));				//вывод информации после вычислений

	system("pause");
	return 0;
}

double f1(double x) {		//задание функции 1
	double f;
	f = 6.5609 * x*x + 12.24828 * x - 89.8912; //т.к. ищем max
	return f;
}

double f2(double x) {		//задание функции 2
	double f;
	f = x * x*x - 2 * x*x + x - 1; // т.к ищем min
	return f;
}

void Initialization(double &eps, double &l, double &A, double &B) {
	cout << "Put in eps= ";
	cin >> eps;
	cout << "Put in l= ";
	cin >> l;
	cout << "Put in a= ";
	cin >> A;
	cout << "Put in b= ";
	cin >> B;
}

void afterFunc(double aX, double bX, int Count, double(*func)(double x)) {
	cout << "Function calculated " << Count << " times\n";
	cout << "Optimal x= " << (bX + aX) / 2 << "\n";
	cout << "Optimal F(x)= " << func((bX + aX) / 2) << "\n";
}

void dichotomy(double eps, double l, double a, double b, double &aOpt, int &kCount, double &bOpt, double(*func)(double)) {

	int k = 1;			//счётчик итераций
	double lam;			//лямбда
	double mu;			//мю

	shapka();			//вывод шапки таблицы

	while (b - a >= l) { //пока интервал больше длины интервала неопределенности

		cout << char(179) << setw(5) << k;
		lam = (a + b) / 2 - eps;
		mu = (a + b) / 2 + eps;
		cout << char(179) << setw(10) << setprecision(4) << a
			<< char(179) << setw(10) << setprecision(4) << b
			<< char(179) << setw(10) << setprecision(4) << lam
			<< char(179) << setw(10) << setprecision(4) << mu
			<< char(179) << setw(10) << setprecision(4) << func(lam)
			<< char(179) << setw(10) << setprecision(4) << func(mu)
			<< char(179) << endl;
		cout << char(179) << setw(6);
		cout << char(179) << setw(11) << setprecision(4)
			<< char(179) << setw(11) << setprecision(4)
			<< char(179) << setw(11) << setprecision(4)
			<< char(179) << setw(11) << setprecision(4)
			<< char(179) << setw(11) << setprecision(4)
			<< char(179) << setw(11) << setprecision(4)
			<< char(179) << endl;
		if (func(lam) < func(mu))		//если значение функции в точке лямбда меньше значения в точке мю
			b = mu;
		else
			a = lam;
		k++;
	}//while
	niz();			//закрываем таблицу

	cout << endl;
	aOpt = a;
	bOpt = b;
	kCount = (k - 1) * 2 + 1;
}

void goldenRatio(double l, double a, double b, double &aOpt, double &bOpt, int &kCount, double(*func)(double)) {

	const double al = 0.618;			//значение альфа
	int k = 1;							//иттерация
	double lam = a + (1 - al)*(b - a);	//вычисление значения лямбды
	double mu = a + al * (b - a);		//вычисление значения мю
	double fLam = func(lam);			//вычисление значения функции лямбды
	double fMu = func(mu);				//вычисление значения функции мю

	shapka();

	while (b - a >= l) {			//пока интервал больше длины интервала неопределенности

		cout << char(179) << setw(5) << k;
		cout << char(179) << setw(10) << setprecision(4) << a
			<< char(179) << setw(10) << setprecision(4) << b
			<< char(179) << setw(10) << setprecision(4) << lam
			<< char(179) << setw(10) << setprecision(4) << mu
			<< char(179) << setw(10) << setprecision(4) << func(lam)
			<< char(179) << setw(10) << setprecision(4) << func(mu)
			<< char(179) << endl;
		cout << char(179) << setw(6);
		cout << char(179) << setw(11) << setprecision(4)
			<< char(179) << setw(11) << setprecision(4)
			<< char(179) << setw(11) << setprecision(4)
			<< char(179) << setw(11) << setprecision(4)
			<< char(179) << setw(11) << setprecision(4)
			<< char(179) << setw(11) << setprecision(4)
			<< char(179) << endl;
		if (fLam > fMu) {
			a = lam;
			lam = mu;
			fLam = fMu;
			mu = a + al * (b - a);
			fMu = func(mu);
		}//if

		else {
			b = mu;
			mu = lam;
			fMu = fLam;
			lam = a + (1 - al)*(b - a);
			fLam = func(lam);
		}//else

		k++;			  //инкрементируем иттерационную переменную

		if (b - a < l) {   //если интервал меньше длины интервала неопределенности

			cout << char(179) << setw(5) << k;
			cout << char(179) << setw(10) << setprecision(4) << a
				<< char(179) << setw(10) << setprecision(4) << b
				<< char(179) << setw(10) << setprecision(4) << lam
				<< char(179) << setw(10) << setprecision(4) << mu
				<< char(179) << setw(10) << setprecision(4) << func(lam)
				<< char(179) << setw(10) << setprecision(4) << func(mu)
				<< char(179) << endl;
			cout << char(179) << setw(6);
			cout << char(179) << setw(11) << setprecision(4)
				<< char(179) << setw(11) << setprecision(4)
				<< char(179) << setw(11) << setprecision(4)
				<< char(179) << setw(11) << setprecision(4)
				<< char(179) << setw(11) << setprecision(4)
				<< char(179) << setw(11) << setprecision(4)
				<< char(179) << endl;
		}//endif
	}//while

	niz();//закрываем таблицу

	cout << endl;
	aOpt = a;
	bOpt = b;
	kCount = k + 2;
}

double Fib(int i) {

	if (i < 0) return 0;
	if (i == 0) return 0;
	if (i == 1) return 1;
	return Fib(i - 1) + Fib(i - 2);
}

void Fibonachi(double eps, double l, double a, double b, double &aOpt, int &kCount, double &bOpt, double(*func)(double)) {

	int n = 1;
	int j = 0;
	while (Fib(n) < abs(b - a) / l)				//условие для выбора числа иттераций
		n++;
	double lam = a + ((Fib(n - 2) / Fib(n)) * abs(b - a));	//вычисление значения лямбда
	double mu = a + ((Fib(n - 1) / Fib(n)) * abs(b - a));	//вычисление значения мю
	double fLam = func(lam);					//вычисление значения функции в точке лямбда
	double fMu = func(mu);						//вычисление значения функции в точке мю
	int k = 1;
	double aPrev = a;							//инициализация предыдущего значения а
	double bPrev = b;							//инициализация предыдущего значения b
	double lamPrev = lam;						//инициализация предыдущего значения лямбда

	shapka();									//вывод шапки

	while (k <= (n - 2))
	{
		cout << char(179) << setw(5) << k
			<< char(179) << setw(10) << setprecision(4) << a
			<< char(179) << setw(10) << setprecision(4) << b;
		if (func(lam) > func(mu))
		{
			aPrev = a;
			a = lam;
			lamPrev = lam;
			lam = mu;
			mu = a + (Fib(n - k) / Fib(n - k + 1))*(b - a);
			if (k != (n - 2))
				fMu = func(mu);
		}
		else
		{
			bPrev = b;
			b = mu;
			mu = lam;
			lamPrev = lam;
			lam = a + (Fib(n - k - 1) / Fib(n - k + 1))*(b - a);
			if (k != (n - 2))
				fLam = func(lam);
		}

		if (k == (n - 2)) {
			lam = lamPrev;
			mu = lam + eps;
			if ((func(lam)) > (func(mu))) {

				a = lam;
				b = bPrev;
			}

			else {
				a = aPrev;
				b = mu;

			}
		}

		k++;
		cout << char(179) << setw(10) << setprecision(4) << lam
			<< char(179) << setw(10) << setprecision(4) << mu
			<< char(179) << setw(10) << setprecision(4) << func(lam)
			<< char(179) << setw(10) << setprecision(4) << func(mu)
			<< char(179) << endl;
		cout << char(179) << setw(6);
		cout << char(179) << setw(11) << setprecision(4)
			<< char(179) << setw(11) << setprecision(4)
			<< char(179) << setw(11) << setprecision(4)
			<< char(179) << setw(11) << setprecision(4)
			<< char(179) << setw(11) << setprecision(4)
			<< char(179) << setw(11) << setprecision(4)
			<< char(179) << endl;
	}//while

	niz();			//закрываем таблицу

	cout << endl;
	aOpt = a;
	bOpt = b;
	kCount = k + 1;
}

void shapka() {

	int j = 0;
	//верхняя крышка таблицы
	cout << char(218);
	for (j = 0; j < 5; j++) cout << char(196); cout << char(194);
	for (j = 0; j < 10; j++) cout << char(196); cout << char(194);
	for (j = 0; j < 10; j++) cout << char(196); cout << char(194);
	for (j = 0; j < 10; j++) cout << char(196); cout << char(194);
	for (j = 0; j < 10; j++) cout << char(196); cout << char(194);
	for (j = 0; j < 10; j++) cout << char(196); cout << char(194);
	for (j = 0; j < 10; j++) cout << char(196); cout << char(191) << endl;
	//шапка таблицы
	cout << char(179) << setw(5) << "K"
		<< char(179) << setw(10) << "a(k)"
		<< char(179) << setw(10) << "b(k)"
		<< char(179) << setw(10) << "lam(k)"
		<< char(179) << setw(10) << "mu(k)"
		<< char(179) << setw(10) << "F(lam(k))"
		<< char(179) << setw(10) << "F(mu(k))" << char(179) << endl;
	cout << char(195);
	for (j = 0; j < 5; j++) cout << char(196); cout << char(197);
	for (j = 0; j < 10; j++) cout << char(196); cout << char(197);
	for (j = 0; j < 10; j++) cout << char(196); cout << char(197);
	for (j = 0; j < 10; j++) cout << char(196); cout << char(197);
	for (j = 0; j < 10; j++) cout << char(196); cout << char(197);
	for (j = 0; j < 10; j++) cout << char(196); cout << char(197);
	for (j = 0; j < 10; j++) cout << char(196); cout << char(180) << endl;
}
void niz() {

	int j = 0;
	//низ таблицы
	cout << char(192);
	for (j = 0; j < 5; j++) cout << char(196); cout << char(193);
	for (j = 0; j < 10; j++) cout << char(196); cout << char(193);
	for (j = 0; j < 10; j++) cout << char(196); cout << char(193);
	for (j = 0; j < 10; j++) cout << char(196); cout << char(193);
	for (j = 0; j < 10; j++) cout << char(196); cout << char(193);
	for (j = 0; j < 10; j++) cout << char(196); cout << char(193);
	for (j = 0; j < 10; j++) cout << char(196); cout << char(217);
}
