#include "Prototype.h"
extern ifstream fin;

int ReadF(int &n, int &i, info *&p, dop *&d, const char* FNAME) {
	char Temp;              //временная переменная под ":"

	/*Если файл не найден*/
	if (!fin)
		return 1;                            //выход по ошибке

	fin >> n;

	if (n <= 0)
		return 2;

	p = new info[n];                           //динамический массив структур
	d = new dop[n];

	/*Если файл пуст*/
	if (fin.eof())
		return 3;                            //выход по ошибке

	for (i = 0; i < n; i++) {
		d[i].f = i;
		fin >> p[i].timeh;
		if ((p[i].timeh >= 24) || (p[i].timeh < 0))
			return 4;
		d[i].hour = p[i].timeh;

		fin >> Temp;
		if (Temp != ':')
			return 4;

		fin >> p[i].timem;
		if ((p[i].timem >= 60) || (p[i].timem < 0))
			return 8;
		d[i].minutes = p[i].timem;

		fin >> p[i].marka;

		fin >> p[i].num;
		if ((p[i].num[0] != 'Б') || (p[i].num[1] != '-'))
			return 5;

		fin >> p[i].punkt;

		if ((fin.eof()) && (i < n - 1))
			return 6;
		//pich(j, n, d);
	}

	if ((fin.eof()) && (i = 0))
		return 3;                            //выход по ошибке	

	if (!fin.eof())
		return 7;                                    //выход по ошибке
	return 0;
}

/*Вывод ошибки*/
void PrintMess(info *&p, int &i, int ErrCode, const char* FNAME)
{
	switch (ErrCode)
	{
	case 1: cout << "Файл <" << FNAME << "> не найден " << endl; break;

	case 2: cout << "Неверно введено количество структур в " << FNAME << endl; break;

	case 3: cout << "Файл <" << FNAME << "> пуст " << endl; break;

	case 4: cout << "Неверно введено время в " << i + 1 << "-ой(ей) строке: " << p[i].timeh << "\n"; break;

	case 5: cout << "Неправильный бортовой номер в " << i + 1 << "-ой(ей) строке." << p[i].marka << "\n"; break;

	case 6: cout << "Файл заполнен не до конца" << endl; break;

	case 7: cout << "Файл переполнен" << endl; break;

	case 8: cout << "Неверно введено время в " << i + 1 << "-ой(ей) строке: " << p[i].timem << " минут(а)\n"; break;

	default: cout << "Файл <" << FNAME << ">" << endl << "Неизвестный код ошибки "
		<< ErrCode << endl; break;
	}
}

/*Дорисовка верхней части таблицы*/
void verh() {
	setlocale(LC_ALL, "C");
	cout << char(218) << setfill(char(196)) << setw(14) << char(194)
		<< setfill(char(196)) << setw(13) << char(194)
		<< setfill(char(196)) << setw(15) << char(194)
		<< setfill(char(196)) << setw(18) << char(191) << endl;
	setlocale(LC_ALL, "Russian");
}

/*Шапка таблицы*/
void shap() {
	setlocale(LC_ALL, "C");
	cout << char(179);
	setlocale(LC_ALL, "Russian");
	cout << "Время посадки" << setfill(' ');
	setlocale(LC_ALL, "C");
	cout << char(179);
	setlocale(LC_ALL, "Russian");
	cout << "Марка ЛА" << setw(5) << setfill(' ');
	setlocale(LC_ALL, "C");
	cout << char(179);
	setlocale(LC_ALL, "Russian");
	cout << "Бортовой номер" << setw(1) << setfill(' ');
	setlocale(LC_ALL, "C");
	cout << char(179);
	setlocale(LC_ALL, "Russian");
	cout << "Пункт отправления" << setw(1) << setfill(' ');
	setlocale(LC_ALL, "C");
	cout << char(179) << endl;
	setlocale(LC_ALL, "Russian");
}

