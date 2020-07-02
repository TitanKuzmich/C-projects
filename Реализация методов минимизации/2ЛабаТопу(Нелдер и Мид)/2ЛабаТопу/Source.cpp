#include <iostream>
#include<math.h>
#define N 2
#define A 1					//длина ребра симплекса
using namespace std;

double f1(double P[N]);
double f2(double P[N]);
int proverka(double &fC, double &Fsum, double *C, double *F, double &eps);
void otrajenie(int &k, int &h, double*R, double &fR, double*C, double *P[], double &alfa);

int main() {

	setlocale(LC_ALL, "Russian");

	double alfa;			//коэффициент отражения
	double beta;			//коэффициент растяжения
	double gamma;			//коэффициент сжатия
	double eps;				//точность

	cout << "Введите коэффициент отражения alfa (рекомендумый: 1): \n";
	cin >> alfa;
	cout << "Введите коэффициент растяжения beta (рекомендумый: 0.5): \n";
	cin >> beta;
	cout << "Введите коэффициент сжатия gamma (рекомендумый: 2): \n";
	cin >> gamma;
	cout << "Введите точность eps: \n";
	cin >> eps;

	int s;
	int j;
	int k;
	int l = 0;
	int h = 0;
	int it = 0;				//количество итераций
	double z = 0;				//условие завершения алгоритма
	double F[N + 1];
	double C[N];			//центр тяжести
	double fC;
	double S[N];			//сжатие
	double R[N];			//растяжение
	double fR;
	double E[N];			//отражение
	double P[N + 1][N];
	double SumP;
	double Fsum;

	/*инициализация вершин*/
	for (j = 0; j < N + 1; j++) {
		for (k = 0; k < N; k++) {
			if (j == 0) 
				P[j][k] = 0;
			else {
				if (j == k + 1)
					P[j][k] = A / (N*sqrt(2)*(sqrt(N + 1) - 1 + N));
				else
					P[j][k] = A / (N*sqrt(2)*(sqrt(N + 1) - 1));
			}
		}
	}

	/*расчет значений функции*/
	//while (j!=N) {
		for (j = 0; j < N + 1; j++)
			F[j] = f1(P[j]);
		for (j = 0; j < N + 1; j++) {
			cout << "X" << j + 1 << "( ";
			for (k = 0; k < N; k++)
				cout << P[j][k] << "; ";
			cout << ")\t";
			cout << "F[" << j + 1 << "] = " << F[j] << endl;
		}
		/*поиск индексов h и l из симплекса*/
		for (j = 0; j < N + 1; j++) {
			if (F[j] > F[h])
				h = j;
			if (F[j] < F[l])
				l = j;
		}
	//}

		/*поиск центра тяжести*/
		for (k = 0; k < N; k++) {
			SumP = 0;
			for (j = 0; j < N + 1; j++)
				SumP += P[j][k];
			C[k] = (1.0 / N)*(SumP - P[h][k]);
		}

		/*проверка на выполнение условия завершения алгоритма*/
		//fC = f1(C);
		//for (Fsum = 0, j = 0; j < N + 1; j++)
		//	Fsum += pow(F[j] - fC, 2);
		//z = sqrt((1.0 / (N + 1))*Fsum);
		//if (z <= eps) {
		//	system("pause");
		//	return 0;
		//}

		proverka(fC, Fsum, C, F, eps);

		/*отражение вершин*/
		for (k = 0; k < N; k++)
			R[k] = C[k] + alfa * (C[k] - P[h][k]);
		fR = f1(R);
		if (fR < F[l]) {
			for (k = 0; k <= N - 1; k++)
				E[k] = C[k] + gamma * (R[k] - C[k]);
			if (f1(E) < f1(R))
				P[h][k] = E[k];
			else
				for (k = 0; k <= N - 1; k++)
					P[h][k] = R[k];
		}
		else {
			s = 1;
			for (j = 0; j < N + 1; j++)//Проверка
			{
				if (j != h)
				{
					if (fR < F[j])
					{
						s = 0;
						break;
					}
				}
			}
			if (s)
			{
				if (fR < F[h])
					for (k = 0; k <= N - 1; k++)//Сжатие будет идти в направлении от хН. Замещение вершины.
						P[h][k] = R[k];



				for (k = 0; k <= N - 1; k++)//Сжатие
					S[k] = C[k] + beta * (P[h][k] - C[k]);

				if (f1(S) < F[h])
					for (k = 0; k <= N - 1; k++)//Сжатие оказалось эффективным, использем его. Замещение вершины
						P[h][k] = R[k];
				else
				{//Сжатие оказалось неэффективным, приступаем к редукции. Перерасчет вершин.
					for (j = 0; j < N + 1; j++)
					{
						for (k = 0; k <= N - 1; k++)
						{
							if (j != l)
							{
								P[j][k] = P[l][k] + 0.5*(P[j][k] - P[l][k]);
							}
						}
					}
				}
			}
			else
				for (k = 0; k <= N - 1; k++)
					P[h][k] = R[k];

		}

		it = it + 1;
	
	cout << "Количество итераций: " << it << endl;
	cout << "Оптимальный X1 = " << C[0] << "\tОптимальный X2 = " << C[1] << endl;
	system("pause");
	return 0;
}

double f1(double P[N]) {		//задание функции 1
	double f;
	f = 2 * P[0] * P[0] + P[1] * P[1] - 2 * P[1] * P[0] + 2 * P[0] + 6;
	return f;
}
double f2(double P[N]) {		//задание функции 1
	double f;
	f = pow((P[0] - 2), 4) - pow((P[0] - 2 * P[1]), 2);
	return f;
}
int proverka(double &fC, double &Fsum, double *C, double *F, double &eps) {
	fC = f1(C);
	for (int j = 0; j < N + 1; j++)
		Fsum += pow(F[j] - fC, 2);
	double z = sqrt((1.0 / (N + 1))*Fsum);
	if (z <= eps) {
		system("pause");
		return 0;
	}
}

void otrajenie(int &k, int &h, double*R, double &fR, double*C, double *P[], double &alfa) {
	for (k = 0; k < N; k++)
		R[k] = C[k] + alfa * (C[k] - P[h][k]);
	fR = f1(R);
}