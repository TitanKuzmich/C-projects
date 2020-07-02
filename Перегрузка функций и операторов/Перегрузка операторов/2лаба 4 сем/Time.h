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
		Time();										//конструктор без параметров
		Time(int h, int m = 0);						//конструктор с параметрами
		void AddMin(int m);							//добавление минут
		void AddHr(int h);							//добавление часов
		void Reset(int h = 0, int m = 0);			//перезапись времени с параметрами по умолчанию
		Time operator + (const Time & t)const;		//перегрузка оператора сложения
		Time operator * (double dN) const;			//перегрузка оператора умножения
		Time operator - (const Time & t) const;		//перегрузка оператора вычитания
		Time operator / (double dN) const;			//перегрузка оператора деления
		void Show() const;							//печать времени
};
#endif