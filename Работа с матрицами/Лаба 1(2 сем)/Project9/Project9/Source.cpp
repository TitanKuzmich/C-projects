/**********************************************************
 *	        Информатика и Вычислительная техника          *
 **********************************************************
 *	Project type: Win32 Console Application1              *
 *	Project name: Laba2                                   *
 *	File name:    Laba2.cpp                               *
 *	language:     cpp, MSVS 2010 and above	              *
 *	Programmers:  M3O-107Б-18                             *
 *	              Кривонос Александр Александрович        *
 *	Modified by:                                          *
 *	Created:      15.02.2019 Last revision:  25.02.2019   *
 *	Comment:	  Символьные данные                       *
 **********************************************************/

#include <iostream> 
#include <fstream> 
#include <string.h>
using namespace std;
const char *FNAME = "Array.txt";           //имя файла с исходными данными
const char *FRES = "Res.txt";   
const char *FRES1 = "Res1.txt";
const int NMAX = 50;                       //максимальный размер строк 


int main()
{
	char Arr1[NMAX];                          //объявление символьного массива 1
	int sizeArr1 = 0;                         //размер строки 1
	int n = 0;                                //индексная переменная Arr1
	int bw1 = 0;                              //начало фамилии
	int ew1 = 0;                              //конец фамилии
	int lenArr1 = 0;                          //длина фамилии
	int v = 0;

	char Arr2[NMAX];                          //объявление символьного массива 2
	int sizeArr2 = 0;                         //размер строки 2
	int m = 0;                                //индексная переменная Arr2
	int bw2 = 0;                              //начало фамилии
	int ew2 = 0;                              //конец фамилии
	int lenArr2 = 0;                          //длина фамилии
	int bw2_2 = 0;                            //начало имени
	int ew2_2 = 0;                            //конец имени
	int lenArr2_2 = 0;                        //длина имени
	int bw2_3 = 0;                            //начало отчества
	int ew2_3 = 0;                            //конец отчества
	int lenArr2_3 = 0;                        //длина отчества

	setlocale(LC_ALL, "RUSSIAN");          //подключение русского языка	

	//объявление файловой переменной и открытие файла для чтения
	
	ifstream fin(FNAME);
	ofstream rout(FRES);
	ofstream dout(FRES1);
	ifstream rin(FRES);
	ifstream din(FRES1);

	/*Если файл не найден*/
	if (!fin)
	{
		cout << "File " << FNAME << " is not found\n";
		fin.close();                          //закрыть файл 
		system("pause");
		return 1;                             //выход по ошибке 
	} // end if 

/*Если файл пуст*/
	if (fin.eof())
	{
		cout << "File " << FNAME << " is empty\n";
		fin.close();                          //закрыть файл 
		system("pause");
		return 2;                             //выход по ошибке 
	} // end if

/*Чтение данной фамилии и ее вывод*/
	fin.getline(Arr1, sizeof(Arr1));
	cout << "Данная фамилия: " << Arr1 << endl;

	/*Пропускаем пробелы*/
	while (Arr1[n] != '\0')
	{
		n++;
		sizeArr1++;
	}

	n = 0;

	while ((n < sizeArr1) && (Arr1[n] == ' '))
	{
		n++;
	}

	bw1 = n;               //находим начало данной фамилии

	while ((Arr1[n] != ' ') && (n < sizeArr1))
	{
		n++;
	}

	ew1 = n;               //находим конец данной фамилии
	lenArr1 = ew1 - bw1;   //находим длину данной фамилии
	if (Arr1[ew1] != '\0')
	{
		cout << "Вы некорректно ввели фамилию!" << endl;
		system("pause");
		return 5;
	}

	//cout << "Количество букв в фамилии: " << lenArr1 << endl;
	//cout << endl;

	cout << "Первое задание:" << endl;
	cout << "Фамилия и инициалы: "<<endl;		
	
	/*Чтение строк и их вывод*/
	while (fin.getline(Arr2, sizeof(Arr2)))
	{
		//cout << "ФИО: " << Arr2 << endl;

		/*Подсчет букв Фамилии*/
		while (Arr2[m] != '\0')
		{
			m++;
			sizeArr2++;
		}

		m = 0;

		while ((m < sizeArr2) && (Arr2[m] == ' '))
		{
			m++;
		}

		bw2 = m;               //находим начало фамилии

		while ((Arr2[m] != ' ') && (m < sizeArr2))
		{
			m++;
		}

		ew2 = m;              //находим конец фамилии
		lenArr2 = ew2 - bw2;  //находим длину фамилии
		cout << "\n";

		/*Вывод фамилии*/
		for (m = bw2; m <= ew2; m++)
		{
			cout << Arr2[m];
		}

		/*Подсчет букв Имени*/
		for (m = ew2; m < sizeArr2; m++)
		{

			while ((m < sizeArr2) && (Arr2[m] == ' '))
			{
				m++;
			}

			bw2_2 = m;            //находим начало имени
			cout << Arr2[bw2_2] << ". ";
			
			while ((Arr2[m] != ' ') && (m < sizeArr2))
			{
				m++;
			}
			
		}
				
		if (lenArr1 == lenArr2)
		{
			n = 0; //обнуляем значение
			m = 0; //обнуляем значение


			for (n = 0; n <= lenArr1; n++)
			{
				
				if (Arr1[n] == Arr2[m])
				{
					m++;
				}

			}
			if (m == lenArr1)
			{
				dout << Arr2 << endl;
				v=1;
			}
			/*else
				dout << "Фамилии не совпадают!" << endl;*/

		}//if (lenArr1 == lenArr2)
				
		/*Обнуляем значения для последующего цикла*/
		sizeArr2 = 0;                         //размер строки 2
		m = 0;                                //индексная переменная Arr2
		bw2 = 0;                              //начало фамилии
		ew2 = 0;                              //конец фамилии
		lenArr2 = 0;                          //длина фамилии
		bw2_2 = 0;                            //начало имени
		ew2_2 = 0;                            //конец имени
		lenArr2_2 = 0;                        //длина имени
		bw2_3 = 0;                            //начало отчества
		ew2_3 = 0;                            //конец отчества
		lenArr2_3 = 0;                        //длина отчества
	}//while (fin.getline(Arr2, sizeof(Arr2)))

	/*while (rin.getline(Arr2, sizeof(Arr2)))
	{
		cout << Arr2<<endl;
	}*/
	if (v == 0)
	{
		cout << "\nВторое задание: " << endl;
		cout << "Нет совпадающих фамилий" << endl;
	}
	else
	{
		cout << "\nВторое задание:" << endl;
		cout << "Совпадающие фамилии: " << endl;
		while (din.getline(Arr2, sizeof(Arr2)))
		{
			cout << Arr2 << endl;
		}
	}

	/*закрыть файл*/
	cin.get();
	fin.close();                                 
	rout.close();
	dout.close();
	rin.close();
	din.close();

	system("pause");
	return 0;

} //end main
/***************   End of Laba.CPP file   *********************/

