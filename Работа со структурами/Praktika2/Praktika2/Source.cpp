#include "Prototype.h"

ifstream fin(FNAME);


int main()
{
	setlocale(LC_ALL, "Russian");

	int n = 0;				//количество структур
	int i = 0;				//индекс для сортировки
	info *p;				//динамический массив структур
	dop *d;					//дополнительый массив структур

	int ErrCode = ReadF(n, i, p, d, FNAME);
	if (ErrCode == 0) {
		cout << "Исходные данные:\n";
		pech(i, n, d, p);
		cout << "\n\n\nУпорядочение по возрастанию времени:\n";
		sort(i, n, p, d);
		pech(i, n, d, p);
		delete[]p;
	}
	else
		PrintMess(p, i, ErrCode, FNAME);

	system("pause");
	return 0;
}
