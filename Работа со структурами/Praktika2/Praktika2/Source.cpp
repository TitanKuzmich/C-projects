#include "Prototype.h"

ifstream fin(FNAME);


int main()
{
	setlocale(LC_ALL, "Russian");

	int n = 0;				//���������� ��������
	int i = 0;				//������ ��� ����������
	info *p;				//������������ ������ ��������
	dop *d;					//������������� ������ ��������

	int ErrCode = ReadF(n, i, p, d, FNAME);
	if (ErrCode == 0) {
		cout << "�������� ������:\n";
		pech(i, n, d, p);
		cout << "\n\n\n������������ �� ����������� �������:\n";
		sort(i, n, p, d);
		pech(i, n, d, p);
		delete[]p;
	}
	else
		PrintMess(p, i, ErrCode, FNAME);

	system("pause");
	return 0;
}
