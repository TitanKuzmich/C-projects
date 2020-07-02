#include <iostream>
#include <iomanip>
using namespace std;

const int i = 2;		//����������� ����������
const int j = i + 1;	//����������� ������
double mu = 10;			//����������� ��

//��������� ����������� � ��������������� �������

////������ �����������(������)
//double F1(double x[2]) {
//	if (x[0] + x[1] + 4 < 0)
//		return -1 / (x[0] + x[1] + 4);
//	else
//		return 100000000;
//}
////������ �����������(������)
//double F2(double x[2]) {
//	if (x[0] + x[1]  < 1)
//		return -1 / (x[0] + x[1] - 1);
//	else
//		return 100000000;
//}
////��������������� �������
//double F(double x[2]) {
//	return (-x[0] * x[0] + 2 * x[0] * x[1] + x[1] * x[1] + pow(2.8, -x[0] - x[1]) + mu * (F1(x) + F2(x)));
//}


//������������ ����������� � ��������������� ������� 

double F1(double x[2]) {
	if (x[0]*x[0] - 15*x[0] + x[1]*x[1] < 5)
		return -1 / (x[0] * x[0] - 15 * x[0] + x[1]*x[1] - 5);
	else
		return 100000000;
}
//��������������� �������
double F(double x[2]) {
	return (-pow(x[0], 2) + 2 * x[0] * x[1] + pow(x[1], 2) + pow(2.8, (-x[0] - x[1])) + mu * (F1(x) /*+ F2(x) + F3(x) + F4(x)*/));
}

//����������� � ��������������� ������� �� ���������

//double F(double x[2]) {
//	return (pow((x[0] - 2), 4) + pow((x[0] + 2*x[1]), 2) + mu * (F1(x) + F3(x) + F4(x)));
//}
//������ �����������(������)
//double F1(double x[2]) {
//	if (x[0] * x[0] + x[1] < 0)
//		return -1 / (x[0] * x[0] + x[1]);
//	else
//		return 100000000;
//}
//������ �����������(������)
//double F3(double x[2]) {
//	if (x[0] > 0)
//		return 1 / x[0];
//	else
//		return 100000000;
//}
////��������� �����������(������)
//double F4(double x[2]) {
//	if (x[1] > 0)
//		return 1 / x[1];
//	else
//		return 1000000000;
//}

//������� ��������� ��������� �����������
double D(double xh[2], double xg[2], double xl[2], double xc[2])
{
	return sqrt(1 / (j + 1) * ((F(xh)) - F(xc)) * ((F(xh)) - F(xc)) + ((F(xg)) - F(xc)) * ((F(xg)) - F(xc)) + ((F(xl)) - F(xc)) * ((F(xl)) - F(xc)));
}

void Sort(double x[j][i]);
void NeldMid(double x[2]);

int main() {

	system("color F0");				//��� ����� ����� ������
	double Eps = 0.001;				//��������
	double x[i] = { 5,-5 };			//(-16;-16) - ������������� ����
	double b = 0.1;
	int k = 0;

	cout << char(218) << setfill(char(196)) << setw(5);
	cout << char(194) << setfill(char(196)) << setw(14);
	for (int i = 0; i < 5; i++)
	{
		cout << char(194) << setfill(char(196)) << setw(22);
	}
	cout << char(191) << endl;
	cout << char(179) << "  k "
		<< char(179) << "      mu     "
		<< char(179) << "    X(k+1) = X(mu)   "
		<< char(179) << "      f(X(k+1))      "
		<< char(179) << "         B(x)        "
		<< char(179) << "           b         "
		<< char(179) << "        mu*B(x)      "
		<< char(179) << endl;

	while (mu * (F1(x)/* + F2(x) + F3(x) + F4(x)*/) > Eps)
	{
		NeldMid(x);
		cout << char(195) << setfill(char(196)) << setw(5);
		cout << char(197) << setfill(char(196)) << setw(14);
		for (int i = 0; i < 5; i++)
		{
			cout << char(197) << setfill(char(196)) << setw(22);
		}
		cout << char(180) << endl;

		cout << char(179) << " " << setfill(char(32)) << setw(2) << k << " ";
		cout << char(179) << " " << setfill(char(32)) << setw(11) << mu << " ";
		cout << char(179) << " (" << setfill(char(32)) << setw(7) << round(x[0] * 1000) / 1000 << " ; " << left << setfill(char(32)) << setw(7) << round(x[1] * 1000) / 1000 << right << ") ";
		cout << char(179) << "    " << setfill(char(32)) << setw(11) << F(x) << "      ";
		cout << char(179) << "    " << setfill(char(32)) << setw(11) << (F1(x) /*+ F2(x) + F3(x) + F4(x)*/) << "      ";
		cout << char(179) << "        " << setfill(char(32)) << setw(5) << b << "        ";
		cout << char(179) << "    " << setfill(char(32)) << setw(11) << mu * (F1(x) /*+ F2(x) + F3(x) + F4(x)*/) << "      ";
		cout << char(179) << endl;

		mu = mu * b;
		k++;
	}
	cout << char(192) << setfill(char(196)) << setw(5);
	cout << char(193) << setfill(char(196)) << setw(14);
	for (int i = 0; i < 5; i++)
	{
		cout << char(193) << setfill(char(196)) << setw(22);
	}
	cout << char(217) << endl;
	system("pause");

}

