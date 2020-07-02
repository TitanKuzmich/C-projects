/**********************************************************
* ����������� � �������������� �������					  *
***********************************************************
* Project type: Win32 Console Application1				  *
* Project name: Laba2									  *
* File name: Laba2.cpp									  *
* language: cpp, MSVS 2010 and above					  *
* Programmers: M3O-107�-18								  *
* �������� ��������� �������������						  *
* Modified by:											  *
* Created: 15.02.2019 Last revision: 25.02.2019			  *
* Comment: ��������� �������							  *
**********************************************************/

#include <iostream> 
#include <fstream> 
#include <string.h>
using namespace std;
const char *FNAME1 = "Array3.txt"; //��� ����� � ��������� ������� 
const char *FNAME2 = "Array4.txt"; //��� ����� � ��������� ������� 
const int NMAX = 10; //������������ ����� ����� 
const int MMAX = 10; //������������ ����� ��������
const int PMAX = 500; //������������ ���������� ���������
ifstream fin(FNAME1);
ifstream gin(FNAME2);

int  ReadFile1(int n, int m, int &N, int &M, const char* FNAME, int Arr1[NMAX][MMAX])					
{

		/*���� ���� �� ������*/
		if (!fin)
			return 1;                            //����� �� ������
		
	
			fin >> N;                                //������ ����� �����
			fin >> M;                                //������ ����� ��������
	
	
		/*���� ���� ����*/
		if (fin.eof())
			return 2;                            //����� �� ������
		
		/*���� � ����� �� �����*/
		if (fin.fail())
			return 3;                            //����� �� ������
	
		for (n = 0; n < N; n++)
		{
			for (m = 0; m < M; m++)
			{
				fin >> Arr1[n][m];

				if ((fin.eof()) && (n < N - 1))         //���� �� ��������� ��������
					return 4;                           //����� �� ������

				if ((fin.eof()) && (m < M - 1))         //���� �� ��������� ��������
					return 5;                           //����� �� ������

				if (fin.fail())                          //���� � ������� �� �����
					return 6;                            //����� �� ������
			}//end for m
		} //end for n

		if (!fin.eof())
			return 7;                                    //����� �� ������
	return 0;
}

int  ReadFile2(int n, int m, int &N, int &M, const char* FNAME, int Arr1[NMAX][MMAX])
{

	/*���� ���� �� ������*/
	if (!gin)
		return 1;                            //����� �� ������


	gin >> N;                                //������ ����� �����
	gin >> M;                                //������ ����� ��������


/*���� ���� ����*/
	if (gin.eof())
		return 2;                            //����� �� ������

	/*���� � ����� �� �����*/
	if (gin.fail())
		return 3;                            //����� �� ������

	for (n = 0; n < N; n++)
	{
		for (m = 0; m < M; m++)
		{
			gin >> Arr1[n][m];

			if ((gin.eof()) && (n < N - 1))         //���� �� ��������� ��������
				return 4;                           //����� �� ������

			if ((gin.eof()) && (m < M - 1))         //���� �� ��������� ��������
				return 5;                           //����� �� ������

			if (gin.fail())                          //���� � ������� �� �����
				return 6;                            //����� �� ������
		}//end for m
	} //end for n

	if (!gin.eof())
		return 7;                                    //����� �� ������
	return 0;
}

void PrintMess(int ErrCode, const char* FNAME)			
{
	switch (ErrCode)
	{
		case 1: cout << "���� <" << FNAME << "> �� ������" << endl; break;

		case 2: cout << "���� <" << FNAME << "> ����" << endl; break;

		case 3: cout << "������� ������� ����������� � ����� " << FNAME << endl; break;

		case 4: cout << "������� " << FNAME << " ��������� �� ���������\n"; break;

		case 5: cout << "������� " << FNAME << " ��������� �� ���������\n"; break;

		case 6: cout << "������� ������� �������� ��������� � ����� "<< FNAME << endl; break;

		case 7: cout << "������� " << FNAME << " ����������� " << endl; break;

		default: cout << "���� <" << FNAME << ">" << endl << "����������� ��� ������ " << ErrCode << endl; break;
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
			cout << "��� ������ ����� ������ �������!" <<  endl;
		}
		if (h < 0)
		{
			cout << "���������� ����� ��� ������ ���������: " << n << endl;
		}
		else
			cout << "���������� ����� ��� ������ ���������: " << h << endl;
	}

void ST(int &m, int &n, int &M, int &N, int Arr[NMAX][MMAX])
	{
		int i = 0; // ��������� ������
		int j = 0; // ���������� ������
		int f = 0; //������� ���������� ���������
		int h = 0; //������� ����� � ������� ����������
		int p = 0; //������ ��� ������
		int P;     //����� ��������� � ������ ��� ������ �������
		int Arr2[PMAX];//������ �� ���������, ������������� ����� ������ ���� ��� ������ �������
		int max = 0; //������������ �� �����

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
			cout << "��� ������������� ���������.\n";
		else
		{
			max = Arr2[0];
			cout << "������������ �� �����, ������������� ����� ������ ����: ";
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
			cout << "�������� �������:\n";
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
	int n = 0;                //��������� ������
	int m = 0;                //���������� ������
	int N;                    //����� �����
	int M;                    //����� ��������
	int Arr1[NMAX][MMAX];     //���������� ������� 1
	int Arr2[NMAX][MMAX];     //���������� ������� 2
	int h = 0;                //������� ����� � ������� ����������

	Task(N, M, n, m, h, Arr1, FNAME1, ReadFile1);
	Task(N, M, n, m, h, Arr2, FNAME2, ReadFile2);
	
	fin.close();
	gin.close();

	system("pause");

	return 0;

} //end main 
/*************** End of Laba.CPP file *********************/
