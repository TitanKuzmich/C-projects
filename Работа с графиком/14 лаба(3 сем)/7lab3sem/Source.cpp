/**********************************************************
 *	        Информатика и Вычислительная техника          *
 **********************************************************
 *	Language:     cpp, MSVS 2010 and above	              *
 *	Programmers:  M3O-107Б-18                             *
 *	              Кривонос Александр Александрович        *
 *	Created:      02.12.2019                         	  *
 *	Comment:	  построения графика функции на экране    *
 **********************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h> 
#include <stdlib.h>

const double M_PI = 3.14159265358979323846;				//число пи
double F(double x) { return (x*x)*exp(-x); }			//функция

void diog(double ax, double bx, int nx, int ny);
void gist(double ax, double bx, int nx, int ny);
int main()
{
	//границы по х
	double ax = -1;
	double bx = 2;
	//размерность
	int nx = 78;
	int ny = 25;
	diog(ax, bx, nx, ny);
	//размерность для гистограммы
	gist(ax, bx, nx, ny);
	system("pause");
	return 0;
}
void diog(double ax, double bx, int nx, int ny) {
	//поиск границ у
	double min = F(ax);
	double max = F(ax);
	double hx = (bx - ax) / (nx);
	for (double x = ax; x <= bx; x = x + hx)
	{
		if (F(x) > max)
			max = F(x);
		if (F(x) < min)
			min = F(x);
	}
	
	double hy = (max - min) / ny;
	
	for (double y = max; y >= min - hy * 0.001; y = y - hy)
	{
		//удаление сдвига из-за знака -
		if (y >= 0) printf(" ");
		//значение у
		printf("%.2f%c", y, char(179));
		//печать х
		for (double Fx, x = ax; x <= bx - hx * 0.001; x = x + hx)
		{
			Fx = F(x);
			//ось графика
			if (x > 0 - hx / 2 && x < 0 + hx / 2)
				printf("%c", char(197));
			else if (y > 0 - hy / 2 && y < 0 + hy / 2)
				printf("%c", char(196));
			//если у близок к f(x)
			else if (y > Fx - hy / 2 && y < Fx + hy / 2)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
}
void gist(double ax, double bx, int nx, int ny) {
	FILE* out = fopen("Text.txt", "w"); //открываем файл для записи
	//поиск границ у
	double min = F(ax);
	double max = F(ax);
	double hx = (bx - ax) / (nx);
	for (double x = ax; x <= bx; x = x + hx)
	{
		if (F(x) > max)
			max = F(x);
		if (F(x) < min)
			min = F(x);
	}
	//расчет шага
	double hy = (max - min) / (ny);
	//ход по х
	for (double Fx, x = ax; x <= bx; x = x + hx)
	{
		Fx = F(x);
		//удаление сдвига
		if (F(x) > 0) fprintf(out, " ");
		//ход по х
		for (double y = min; y < max - 0.000001; y = y + hy)
		{
			//если близок к 0 ресуем ось
			if (y > 0 - hy / 2 && y < 0 + hy / 2)
				fprintf(out, "|");
			else if (x > 0 - hx / 2 && x < 0 + hx / 2)
				fprintf(out, "-");
			//у меньше 0 и больше f(x)
			else if (y + hy / 2 > Fx && y < 0)
			{
				//печать числа
				fprintf(out, "%.4f ", y);
				//заполняем y до 0
				while (y < 0)
				{
					fprintf(out, "x");
					y = y + hy;
				}
				fprintf(out, "|");
			}
			else if (y > 0)
				//заполняем y пока у < f(x)
				while (y + 0.00001 < Fx) {
					fprintf(out, "x");
					y = y + hy;
				}
			else if (y < 0)
				fprintf(out, " ");
		}
		if (F(x) > 0) fprintf(out, " %.4f ", Fx);
		fprintf(out, "\n");
	}
	//удаление сдвига графика из-за печати цифр
	fprintf(out, " ");

	//маcштаб функции по у
	int i = 0;
	for (double y = min; y < max - hy - 0.000001; y = y + hy)
	{

		if (i % 10 == 0)
			fprintf(out, "|");
		else
			fprintf(out, "-");
		i++;
	}fprintf(out, "|");
	//соответствующие значения функции
	fprintf(out, "\n "); i = 0;
	for (double y = min; y < max - hy - 0.000001; y = y + hy)
	{
		if (y < 0 && i % 10 == 0)
			fprintf(out, "%.1f", y);
		else if (y > 0 && i % 10 == 0)
			fprintf(out, "%.1f ", y);
		else if (i % 10 >= 4)
			fprintf(out, " ");
		i++;
	}fprintf(out, "%.1f", max);
}