void NeldMid(double x1[2]) {
	int n;							//��������� ����������
	int k = 0;						//���������� ��������
	bool f = 0;						//��������������� ����
	double Temp[i];					//��������� ����������

	double Eps = 0.001;				//��������
	double	a = 1;					//��������� ���������
	double	b = 0.5;				//��������� ������
	double	y = 2;					//��������� ����������
	
	//��������� ����� �����
	double	xHigh[2];				//����� � ���������� ��������� �������
	double	xAverage[2];			//������� ����� �� �������� �������� �������
	double	xLow[2];				//����� � ����� ��������� ��������� �������

	double	centerOfWeight[2];		//����� �������
	double	reflection[2];			//���������� �
	double	reflectionStretch[2];	//���������� � c �����������
	double	reflectionSqueeze[2];	//���������� � � ������

	double	x[j][i] = { {x1[0],x1[1]},{ x1[0] + 3,x1[1] + 2 },{ x1[0] - 3,x1[1] + 2 } };
	do {
		k++;
		Sort(x);					//���������� �����
		/*���������� ��������*/
		for (n = 0; n < i; n++)
		{
			centerOfWeight[n] = 0;
			reflection[n] = 0;
			reflectionStretch[n] = 0;
			reflectionSqueeze[n] = 0;
			xHigh[n] = x[i][n];
			xAverage[n] = x[i - 1][n];
			xLow[n] = x[0][n];
		}
		f = 0;

		//����� ������ �������
		for (n = 0; n < i; n++)
			for (int m = 0; m < i; m++)
				centerOfWeight[n] = centerOfWeight[n] + (x[m][n]);
		centerOfWeight[0] = centerOfWeight[0] / i; centerOfWeight[1] = centerOfWeight[1] / i;

		for (n = 0; n < i; n++)
			reflection[n] = centerOfWeight[n] + a * (centerOfWeight[n] - xHigh[n]);

		if (F(reflection) <= F(xLow))
		{
			for (n = 0; n < i; n++)
				reflectionStretch[n] = centerOfWeight[n] + y * (reflection[n] - centerOfWeight[n]);
			double x7 = F(reflectionStretch);

			if (F(reflectionStretch) < F(reflection))
				for (n = 0; n < i; n++)
					xHigh[n] = reflectionStretch[n];
			else
				for (n = 0; n < i; n++)
					xHigh[n] = reflection[n];
		}
		else if (F(xLow) <= F(reflection) && F(reflection) <= F(xAverage))
		{
			for (n = 0; n < i; n++)
				xHigh[n] = reflection[n];
		}
		else if (F(xAverage) <= F(reflection) && F(reflection) <= F(xHigh))
		{
			for (n = 0; n < i; n++)
			{
				Temp[n] = reflection[n];
				reflection[n] = xHigh[n];
				xHigh[n] = Temp[n];
				f = 1;
			}
		}
		else if (F(xHigh) <= F(reflection))
			f = 1;
		if (f) {
			for (n = 0; n < i; n++)
				reflectionSqueeze[n] = centerOfWeight[n] + b * (xHigh[n] - centerOfWeight[n]);

			if (F(reflectionSqueeze) < F(xHigh))
				for (n = 0; n < i; n++)
					xHigh[n] = reflectionSqueeze[n];

			if (F(reflectionSqueeze) >= F(xHigh))
			{
				for (n = 0; n < i; n++)
				{
					x[i][n] = xHigh[n];
					x[i - 1][n] = xAverage[n];
					x[0][n] = xLow[n];
				}
				Sort(x);							//���������� �����
				for (n = 0; n < i; n++)
				{
					xHigh[n] = x[i][n];
					xAverage[n] = x[i - 1][n];
					xLow[n] = x[0][n];
				}
				for (n = 0; n < i; n++)
				{
					xHigh[n] = (xHigh[n] + xLow[n]) / 2;
					xAverage[n] = (xAverage[n] + xLow[n]) / 2;
				}
			}
		}
		for (n = 0; n < i; n++)
		{
			x[i][n] = xHigh[n];
			x[i - 1][n] = xAverage[n];
			x[0][n] = xLow[n];
		}
	} while (fabs(D(xHigh, xAverage, xLow, centerOfWeight)) > Eps);

	Sort(x);					//���������� �����
	for (n = 0; n < i; n++)
		x1[n] = xLow[n];
}

void Sort(double x[j][i])
{
	double Min;                	//����������� �������
	int jMin;					//������ ������������ ��������
	int iSort;					//������� ��������������� �������
	int k;						//��������� ����������
	double Temp[i];				//�������� ����������

	for (iSort = 0; iSort < j - 1; iSort++)
	{
		//��������� ������ ������� �� ��������������� �� �����������
		Min = F(x[iSort]);				//�������
		jMin = iSort;					//��� ������

		//���� ����������� ������� � ���������� ����� �������
		for (k = iSort + 1; k < j; k++)
		{
			if (F(x[k]) < Min)		//��������� �������� �� �����������
			{
				//���������� ����������� ������� � ��� �����
				Min = F(x[k]);
				jMin = k;
			}
		}

		/*����� ������� � ��������������� ����� �������
		������ ��� �� ����� ������� � ��������������� ����� �������
		������ �������� �������*/
		for (k = 0; k < i; k++)
		{
			Temp[k] = x[iSort][k];
			x[iSort][k] = x[jMin][k];
			x[jMin][k] = Temp[k];
		}
	} //for iSort
}