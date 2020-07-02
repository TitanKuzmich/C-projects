/******************************************************
 *	                                                  *
 *	      ����������� � �������������� �������        *
 *	                                                  *
 ******************************************************
 *	Progect type: Win32 Console Application1          *
 *	Progect name: Laba2                               *
 *	File name:    Laba2.cpp                           *
 *	language:     cpp, MSVS 2010 and above	          *
 *	Programmer:   M3O-107�-18                         *
 *	              �������� ��������� �������������    *
 *	Created:      21.02.2020 Last revision:21.02.2020 *
 *	Comment:      ��������� ��������� �������������   *
 *                "TASK..."                           *
 ******************************************************/

//************TASK 1**************/
//�������� �� ����� ��������� ������-���� ������ �����
#include <iostream>
using namespace std;

//*��������� �������*/
template <typename xType>			//������
void sqroot(xType &x);			//�������� �������

/*�������� ���������*/
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

/*���������� �������*/
template <typename xType>			//��������� ���������� �������
void sqroot(xType &x) {			//���������� �������
	xType sqrx = 1;
	while (sqrx*sqrx < x) {
		sqrx = sqrx + 1;
	}
	cout << "Value of sqrt(): " << sqrx-0.5 << endl;  //����� �������� �����
}


///************TASK 2**************/
//����������� �������� �� ����� � ������� �������
//#include <iostream>
//using namespace std;
//
///*��������� �������*/
//template <typename xType>			//������
//xType Min(xType, xType);			//�������� �������
//
//
///*�������� ���������*/
//int main() {
//	//����������� ��������
//	setlocale(LC_ALL, "RUSSIAN");
//	system("color F0");
//	int ia = 10, ib = 20;						//������������� ����������
//	float f3 = 1.732f, f2=1.4142f;				//sqrt(3),sqrt(2)
//	double de = 2.718281828, dpi = 3.1457;		//e, pi
//	cout << "\tOOPEx01_01_����������_�������.cpp\n";
//	cout << "\t\t���������� �������\n";
//	//����� ������������� �������
//	cout << "\tInt \tia=" << ia << "  \tib= " << ib << "\t\tMax int = " << Min(ia, ib) << endl;
//	cout << "\tDouble \tde=" << de << "  \tdpi= " << dpi << "\t\tMax double = " << Min(de, dpi) << endl;
//	cout << endl;
//	system("pause");
//	return 0;
//}//main
//
//
///*���������� �������*/
//template <typename xType>
//xType Min(xType x, xType y) {
//	if (x < y)
//		return x;
//	else
//		return y;
//}




///************TASK 3**************/
//���������� ���������� �������� ����������� ����� � ������� ������� �������
//#include <iostream>
//using namespace std;
//
//
//template <typename xType>			//������
//void sqroot(xType &x);			//�������� �������
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
//void sqroot(xType &x) {			//���������� ������� ���������� �����
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
//���������� ������� ����� ������ ����� ������
//#include <iostream>
//using namespace std;
//const int NMAX = 5;   //������ �������
//
///*��������� �������*/
////�������� ������� �������
//template <typename xType>
//void Swap(xType &a, xType &b);
////������������� ����� ������
//template <typename XType>
//void Swap(XType *a, XType *b, int xN);
//template <typename XType>   //int, char, double
//void Show(XType a[], int xN); //������ �������
//struct Coord
//{
//	int x;
//	int y;
//};//struct coord
//
///*�������� ���������*/
//int main()
//{
//	setlocale(LC_ALL, "RUSSIAN");
//	system("color F0");
//	//	cout << "\t\t������� �������\n";
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
//	//�� ������ �������
//	//���������� � ������������� �������
//	double XVec[NMAX]={11.11, 11.11, 11.11, 11.11, 11.11 };
//	double YVec[NMAX] = { 22.22,22.22,22.22,22.22,22.22 };
//	cout << "\n\tNEW TEMPLATE\n";
//	cout << "Before array Swap():\n XVec = ";
//	Show(XVec, NMAX);   //������ ��������� �������
//	cout << "\n YVec = ";
//	Show(YVec, NMAX);   //������ ��������� �������
//	cout << "\n";
//	Swap(XVec, YVec, NMAX); //������������ ��������
//	cout << "After array Swap():\n XVec = ";
//	Show(XVec, NMAX);   //������ ��������� �������
//	cout << "\n YVec = ";
//	Show(YVec, NMAX);   //������ ��������� �������
//	cout << "\n";
//	system("pause");
//	return 0;
//}//main

///*���������� �������*/
////����������� ������� �������
//template <typename xType>
//void Swap(xType &a, xType &b) {
//	xType temp; 
//	temp = a;
//	a = b; 
//	b = temp;
//};//Swap()
//
////���������� ������� �������
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
////������ ������ �������
//template <typename XType>
//void Show(XType a[], int n) {
//	for (int i = 0; i < n; i++) {
//		cout << i[a] << " ";
//	}
//}

///************TASK 5**************/
//���������� ������� ��� ������ ����
//#include <iostream>
//using namespace std;
//
///*��������� �������*/
//void Date(char *date);
//void Date(int day, int mounth, int year);
//
///*�������� ���������*/
//int main() {
//	setlocale(LC_ALL, "RUSSIAN");
//	system("color F0");
//
//	cout << "\t\t���������� �������\n";
//	Date((char *) "09/05/1945");
//	Date(9, 05, 1945);
//
//	cout << endl;
//	system("pause");
//	return 0;
//}
//
///*���������� �������*/
//
///*���� � ���� ������*/
//void Date(char * date)
//{
//	cout << "���� � ���� ������ : " << date << "\n";
//}//Date()
//
///*���� � ���� �����*/
//void Date(int day, int month, int year)
//{
//	cout << "���� � ���� �����: " << day << "/" << month << "/" << year << "\n";
//}//Date()