/**********************************************************
 *	        ����������� � �������������� �������          *
 **********************************************************
 *	Project type: Win32 Console Application1              *
 *	Project name: Laba2                                   *
 *	File name:    Laba2.cpp                               *
 *	language:     cpp, MSVS 2010 and above	              *
 *	Programmers:  M3O-107�-18                             *
 *	              �������� ��������� �������������        *
 *	Modified by:                                          *
 *	Created:      15.02.2019 Last revision:  25.02.2019   *
 *	Comment:	  ���������� ������                       *
 **********************************************************/

#include <iostream> 
#include <fstream> 
#include <string.h>
using namespace std;
const char *FNAME = "Array.txt";           //��� ����� � ��������� �������
const char *FRES = "Res.txt";   
const char *FRES1 = "Res1.txt";
const int NMAX = 50;                       //������������ ������ ����� 


int main()
{
	char Arr1[NMAX];                          //���������� ����������� ������� 1
	int sizeArr1 = 0;                         //������ ������ 1
	int n = 0;                                //��������� ���������� Arr1
	int bw1 = 0;                              //������ �������
	int ew1 = 0;                              //����� �������
	int lenArr1 = 0;                          //����� �������
	int v = 0;

	char Arr2[NMAX];                          //���������� ����������� ������� 2
	int sizeArr2 = 0;                         //������ ������ 2
	int m = 0;                                //��������� ���������� Arr2
	int bw2 = 0;                              //������ �������
	int ew2 = 0;                              //����� �������
	int lenArr2 = 0;                          //����� �������
	int bw2_2 = 0;                            //������ �����
	int ew2_2 = 0;                            //����� �����
	int lenArr2_2 = 0;                        //����� �����
	int bw2_3 = 0;                            //������ ��������
	int ew2_3 = 0;                            //����� ��������
	int lenArr2_3 = 0;                        //����� ��������

	setlocale(LC_ALL, "RUSSIAN");          //����������� �������� �����	

	//���������� �������� ���������� � �������� ����� ��� ������
	
	ifstream fin(FNAME);
	ofstream rout(FRES);
	ofstream dout(FRES1);
	ifstream rin(FRES);
	ifstream din(FRES1);

	/*���� ���� �� ������*/
	if (!fin)
	{
		cout << "File " << FNAME << " is not found\n";
		fin.close();                          //������� ���� 
		system("pause");
		return 1;                             //����� �� ������ 
	} // end if 

/*���� ���� ����*/
	if (fin.eof())
	{
		cout << "File " << FNAME << " is empty\n";
		fin.close();                          //������� ���� 
		system("pause");
		return 2;                             //����� �� ������ 
	} // end if

/*������ ������ ������� � �� �����*/
	fin.getline(Arr1, sizeof(Arr1));
	cout << "������ �������: " << Arr1 << endl;

	/*���������� �������*/
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

	bw1 = n;               //������� ������ ������ �������

	while ((Arr1[n] != ' ') && (n < sizeArr1))
	{
		n++;
	}

	ew1 = n;               //������� ����� ������ �������
	lenArr1 = ew1 - bw1;   //������� ����� ������ �������
	if (Arr1[ew1] != '\0')
	{
		cout << "�� ����������� ����� �������!" << endl;
		system("pause");
		return 5;
	}

	//cout << "���������� ���� � �������: " << lenArr1 << endl;
	//cout << endl;

	cout << "������ �������:" << endl;
	cout << "������� � ��������: "<<endl;		
	
	/*������ ����� � �� �����*/
	while (fin.getline(Arr2, sizeof(Arr2)))
	{
		//cout << "���: " << Arr2 << endl;

		/*������� ���� �������*/
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

		bw2 = m;               //������� ������ �������

		while ((Arr2[m] != ' ') && (m < sizeArr2))
		{
			m++;
		}

		ew2 = m;              //������� ����� �������
		lenArr2 = ew2 - bw2;  //������� ����� �������
		cout << "\n";

		/*����� �������*/
		for (m = bw2; m <= ew2; m++)
		{
			cout << Arr2[m];
		}

		/*������� ���� �����*/
		for (m = ew2; m < sizeArr2; m++)
		{

			while ((m < sizeArr2) && (Arr2[m] == ' '))
			{
				m++;
			}

			bw2_2 = m;            //������� ������ �����
			cout << Arr2[bw2_2] << ". ";
			
			while ((Arr2[m] != ' ') && (m < sizeArr2))
			{
				m++;
			}
			
		}
				
		if (lenArr1 == lenArr2)
		{
			n = 0; //�������� ��������
			m = 0; //�������� ��������


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
				dout << "������� �� ���������!" << endl;*/

		}//if (lenArr1 == lenArr2)
				
		/*�������� �������� ��� ������������ �����*/
		sizeArr2 = 0;                         //������ ������ 2
		m = 0;                                //��������� ���������� Arr2
		bw2 = 0;                              //������ �������
		ew2 = 0;                              //����� �������
		lenArr2 = 0;                          //����� �������
		bw2_2 = 0;                            //������ �����
		ew2_2 = 0;                            //����� �����
		lenArr2_2 = 0;                        //����� �����
		bw2_3 = 0;                            //������ ��������
		ew2_3 = 0;                            //����� ��������
		lenArr2_3 = 0;                        //����� ��������
	}//while (fin.getline(Arr2, sizeof(Arr2)))

	/*while (rin.getline(Arr2, sizeof(Arr2)))
	{
		cout << Arr2<<endl;
	}*/
	if (v == 0)
	{
		cout << "\n������ �������: " << endl;
		cout << "��� ����������� �������" << endl;
	}
	else
	{
		cout << "\n������ �������:" << endl;
		cout << "����������� �������: " << endl;
		while (din.getline(Arr2, sizeof(Arr2)))
		{
			cout << Arr2 << endl;
		}
	}

	/*������� ����*/
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

