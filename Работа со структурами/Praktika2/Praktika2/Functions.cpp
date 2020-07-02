#include "Prototype.h"
extern ifstream fin;

int ReadF(int &n, int &i, info *&p, dop *&d, const char* FNAME) {
	char Temp;              //��������� ���������� ��� ":"

	/*���� ���� �� ������*/
	if (!fin)
		return 1;                            //����� �� ������

	fin >> n;

	if (n <= 0)
		return 2;

	p = new info[n];                           //������������ ������ ��������
	d = new dop[n];

	/*���� ���� ����*/
	if (fin.eof())
		return 3;                            //����� �� ������

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
		if ((p[i].num[0] != '�') || (p[i].num[1] != '-'))
			return 5;

		fin >> p[i].punkt;

		if ((fin.eof()) && (i < n - 1))
			return 6;
		//pich(j, n, d);
	}

	if ((fin.eof()) && (i = 0))
		return 3;                            //����� �� ������	

	if (!fin.eof())
		return 7;                                    //����� �� ������
	return 0;
}

/*����� ������*/
void PrintMess(info *&p, int &i, int ErrCode, const char* FNAME)
{
	switch (ErrCode)
	{
	case 1: cout << "���� <" << FNAME << "> �� ������ " << endl; break;

	case 2: cout << "������� ������� ���������� �������� � " << FNAME << endl; break;

	case 3: cout << "���� <" << FNAME << "> ���� " << endl; break;

	case 4: cout << "������� ������� ����� � " << i + 1 << "-��(��) ������: " << p[i].timeh << "\n"; break;

	case 5: cout << "������������ �������� ����� � " << i + 1 << "-��(��) ������." << p[i].marka << "\n"; break;

	case 6: cout << "���� �������� �� �� �����" << endl; break;

	case 7: cout << "���� ����������" << endl; break;

	case 8: cout << "������� ������� ����� � " << i + 1 << "-��(��) ������: " << p[i].timem << " �����(�)\n"; break;

	default: cout << "���� <" << FNAME << ">" << endl << "����������� ��� ������ "
		<< ErrCode << endl; break;
	}
}

/*��������� ������� ����� �������*/
void verh() {
	setlocale(LC_ALL, "C");
	cout << char(218) << setfill(char(196)) << setw(14) << char(194)
		<< setfill(char(196)) << setw(13) << char(194)
		<< setfill(char(196)) << setw(15) << char(194)
		<< setfill(char(196)) << setw(18) << char(191) << endl;
	setlocale(LC_ALL, "Russian");
}

/*����� �������*/
void shap() {
	setlocale(LC_ALL, "C");
	cout << char(179);
	setlocale(LC_ALL, "Russian");
	cout << "����� �������" << setfill(' ');
	setlocale(LC_ALL, "C");
	cout << char(179);
	setlocale(LC_ALL, "Russian");
	cout << "����� ��" << setw(5) << setfill(' ');
	setlocale(LC_ALL, "C");
	cout << char(179);
	setlocale(LC_ALL, "Russian");
	cout << "�������� �����" << setw(1) << setfill(' ');
	setlocale(LC_ALL, "C");
	cout << char(179);
	setlocale(LC_ALL, "Russian");
	cout << "����� �����������" << setw(1) << setfill(' ');
	setlocale(LC_ALL, "C");
	cout << char(179) << endl;
	setlocale(LC_ALL, "Russian");
}

/*���������� �������*/
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

/*��������� ������ ����� �������*/
void niz() {
	setlocale(LC_ALL, "C");
	cout << char(192) << setfill(char(196)) << setw(14) << char(193)
		<< setfill(char(196)) << setw(13) << char(193)
		<< setfill(char(196)) << setw(15) << char(193)
		<< setfill(char(196)) << setw(18) << char(217) << endl;
	setlocale(LC_ALL, "Russian");
}

/*��������� ����� �������*/
void dor() {
	setlocale(LC_ALL, "C");
	cout << char(195) << setfill(char(196)) << setw(14) << char(197)
		<< setfill(char(196)) << setw(13) << char(197)
		<< setfill(char(196)) << setw(15) << char(197)
		<< setfill(char(196)) << setw(18) << char(180) << endl;
	setlocale(LC_ALL, "Russian");
}

/*������*/
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

/*��������� ���������� �������*/
void sort(int &i, int &n, info *&p, dop *&d) {
	int minh;				//���������� ��� ����������� �����
	int minm;				//���������� ��� ����������� �����
	int minf;				//����������� ������
	int jMin;				//������ ������������ ��������
	int j = 0;				//������� ��� ����������
	dop temp;				//��������� ����������

	for (i = 0; i < n - 1; i++) {
		/*����� ������������ ��������*/
		minh = d[i].hour;
		minm = d[i].minutes;
		minf = d[i].f;
		jMin = i;

		/*����� ������������ �������� � ���������� �����*/
		for (j = i + 1; j < n; j++) {
			/*��������� ����������� �������*/
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
