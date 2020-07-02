/******************************************************
 *	                                                  *
 *	      Информатика и Вычислительная техника        *
 *	                                                  *
 ******************************************************
 *	Progect type: Win32 Console Application1          *
 *	Progect name: Laba2                               *
 *	File name:    Laba2.cpp                           *
 *	language:     cpp, MSVS 2010 and above	          *
 *	Programmer:   M3O-107Б-18                         *
 *	              Кривонос Александр Александрович    *
 *	Modified by:                                      *
 *	Created:      02.12.2018 Last revision:02.12.2018 *
 *	Comment:	  Сдвиг элементов массива влево на n  *
 ******************************************************/
#include<iostream> 
#include<fstream> 
#include<iomanip>
#include<cmath>
using namespace std;
const char *FNAME = "Mass.txt";              //имя файла с исходными данными
const int NMAX = 10;                         //максимальный размер массива

int main()
{
	int N;                                   //реальное число элементов в массиве
	int Mass[NMAX];                          //объявление массива
	int i = 0;                               //индексная переменная
	
	//объявление файловой переменной и открытие файла для чтения
	ifstream fin(FNAME);

	/*Если файл не найден*/
	if (!fin)
	{
		cout << "File " << FNAME << " is not found\n";
		fin.close();                         //закрыть файл
		system("pause");
		return 1;                            //выход по ошибке
	} // end if

	fin >> N;                                //чтение числа элементов массива из файла

	/*Если файл пуст*/
	if (fin.eof())
	{
		cout << "File " << FNAME << " is empty\n";
		fin.close();                         //закрыть файл
		system("pause");
		return 2;                            //выход по ошибке
	} // end if

	/*Если в файле не число*/
	if (fin.fail())
	{
		cout << "Failed to read file. " << FNAME << endl;
		fin.close();                         //закрыть файл
		system("pause");
		return 3;                            //выход по ошибке
	} // end if

	else
	{
		cout << "Reading of array\n";       //считываем элементы массива из файла
	
		for (i = 0; i < N; i++)
		{
			fin >> Mass[i];                  //чтение элементов массива из файла	

			if ((fin.eof()) && (i < N - 1))  //если не полностью заполнен
			{
				system("cls");
				cout << "Array " << FNAME << " is not completely filled\n";
				fin.close();                         //закрыть файл
				system("pause");
				return 4;                           //выход по ошибке
			}//if
			if (fin.fail())                        //если в массиве не числа
			{
				system("cls");
				cout << "File " << FNAME << " is failed to read\n";
				fin.close();                         //закрыть файл
				system("pause");
				return 5;                            //выход по ошибке
			}//if
			else                                     //печать исходного массива
			{
				cout << Mass[i] << " ";
			}//else
		} //end for i
		cout << endl;
	}//if
		cout << "Reading of array has ended\n";

		int Min = Mass[0];                       //минимальный элемент
		int iMin = 0;                            //индекс минимального элемента
		int Max = Mass[0];                       //максимальный элемент
		int iMax = 0;                            //индекс минимального элемента
		int Temp;                                //временное значение переменной
		int n;                                   //число сдвигов элементов
		int k;                                   //дополнительная индексная переменная            
		
		for (i = 0; i < N; i++)                  //цикл for
		{
			if (Mass[i] < Min)                   //если элемент меньше данного
			{
				iMin = i;                        //данному индексу присвоить индекс минимального элемента 
			}//if
			if (Mass[i] > Max)                   //если элемент больше данного
			{
				iMax = i;                        //данному индексу присвоить индекс большего элемента
			}//if
		}//for i

		if (iMin == iMax)                                                           //если все элементы одинаковые 
		{
			cout << "All elements are equal. Shift doesn't make sense." << endl;    //сообщение об ошибке
			system("Pause");
			return 6;
		}//if

		cout << "Enter a number of elements' shifts\n";                         //приглашение к вводу
		cin >> n;                                                               //ввод числа на которое сдвинуть элементы
		n = n % N;                                                              //вычисление остатка от деления 
		cout << "Shift on: " << n << endl;                                      //эхо-печать

		for (k = 0; k < n; k++)                                                 //цикл for k
		{
			Temp = Mass[0];                                                     //присвоить временной переменной значение первого элемента
			for (i=0; i < N; i++)                                               //цикл for i
			{
				Mass[i] = Mass[i+1];                                            //элементу присвоить значение следующего
			}//for i
			Mass[N - 1] = Temp;                                                 //последнему элементу присвоить значение временной переменной
		}//for k

		cout << "The resulting array:" << endl;                                 

		/*Печать результирующего массива*/
		for (i = 0; i < N; i++)
		{
			cout << Mass[i] << " ";
		}//for i

		cout << endl;

	fin.close();                             //закрыть файл	
	system("pause");
	return 0;

} //end main

  /***************   End of Laba4.CPP file   *********************/