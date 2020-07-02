#include "Time.h"

//���������� �������

//����������� ��� ����������
Time::Time() {
	Hours = Minutes = 0;
}

//����������� � ����������
Time::Time(int h, int m) {
	Hours = h;
	Minutes = m;
}

//���������� �����
void Time::AddMin(int m) {
	Minutes += m;
	Hours = Hours + Minutes / 60;
	Minutes = Minutes % 60 ;
}

//���������� �����
void Time::AddHr(int h) {
	Hours = Hours + h;
}

//���������� ������� � ����������� �� ���������
void Time::Reset(int h, int m) {
	Hours = h;
	Minutes = m;
}

//���������� ��������� ��������
Time Time:: operator + (const Time & t) const
{
	Time Sum;
	Sum.Minutes = Minutes + t.Minutes;
	Sum.Hours = Hours + t.Hours + Sum.Minutes / 60;
	Sum.Minutes %= 60;
	
	return Sum;
}

//���������� ��������� ���������
Time Time::operator * (double dN) const
{
	Time newTime;
	int totMinA, newTotMin;
	totMinA = Hours * 60 + Minutes;
	newTotMin = totMinA * dN;

	newTime.Hours = newTotMin / 60;
	newTime.Minutes = newTotMin % 60;

	return newTime;
}

//���������� ��������� ���������
Time Time:: operator - (const Time & t) const
{
	Time diff;
	int totMinA, totMinB;

	totMinA = Hours * 60 + Minutes;
	totMinB = t.Hours * 60 + t.Minutes;
	diff.Hours = (totMinA - totMinB) / 60;
	diff.Minutes = (totMinA - totMinB) % 60;

	return diff;
}

//���������� ��������� �������
Time Time:: operator / (double dN) const
{
	Time newTime;
	int totMinA, newTotMin;

	if (dN == 0.0) {
		cout << "ERROR! DIVISION BY ZERO!\n";
		newTime.Hours = Hours;
		newTime.Minutes = Minutes;

		return newTime;
	}

	totMinA = Hours * 60 + Minutes;
	newTotMin = totMinA / dN;

	newTime.Hours = newTotMin / 60;
	newTime.Minutes = newTotMin % 60;

	return newTime;
}

//������ �������
void Time::Show() const {
	cout << "Hours = " << Hours << " Minutes = " << Minutes << endl;
}