/*Содержание таблицы*/
void sod(int &i, dop *d, info *p) {
	setlocale(LC_ALL, "C");
	cout << char(179);
	setlocale(LC_ALL, "Russian");
	if ((p[d[i].f].timeh < 10) && (p[d[i].f].timem < 10))
		cout << '0' << p[d[i].f].timeh << ":" << '0' << p[d[i].f].timem << setw(9)
		<< setfill(' ');
	else if (p[d[i].f].timeh < 10)
		cout << '0' << p[d[i].f].timeh << ":" << p[d[i].f].timem << setw(9) << setfill(' ');
	else if (p[d[i].f].timem < 10)
		cout << p[d[i].f].timeh << ":" << '0' << p[d[i].f].timem << setw(9) << setfill(' ');
	else
		cout << p[d[i].f].timeh << ":" << p[d[i].f].timem << setw(9) << setfill(' ');
	setlocale(LC_ALL, "C");
	cout << char(179);
	setlocale(LC_ALL, "Russian");
	cout << p[d[i].f].marka << setw(13 - strlen(p[d[i].f].marka)) << setfill(' ');
	setlocale(LC_ALL, "C");
	cout << char(179);
	setlocale(LC_ALL, "Russian");
	cout << p[d[i].f].num << setw(15 - strlen(p[d[i].f].num)) << setfill(' ');
	setlocale(LC_ALL, "C");
	cout << char(179);
	setlocale(LC_ALL, "Russian");
	cout << p[d[i].f].punkt << setw(18 - strlen(p[d[i].f].punkt));
	setlocale(LC_ALL, "C");
	cout << char(179) << endl;
}

/*Дорисовка нижней части таблицы*/
void niz() {
	setlocale(LC_ALL, "C");
	cout << char(192) << setfill(char(196)) << setw(14) << char(193)
		<< setfill(char(196)) << setw(13) << char(193)
		<< setfill(char(196)) << setw(15) << char(193)
		<< setfill(char(196)) << setw(18) << char(217) << endl;
	setlocale(LC_ALL, "Russian");
}

/*Дорисовка ячеек таблицы*/
void dor() {
	setlocale(LC_ALL, "C");
	cout << char(195) << setfill(char(196)) << setw(14) << char(197)
		<< setfill(char(196)) << setw(13) << char(197)
		<< setfill(char(196)) << setw(15) << char(197)
		<< setfill(char(196)) << setw(18) << char(180) << endl;
	setlocale(LC_ALL, "Russian");
}

/*Печать*/
void pech(int &i, int &n, dop *&d, info *&p) {

	verh();
	shap();
	dor();

	for (i = 0; i < n; i++) {
		sod(i, d, p);

		if (i < n - 1)
			dor();
	}

	niz();

}

/*Индексная сортировка выбором*/
void sort(int &i, int &n, info *&p, dop *&d) {
	int minh;				//переменная для запоминания часов
	int minm;				//переменная для запоминания минут
	int minf;				//минимальный индекс
	int jMin;				//индекс минимального элемента
	int j = 0;				//индексы для сортировки
	dop temp;				//временная переменная

	for (i = 0; i < n - 1; i++) {
		/*поиск минимального элемента*/
		minh = d[i].hour;
		minm = d[i].minutes;
		minf = d[i].f;
		jMin = i;

		/*поиск минимального элемента в оставшейся части*/
		for (j = i + 1; j < n; j++) {
			/*возможный минимальный элемент*/
			if (d[j].hour < minh) {
				minh = d[j].hour;
				minm = d[j].minutes;
				minf = d[j].f;
				jMin = j;
			}//if p[j].timeh

			if (d[j].hour == minh) {
				if (d[j].minutes < minm) {
					minh = d[j].hour;
					minm = d[j].minutes;
					minf = d[j].f;
					jMin = j;
				}//if p[j].timem
			}//if p[j].timeh
		}//for j

		temp = d[i];
		d[i] = d[jMin];
		d[jMin] = temp;
	}
}
