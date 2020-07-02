#include <iostream>
#include <ctime>
#include "Time.h"
using namespace std;
int main()
{
	setlocale(LC_ALL, "RUS");
	Time ATime;			//������ �����������
	Time BTime(3, 21);	//����������� � �����������
	Time CTime(4, 55);	//����������� � �����������

	cout << "\n\t�������� ������\n";
	cout << "ATime = ";
	ATime.Show();
	cout << "BTime = ";
	BTime.Show();
	cout << "CTime = ";
	CTime.Show();
	cout << endl;

	//�������� ����� ������������� �������
	cout << "����� ������\n";
	ATime = BTime + CTime;
	cout << "BTime+CTime: ";
	ATime.Show();

	//3 ��������� ����� ������������� �������
	double Scale;		//���������
	cout << "\n�������� ����� �� �����\n";
	cout << "������� ����� = ";
	cin >> Scale;
	ATime = ATime.operator*(Scale);
	cout << "ATime = ATime.operator*(" << Scale << "): ";
	ATime.Show();
	ATime = CTime * Scale;
	cout << "�Time = CTime *" << Scale << ": ";
	ATime.Show();

	//4 ��������
	cout << "\n �������� �����\n";
	ATime = BTime.operator-(CTime);
	ATime = BTime - CTime;
	cout << "\nATime = BTime-CTime: ";
	ATime.Show();

	//5 ������� �� �����
	cout << "\n��������� ����� �� �����\n";
	cout << "������� ����� = ";
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
