#pragma once
#ifndef _TIME0_h
#define _TIME0_H
#include <iostream>
using namespace std;
class Time
{
	private:
		int Hours;
		int Minutes;
	public:
		Time();										//����������� ��� ����������
		Time(int h, int m = 0);						//����������� � �����������
		void AddMin(int m);							//���������� �����
		void AddHr(int h);							//���������� �����
		void Reset(int h = 0, int m = 0);			//���������� ������� � ����������� �� ���������
		Time operator + (const Time & t)const;		//���������� ��������� ��������
		Time operator * (double dN) const;			//���������� ��������� ���������
		Time operator - (const Time & t) const;		//���������� ��������� ���������
		Time operator / (double dN) const;			//���������� ��������� �������
		void Show() const;							//������ �������
};
#endif