#pragma once
#include <iomanip>
#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>
#include "locale.h"
using namespace std;
static const char *FNAME = "Info2.txt";
static const int MMAX = 40;

struct info {
	int timeh;
	int timem;
	char marka[MMAX];
	char num[MMAX];
	char punkt[MMAX];
};
struct dop {
	int hour;
	int minutes;
	int f;
};

int ReadF(int &n, int &i, info *&p, dop *&d, const char* FNAME);
void PrintMess(info *&p, int &i, int ErrCode, const char* FNAME);
void verh();
void shap();
void sod(int &i, dop *d, info *p);
void niz();
void dor();
void pech(int &i, int &n, dop *&d, info *&p);
void sort(int &i, int &n, info *&p, dop *&d);