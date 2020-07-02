/**********************************************************
 *	        ����������� � �������������� �������          *
 **********************************************************
 *	Language:     cpp, MSVS 2010 and above	              *
 *	Programmers:  M3O-107�-18                             *
 *	              �������� ��������� �������������        *
 *	                                                      *
 *	Created:      17.03.2019 Last revision: 20.03.2019    *
 *	Comment:	  ���������� ��������� ������� ��������   *
 **********************************************************/

#include <iostream>
#include <math.h>
#include <ctime>
using namespace std;

int RE(double &a, double &b, int &n)
{
	cout << "������� ������ ������� �������������� �: ";
	cin >> a;
	cout << "������� ������� ������� �������������� b: ";
	cin >> b;

	if (a >= b)
	{
		cout << "b ������ ���� ����� a\n";
		system("Pause");
		return 1;
	}

	cout << "������� ����� ���������: ";
	cin >> n;
	cout << endl;

	if (n <= 0)
	{
		cout << "n ������ ���� ������ 0\n";
		system("Pause");
		return 2;
	}
	return 0;
}

double Pryamoug(int RE(double &a, double &b, int &n))
{
	double a;  //������ ������� ��������������
	double b;  //������� ������� ���������
	double h;  //��� ���������
	int n;  //����� ���������
	double func;// �������
	double x = 0.0; //����������
	int i=0;    //����� ��������
	double Sum=0;//����� �������� �������
	double I;    //�������� ��������� 
	cout << "���������� �� ������ ���������������" << endl;

	RE(a, b, n);

	int start = clock();

	h = (b - a) / n; //���������� ���� ���������
	cout << "��� ���������: " << h << endl;

	/*���������� ������� �� �������*/
	for (x = a; x <= b-h; x = x + h)
	{
		i++;
		func = 1 / (2 + x * x);
		cout << i << ". " << func << endl;
		Sum = Sum + func;
	}

	I = h * Sum;
	cout << "�������� ���������: " << I << endl;	

	int end = clock();
	cout << "����� ������: " << end - start <<" ����������"<< endl;

	return I;
}//Pryamoug

double Simpson(int RE (double &a, double &b, int &n))
{
	double a;  //������ ������� ��������������
	double b;  //������� ������� ���������
	double h;  //��� ���������
	int n;  //����� ���������
	double func;// �������
	double x = 0.0; //����������
	int i = 1;    //����� ��������
	double a1=0; //������ ���������
	double a2=0; //������ ���������
	double a3=0; //������ ���������
	double x1 = 0; //������ ����������
	double xn = 0; //��������� ����������
	double Sum = 0;//����� �������� �������
	double I;    //�������� ���������
	cout << "���������� �� ������ ��������" << endl;

	RE(a, b, n);

	int start = clock();

	h = (b - a) / (2*n); //���������� ���� ���������
	cout << "��� ���������: " << h << endl;
	x1 = 1 / (2 + a * a);
	xn = 1 / (2 + b * b);
	a1 = (x1 + xn)/2;
	cout << i << "." << x1 << endl;
	i++;
	cout << "���������� ������� ��������� �� �������� ��������:" << endl;
	/*���������� ������� ��������� �� �������� ��������*/
	for (x = (a + 2 * h); x <= (b - 2*h); x = (x + 2 * h))
	{
		func = 1 / (2 + x * x);
		cout << i << "." << func << " " << endl;
		i++;
		a2 = a2 + func;
	}

	cout << "���������� �������� ��������� �� �������� ��������:" << endl;

	/*���������� �������� ��������� �� ������ �������� �������*/
	for (x = (a + h); x <= (b - h); x = x + 2 * h)
	{
		func = 1 / (2 + ((x * x - h) + x * x)/2);
		cout << i << "." << func << endl;
		i++;
		a3 = a3 + func;
	}
	cout << i << "." << xn << endl;
	Sum = (a1 + a2 + 2*a3);
	I = (2 * h * Sum) / 3;
	cout << "�������� ���������: " << I << endl;	

	int end = clock();
	cout << "����� ������: " << end - start << " ����������" << endl;

	return I;
}//Simpson
	
int main()
{
	setlocale(LC_ALL, "Russian");	

	Pryamoug(RE);
	Simpson(RE);

	system("Pause");
	return 0;
}// main()