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
 *	Modified by:                                      *
 *	Created:      02.12.2018 Last revision:02.12.2018 *
 *	Comment:	  ����� ��������� ������� ����� �� n  *
 ******************************************************/
#include<iostream> 
#include<fstream> 
#include<iomanip>
#include<cmath>
using namespace std;
const char *FNAME = "Mass.txt";              //��� ����� � ��������� �������
const int NMAX = 10;                         //������������ ������ �������

int main()
{
	int N;                                   //�������� ����� ��������� � �������
	int Mass[NMAX];                          //���������� �������
	int i = 0;                               //��������� ����������
	
	//���������� �������� ���������� � �������� ����� ��� ������
	ifstream fin(FNAME);

	/*���� ���� �� ������*/
	if (!fin)
	{
		cout << "File " << FNAME << " is not found\n";
		fin.close();                         //������� ����
		system("pause");
		return 1;                            //����� �� ������
	} // end if

	fin >> N;                                //������ ����� ��������� ������� �� �����

	/*���� ���� ����*/
	if (fin.eof())
	{
		cout << "File " << FNAME << " is empty\n";
		fin.close();                         //������� ����
		system("pause");
		return 2;                            //����� �� ������
	} // end if

	/*���� � ����� �� �����*/
	if (fin.fail())
	{
		cout << "Failed to read file. " << FNAME << endl;
		fin.close();                         //������� ����
		system("pause");
		return 3;                            //����� �� ������
	} // end if

	else
	{
		cout << "Reading of array\n";       //��������� �������� ������� �� �����
	
		for (i = 0; i < N; i++)
		{
			fin >> Mass[i];                  //������ ��������� ������� �� �����	

			if ((fin.eof()) && (i < N - 1))  //���� �� ��������� ��������
			{
				system("cls");
				cout << "Array " << FNAME << " is not completely filled\n";
				fin.close();                         //������� ����
				system("pause");
				return 4;                           //����� �� ������
			}//if
			if (fin.fail())                        //���� � ������� �� �����
			{
				system("cls");
				cout << "File " << FNAME << " is failed to read\n";
				fin.close();                         //������� ����
				system("pause");
				return 5;                            //����� �� ������
			}//if
			else                                     //������ ��������� �������
			{
				cout << Mass[i] << " ";
			}//else
		} //end for i
		cout << endl;
	}//if
		cout << "Reading of array has ended\n";

		int Min = Mass[0];                       //����������� �������
		int iMin = 0;                            //������ ������������ ��������
		int Max = Mass[0];                       //������������ �������
		int iMax = 0;                            //������ ������������ ��������
		int Temp;                                //��������� �������� ����������
		int n;                                   //����� ������� ���������
		int k;                                   //�������������� ��������� ����������            
		
		for (i = 0; i < N; i++)                  //���� for
		{
			if (Mass[i] < Min)                   //���� ������� ������ �������
			{
				iMin = i;                        //������� ������� ��������� ������ ������������ �������� 
			}//if
			if (Mass[i] > Max)                   //���� ������� ������ �������
			{
				iMax = i;                        //������� ������� ��������� ������ �������� ��������
			}//if
		}//for i

		if (iMin == iMax)                                                           //���� ��� �������� ���������� 
		{
			cout << "All elements are equal. Shift doesn't make sense." << endl;    //��������� �� ������
			system("Pause");
			return 6;
		}//if

		cout << "Enter a number of elements' shifts\n";                         //����������� � �����
		cin >> n;                                                               //���� ����� �� ������� �������� ��������
		n = n % N;                                                              //���������� ������� �� ������� 
		cout << "Shift on: " << n << endl;                                      //���-������

		for (k = 0; k < n; k++)                                                 //���� for k
		{
			Temp = Mass[0];                                                     //��������� ��������� ���������� �������� ������� ��������
			for (i=0; i < N; i++)                                               //���� for i
			{
				Mass[i] = Mass[i+1];                                            //�������� ��������� �������� ����������
			}//for i
			Mass[N - 1] = Temp;                                                 //���������� �������� ��������� �������� ��������� ����������
		}//for k

		cout << "The resulting array:" << endl;                                 

		/*������ ��������������� �������*/
		for (i = 0; i < N; i++)
		{
			cout << Mass[i] << " ";
		}//for i

		cout << endl;

	fin.close();                             //������� ����	
	system("pause");
	return 0;

} //end main

  /***************   End of Laba4.CPP file   *********************/