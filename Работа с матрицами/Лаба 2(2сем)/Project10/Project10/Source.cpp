/**********************************************************
* Информатика и Вычислительная техника					  *
***********************************************************
* Project type: Win32 Console Application1				  *
* Project name: Laba2									  *
* File name: Laba2.cpp									  *
* language: cpp, MSVS 2010 and above					  *
* Programmers: M3O-107Б-18								  *
* Кривонос Александр Александрович						  *
* Modified by:											  *
* Created: 15.02.2019 Last revision: 25.02.2019			  *
* Comment: Двумерные массивы							  *
**********************************************************/

#include <iostream> 
#include <fstream> 
#include <string.h>
using namespace std;
const char *FNAME1 = "Array3.txt"; //имя файла с исходными данными 
const char *FNAME2 = "Array4.txt"; //имя файла с исходными данными 
const int NMAX = 10; //максимальное число строк 
const int MMAX = 10; //максимальное число столбцов
const int PMAX = 500; //максимальное количество элементов
ifstream fin(FNAME1);
ifstream gin(FNAME2);

int  ReadFile1(int n, int m, int &N, int &M, const char* FNAME, int Arr1[NMAX][MMAX])					
{

		/*Если файл не найден*/
		if (!fin)
			return 1;                            //выход по ошибке
		
	
			fin >> N;                                //чтение число строк
			fin >> M;                                //чтение числа столбцов
	
	
		/*Если файл пуст*/
		if (fin.eof())
			return 2;                            //выход по ошибке
		
		/*Если в файле не число*/
		if (fin.fail())
			return 3;                            //выход по ошибке
	
		for (n = 0; n < N; n++)
		{
			for (m = 0; m < M; m++)
			{
				fin >> Arr1[n][m];

				if ((fin.eof()) && (n < N - 1))         //если не полностью заполнен
					return 4;                           //выход по ошибке

				if ((fin.eof()) && (m < M - 1))         //если не полностью заполнен
					return 5;                           //выход по ошибке

				if (fin.fail())                          //если в матрице не числа
					return 6;                            //выход по ошибке
			}//end for m
		} //end for n

		if (!fin.eof())
			return 7;                                    //выход по ошибке
	return 0;
}

int  ReadFile2(int n, int m, int &N, int &M, const char* FNAME, int Arr1[NMAX][MMAX])
{

	/*Если файл не найден*/
	if (!gin)
		return 1;                            //выход по ошибке


	gin >> N;                                //чтение число строк
	gin >> M;                                //чтение числа столбцов


/*Если файл пуст*/
	if (gin.eof())
		return 2;                            //выход по ошибке

	/*Если в файле не число*/
	if (gin.fail())
		return 3;                            //выход по ошибке

	for (n = 0; n < N; n++)
	{
		for (m = 0; m < M; m++)
		{
			gin >> Arr1[n][m];

			if ((gin.eof()) && (n < N - 1))         //если не полностью заполнен
				return 4;                           //выход по ошибке

			if ((gin.eof()) && (m < M - 1))         //если не полностью заполнен
				return 5;                           //выход по ошибке

			if (gin.fail())                          //если в матрице не числа
				return 6;                            //выход по ошибке
		}//end for m
	} //end for n

	if (!gin.eof())
		return 7;                                    //выход по ошибке
	return 0;
}

void PrintMess(int ErrCode, const char* FNAME)			
{
	switch (ErrCode)
	{
		case 1: cout << "Файл <" << FNAME << "> не найден" << endl; break;

		case 2: cout << "Файл <" << FNAME << "> пуст" << endl; break;

		case 3: cout << "Неверно введена размерность в файле " << FNAME << endl; break;

		case 4: cout << "Матрица " << FNAME << " заполнена не полностью\n"; break;

		case 5: cout << "Матрица " << FNAME << " заполнена не полностью\n"; break;

		case 6: cout << "Неверно введены значения элементов в файле "<< FNAME << endl; break;

		case 7: cout << "Матрица " << FNAME << " переполнена " << endl; break;

		default: cout << "Файл <" << FNAME << ">" << endl << "Неизвестный код ошибки " << ErrCode << endl; break;
	}
}
	
void FT(int &n, int &m, int &N, int &M, int &h, int Arr[NMAX][MMAX])
	{
		for (n = 0; n < N; n++)
		{
			for (m = 0; m < M; m++)
			{    
				if (Arr[n][m] % 2 == 0)
				{
					h++;
					break;
				}
			}
		}
		h = n - h;
		if (h == 0)
		{
			cout << "Все строки имеют четный элемент!" <<  endl;
		}
		if (h < 0)
		{
			cout << "Количество строк без четных элементов: " << n << endl;
		}
		else
			cout << "Количество строк без четных элементов: " << h << endl;
	}

void ST(int &m, int &n, int &M, int &N, int Arr[NMAX][MMAX])
	{
		int i = 0; // строковый индекс
		int j = 0; // столбцовый индекс
		int f = 0; //счетчик одинаковых элементов
		int h = 0; //счетчик строк с четными элементами
		int p = 0; //индекс для строки
		int P;     //число элементов в строке для первой матрицы
		int Arr2[PMAX];//строка из элементов, встречающихся более одного раза для первой матрицы
		int max = 0; //максимальное из чисел

		for (i = 0; i < N; i++)
		{
			for (j = 0; j < N; j++)
			{
				for (n = 0; n < N; n++)
				{
					for (m = 0; m < M; m++)
					{
						if (Arr[i][j] == Arr[n][m])
						{
							f++;
							if (f >= 2)
							{
								Arr2[p] = Arr[i][j];
								p++;
							}
						}
					}
				}
				f = 0;
			}
		}
	
		P = p;
		if (p == 0)
			cout << "Нет повторяющихся элементов.\n";
		else
		{
			max = Arr2[0];
			cout << "Максимальное из чисел, встречающихся более одного раза: ";
			for (p = 0; p < P; p++)
			{
				if (Arr2[p] > max)
					max = Arr2[p];
			}
			cout << max << endl;
		}
}

void Task(int &N, int &M, int &n, int &m, int &h, int Arr[NMAX][MMAX], const char *FNAME, int ReadFile(int n, int m, int &N, int &M, const char* FNAME, int Arr1[NMAX][MMAX]))
{
	int ErrCode = ReadFile(n, m, N, M, FNAME, Arr);
		if (ErrCode == 0)
		{
			cout << "Исходная матрица:\n";
			for (n = 0; n < N; n++)
			{
				for (m = 0; m < M; m++)
				{
					cout << Arr[n][m] << " ";
				}
				cout << endl;
			}

			FT(n, m, N, M, h, Arr);
			ST(m, n, M, N, Arr);
		}
		else
			PrintMess(ErrCode, FNAME);
}

int main()
{
	setlocale (LC_ALL, "Russian");
	int n = 0;                //строковый индекс
	int m = 0;                //столбцовый индекс
	int N;                    //число строк
	int M;                    //число столбцов
	int Arr1[NMAX][MMAX];     //объявление матрицы 1
	int Arr2[NMAX][MMAX];     //объявление матрицы 2
	int h = 0;                //счетчик строк с четными элементами

	Task(N, M, n, m, h, Arr1, FNAME1, ReadFile1);
	Task(N, M, n, m, h, Arr2, FNAME2, ReadFile2);
	
	fin.close();
	gin.close();

	system("pause");

	return 0;

} //end main 
/*************** End of Laba.CPP file *********************/
