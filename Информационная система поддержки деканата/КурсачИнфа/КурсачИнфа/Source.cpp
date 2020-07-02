#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<locale.h>
#include<conio.h>
#include <Windows.h>

using namespace std;

////////////////////////////////////////////////////////////////////
/**************************���������*******************************/
////////////////////////////////////////////////////////////////////

struct studentInf {				//��������� ���������
	char name[25];				//��� ��������
	char surname[25];			//������� ��������
	char secondname[25];		//�������� ��������
	char enterYear[5];			//��� �����������
	char group[12];				//������
	char adress[50];			//�����
	char phone[13];				//�������
};
struct teacherInf {				//��������� ��������������
	char tName[25];				//��� �������������
	char tSurname[25];			//������� �������������
	char tSecondname[25];		//�������� �������������
	char tPhone[13];			//������� �������������
};
struct scheduleInf {			//��������� ����������
	int numWeek;				//����� ������
	char week[10];				//"������"
	char date[9];				//����
	char subject[15];			//�������
	char classTime[6];			//����� ��������
	char numOfAudience[10];		//����� ���������
	char teacherN[25];			//��� �������������
	char teacherS[25];			//������� �������������
	char teacherSN[25];			//�������� �������������
};
struct authorizationData {		//��������� ������������
	char login[25];				//�����
	char pasword[25];			//������
};
struct absentInf {				//��������� �������������
	char sName[256];			//��� ��������������
	char sSurName[256];			//������� ��������������
	char sSecondName[256];		//�������� ��������������
	char absentDate[10];		//����, ����� ������������
	char abSubject[15];			//�������, �� ������� ������������
};

////////////////////////////////////////////////////////////////////
/***********************��������� �������**************************/
////////////////////////////////////////////////////////////////////

/******************������� ������������� ��������******************/
int initialization(FILE *students, int &strCountS, studentInf *student,
	FILE *teachers, int &strCountT, teacherInf *teacher,
	FILE *Schedule, int &strCountSc, scheduleInf *schedule,
	int *weekIndex, int *dateIndex, int &sizeWeekIndex, int &sizeDateIndex,
	int &strCountAb, absentInf *absent, FILE *Absent, int *absentIndex, int & sizeAbsentIndex);
/****************������� ������ ������ ���������******************/
void getStudents(int &strCountS, studentInf *student);
/*****************������� ���������� ��������*********************/
int AddStudent(FILE *students, int &strCountS, studentInf *student);
/******************������� �������� ��������**********************/
int DeleteStudent(FILE *students, int &strCountS, studentInf *student);
/**************������� ������ ������ ��������������***************/
void getTeachers(int &strCountT, teacherInf *teacher);
/***************������� ���������� �������������*******************/
int AddTeacher(FILE *teachers, int &strCountT, teacherInf *teacher);
/****************������� �������� �������������********************/
int DeleteTeacher(FILE *teachers, int &strCountT, teacherInf *teacher);
/***************������� ������ ���������� ������*******************/
void getSchedule(int &strCountSc, scheduleInf *schedule, int *weekIndex, int *dateIndex, int &sizeWeekIndex, int &sizeDateIndex);
/**********������� ������ ���������� ��� �������������*************/
void GetScheduleForT(int &strCountSc, scheduleInf *schedule, int *weekIndex, int *dateIndex, int &sizeWeekIndex, int &sizeDateIndex);
/*****************������� ������ �������������*********************/
void getAbsent(int &strCountAb, absentInf *absent, int &strCountS, studentInf *student, int *absentIndex, int &sizeAbsentIndex);

////////////////////////////////////////////////////////////////////
/******************************************************************/
////////////////////////////////////////////////////////////////////

int main() {
	setlocale(LC_ALL, "Russian");								//����������� �������� �����
	SetConsoleCP(1251);											//��������� ���������
	SetConsoleOutputCP(1251);									//��������� ��������� �������
	FILE *authorization = fopen("authorization.bin", "rb");		//���� � ������� �����������
	int i = -1;													//���������� ��� ����������� ��������
	int l = -1;													//���������� ��� ���������� ���������
	int h = -1;													//���������� ��� ������ �������� ��� ��������� ������ ���������
	int p = -1;													//���������� ��� ������ �������� ��� ��������� ������ ��������������
	bool signedIn = false;										//���������� ������������� ����� � �������
	/*��� ��������*/
	FILE *students = NULL;										//���� � ������� ���������
	int strCountS = 0;											//���������� ����� � ����� ���������
	studentInf student[256];									//������ �������� ���������
	/*��� �������*/
	FILE *teachers = NULL;										//���� � ������� ��������������int strCountT = 0;
	int strCountT = 0;											//���������� ����� � ����� ��������������
	teacherInf teacher[256];									//������ �������� ��������������
	/*��� ����������*/
	FILE *Schedule = NULL;										//���� � ����������� � ��������������
	int strCountSc = 0;											//���������� ����� � ����� ����������
	scheduleInf schedule[256];									//������ �������� ����������
	int dateIndex[256];											//������ �������� ��� � ����� ����������
	int weekIndex[256];											//������ �������� ������ � ����� ����������
	int sizeWeekIndex = 0;										//������ ��� ������ �������� ������
	int sizeDateIndex = 0;										//������ ��� ������ �������� ���
	/*��� �������������*/
	FILE *Absent = NULL;										//���� � ����������� � ���������
	absentInf absent[256];										//������ �������� �������������
	int strCountAb = 0;											//���������� ����� � ����� ��������
	int absentIndex[256];										//������ �������� ��� ������������� 
	int sizeAbsentIndex = 0;									//������ ��� ������� �������� ��� ������������� 
	/*��� �����������*/
	authorizationData signIn[3];								//������ �������� ��������������� ������
	char log[256];												//�����
	char pas[256];												//������
	int f = 0;													//������ ��� ������ � ������� �������� �����������
	char c;														//���������� ��� ���������� �������

	for (int i = 0; i < 3; i++) {								
		while (1) {												//����������� ����
			fread(&signIn[i].login[f], sizeof(char), 1, authorization); //��������� �������� �����
			if (signIn[i].login[f] == ' ') {					//���� ������ - ������, �� �������� ���������� ������
				signIn[i].login[f] = '\0';
				f = 0;
				break;
			}
			else
				f++;											//����� ����������� ������ ��� ������
		}
		while (1) {												//����������� ����
			fread(&signIn[i].pasword[f], sizeof(char), 1, authorization); //��������� �������� ������
			if ((signIn[i].pasword[f] == '\r') || (signIn[i].pasword[f] == '\n')) { //���� ������ - "������� �������" ��� "����� ������", �� �������� ���������� ������
				signIn[i].pasword[f] = '\0';
				f = 0;
				break;
			}
			else
				f++;											//����� ����������� ������ ��� ������
		}
		fread(&c, sizeof(char), 1, authorization);				//��������� ������ ����� ������� � �������
	}
	printf("������� � ������� ������.\n������� �����: ");
	scanf("%s", &log);											//��������� ��������� ����� 
	printf("������� ������: ");
	scanf("%s", &pas);											//��������� ��������� ������

	for (i = 0; i < 3; i++) {
		if ((strcmp(signIn[i].login, log) == 0) && ((strcmp(signIn[i].pasword, pas)) == 0)) {	//������� ����������� �������
			signedIn = true;
			break;
		}
	}

	system("cls");			//������� �����
	if (signedIn == true) { //���� ������������ �������������
		while (l != 0) {	

			switch (i) {
			case 0:
				initialization(students, strCountS, student,						//������������� ��������
					teachers, strCountT, teacher, Schedule, strCountSc, schedule, 
					weekIndex, dateIndex, sizeWeekIndex, sizeDateIndex, 
					strCountAb, absent, Absent, absentIndex, sizeAbsentIndex);

				printf("�� ����� ��� ������� ������� ������������� ��������.\n\
1. ���������� ������ ������\n\
2. ���������� ������ ��������������\n\
3. ���������� ���������� ������� ������\n\
4. ���������� ���������� ������� � �������������\n\
5. ���������� ����������� ��������\n\
6. �������� ������ ���������\n\
7. �������� ������ ��������������\n\
0. ����� �� ���������\n");


				printf("�������� ��������: \n");
				scanf("%d", &l);						//��������� ��������� �����
				switch (l) {
				case 1:
					getStudents(strCountS, student);		//������� ������ ���������
					break;
				case 2:
					getTeachers(strCountT, teacher);		//������� ������ ��������������
					break;
				case 3:
					getSchedule(strCountSc, schedule, weekIndex, dateIndex, sizeWeekIndex, sizeDateIndex);		//������� ���������� ��� ������
					break;
				case 4:
					GetScheduleForT(strCountSc, schedule, weekIndex, dateIndex, sizeWeekIndex, sizeDateIndex);	//������� ���������� ��� �������������
					break;
				case 5:
					getAbsent(strCountAb, absent, strCountS, student, absentIndex, sizeAbsentIndex);			//������� ������� ��������
					break;
				case 6:
					system("cls");
					printf("�������� ���������� ��������:\n1. �������� ��������\n2. ������� ��������\n");
					scanf("%d", &h);
					switch (h) {
					case 1:
						AddStudent(students, strCountS, student);		//�������� ��������
						break;
					case 2:
						DeleteStudent(students, strCountS, student);	//������� ��������
						break;
					default:
						printf("\n��������� ������� �� ����������!\n");
						break;
					}
					break;
				case 7:
					system("cls");
					printf("�������� ���������� ��������:\n1. �������� �������������\n2. ������� �������������\n");
					scanf("%d", &p);
					switch (p) {
					case 1:
						AddTeacher(teachers, strCountT, teacher);		//�������� �������������
						break;
					case 2:
						DeleteTeacher(teachers, strCountT, teacher);	//������� �������������
						break;
					default:
						printf("\n��������� ������� �� ����������!\n");
						break;
					}
					break;
				case 0:
					break;
				default:
					printf("\n��������� ������� �� ����������!\n");
					break;
				}
				break;
			case 1:
				initialization(students, strCountS, student,						//������������� �������� 
					teachers, strCountT, teacher, Schedule, strCountSc, schedule, 
					weekIndex, dateIndex, sizeWeekIndex, sizeDateIndex, 
					strCountAb, absent, Absent, absentIndex, sizeAbsentIndex);
				printf("�� ����� ��� ������� ������� �������������.\n\
�������� ���������� ��������:\n1. ���������� ������ ������\n\
2. ���������� ������ ��������������\n\
3. ���������� ���������� ������� � �������������\n\
0. ����� �� ���������\n");
				scanf("%d", &l);
				switch (l) {
				case 1:
					getStudents(strCountS, student);		//������� ������ ���������
					break;
				case 2:
					getTeachers(strCountT, teacher);		//������� ������ ��������������
					break;
				case 3:
					GetScheduleForT(strCountSc, schedule, weekIndex, dateIndex, sizeWeekIndex, sizeDateIndex); //������� ���������� ��� �������������
					break;
				case 0:
					break;
				default:
					printf("\n��������� ������� �� ����������!\n");
					break;
				}
				break;
			case 2:
				initialization(students, strCountS, student,						//������������� ��������
					teachers, strCountT, teacher, Schedule, strCountSc, schedule, 
					weekIndex, dateIndex, sizeWeekIndex, sizeDateIndex, 
					strCountAb, absent, Absent, absentIndex, sizeAbsentIndex);
				printf("�� ����� ��� ������� ������� ��������.\n\
�������� ���������� ��������:\n1. ���������� ������ ������\n\
2. ���������� ���������� ������� ������\n\
3. ���������� ����������� ��������\n\
0. ����� �� ���������\n");
				scanf("%d", &l);
				switch (l) {
				case 1:
					getStudents(strCountS, student);		//������� ������ ���������
					break;
				case 2:
					getSchedule(strCountSc, schedule, weekIndex, dateIndex, sizeWeekIndex, sizeDateIndex);		//������� ���������� ��� ������
					break;
				case 3:
					getAbsent(strCountAb, absent, strCountS, student, absentIndex, sizeAbsentIndex);			//������� ������� ��������
					break;
				case 0:
					break;
				default:
					printf("\n��������� ������� �� ����������!\n");
					break;
				}
				break;
			}

			/*�������� ������ ���������� ��� ����������*/
			memset(student, 0, sizeof(student));
			memset(teacher, 0, sizeof(teacher));
			memset(schedule, 0, sizeof(schedule));
			memset(absent, 0, sizeof(absent));
			strCountS = 0;
			strCountT = 0;
			strCountSc = 0;
			strCountAb = 0;
			memset(absentIndex, 0, sizeof(absentIndex));
			sizeAbsentIndex = 0;
			memset(dateIndex, 0, sizeof(dateIndex));
			memset(weekIndex, 0, sizeof(weekIndex));
			sizeWeekIndex = 0;
			sizeDateIndex = 0;
			/******************************************/
			
			if (l != 0) {			//������� ���������� ���������
				system("pause");
				system("cls");
			}
		}

	}
	else
		printf("������ �����������.\n");

	memset(authorization, 0, sizeof(authorization));
	system("pause");
	return 0;
}



////////////////////////////////////////////////////////////////////
/***********************���������� �������*************************/
////////////////////////////////////////////////////////////////////

int initialization(FILE *students, int &strCountS, studentInf *student,
	FILE *teachers, int &strCountT, teacherInf *teacher,
	FILE *Schedule, int &strCountSc, scheduleInf *schedule,
	int *weekIndex, int *dateIndex, int &sizeWeekIndex, int &sizeDateIndex,
	int &strCountAb, absentInf *absent, FILE *Absent, int *absentIndex, int & sizeAbsentIndex) {
	/*******************������������� ��������� student***********************/
	students = fopen("Students.txt", "rt");			//��������� ����
	char *s = (char*)malloc(256);					//������ ��� ���������� ����� �����
	int i;											//��������� ����������
	/*���������, ���������� �� ����*/
	if (students == NULL) {
		printf("������ �������� �����!");
		system("pause");
		return 1;
	}
	/*���������, ���� �� ����*/
	fseek(students, 0, SEEK_END);					//��������� ��������� � �����
	long posS = ftell(students);					//���������� ��� �������
	if (posS <= 0) {
		printf("���� ����!");
		system("pause");
		return 2;
	}
	rewind(students);								//��������� ��������� � ������

	while (fgets(s, 256, students) != NULL) {		//��������� ���� �� �����
		if (s[0] != '\n') {
			strCountS++;							//����������� ������� �����
		}
	}
	rewind(students);

	/**************��������� ���������� �� ����� � ������ ��������****************/
	for (i = 0; i < strCountS; i++) {
		fscanf(students, "%s%s%s%s%s%s", &student[i].surname, &student[i].name, &student[i].secondname, &student[i].enterYear, &student[i].group, &student[i].phone);
		int a = fgetc(students);
		fgets(student[i].adress, 50, students);
	}
	fclose(students);								//��������� ����

	/*******************������������� ��������� teacher***********************/
	teachers = fopen("Teachers.txt", "rt");		//��������� ����
	int j;										//��������� ����������
	char *p = (char*)malloc(256);				//������ ��� ���������� ����� �����
	/*���������, ���������� �� ����*/
	if (teachers == NULL) {
		printf("������ �������� �����!");
		system("pause");
		return 3;
	}
	/*���������, ���� �� ����*/
	fseek(teachers, 0, SEEK_END);				//��������� ��������� � �����
	long posT = ftell(teachers);				//���������� ��� �������
	if (posT <= 0) {
		printf("���� ����!");
		system("pause");
		return 4;
	}
	rewind(teachers);							//��������� ��������� � ������

	while (fgets(p, 256, students) != NULL) {	//��������� ���� �� �����
		strCountT++;							//����������� ������� �����
	}
	rewind(teachers);

	/**************��������� ���������� �� ����� � ������ ��������****************/
	for (j = 0; j < strCountT; j++) {
		fscanf(teachers, "%s%s%s%s", &teacher[j].tSurname, &teacher[j].tName, &teacher[j].tSecondname, &teacher[j].tPhone);
	}
	fclose(teachers);								//��������� ����

	/*******************������������� ��������� schedule***********************/
	Schedule = fopen("Schedule.txt", "rt");		//��������� ����
	char *sc = (char*)malloc(256);				//������ ��� ���������� ����� �����
	int l = 0;									//��������� ����������
	int m = 0;									//������ ��� ������� �������� ���
	int k = 0;									//������ ��� ������� �������� ������
	/*���������, ���������� �� ����*/
	if (Schedule == NULL) {
		printf("������ �������� �����!");
		system("pause");
		return 5;
	}
	/*���������, ���� �� ����*/
	fseek(Schedule, 0, SEEK_END);					//��������� ��������� � �����
	long posSce = ftell(Schedule);					//���������� ��� �������
	if (posSce <= 0) {
		printf("���� ����!");
		system("pause");
		return 6;
	}
	rewind(Schedule);								//��������� ��������� � ������

	while (fgets(sc, 256, Schedule) != NULL) {		//��������� ���� �� �����
		if (strstr(sc, "������") != NULL) {
			weekIndex[k] = strCountSc;				//��������� ������ ��������� ������
			k++;
		}
		if (isdigit((unsigned char)sc[0])) {	
			dateIndex[m] = strCountSc;				//��������� ������ ��������� ���
			m++;
		}
		strCountSc++;								//����������� ������� �����
	}
	rewind(Schedule);
	sizeWeekIndex = k;								//���������� ������ ������� �������� ������
	sizeDateIndex = m;								//���������� ������ ������� �������� ���

	m = 0;											//�������� �������
	k = 0;

	/**************��������� ���������� �� ����� � ������ ��������****************/
	for (l = 0; l < strCountSc; l++) {
		if (l == weekIndex[k]) {
			fscanf(Schedule, "%s%d", schedule[l].week, &schedule[l].numWeek);
			k++;
		}
		else if (l == dateIndex[m]) {
			fscanf(Schedule, "%s", schedule[l].date);
			m++;

		}
		else if (l != dateIndex[m]) {
			fscanf(Schedule, "%s%s%s%s%s%s", schedule[l].subject, schedule[l].classTime, schedule[l].numOfAudience, schedule[l].teacherS, schedule[l].teacherN, schedule[l].teacherSN);

		}
	}
	/*******************������������� ��������� Absent***********************/
	Absent = fopen("Absent.txt", "rt");		//��������� ����
	int n = 0;								//��������� ����������
	int b = 0;								//������ ��� ������� �������� �������������
	char *ab = (char*)malloc(256);			//������ ��� ���������� ����� �����
	/*���������, ���������� �� ����*/
	if (Absent == NULL) {
		printf("������ �������� �����!");
		system("pause");
		return 7;
	}
	/*���������, ���� �� ����*/
	fseek(Absent, 0, SEEK_END);					//��������� ��������� � �����
	long posA = ftell(Absent);					//���������� ��� �������
	if (posA <= 0) {
		printf("���� ����!\n");
		system("pause");
		return 8;
	}
	rewind(Absent);								//��������� ��������� � ������

	while (fgets(ab, 256, Absent) != NULL) {	//��������� ���� �� �����
		if (!isdigit((unsigned char)ab[0])) {
			absentIndex[b] = strCountAb;		//��������� ������ ��������� �������������
			b++;
		}
		strCountAb++;							//����������� ������� �����
	}
	rewind(Absent);
	sizeAbsentIndex = b;						//���������� ������ ������� �������� �������������

	b = 0;										//�������� ������

	/**************��������� ���������� �� ����� � ������ ��������****************/
	for (n = 0; n < strCountAb; n++) {
		if (n == absentIndex[b]) {
			fscanf(Absent, "%s%s%s", &absent[n].sSurName, &absent[n].sName, &absent[n].sSecondName);
			b++;
		}
		else if (n != absentIndex[b]) {
			fscanf(Absent, "%s", &absent[n].absentDate);
			fgets(absent[n].abSubject, 50, Absent);
		}
	}
	fclose(Absent);
	return 9;
}


void getStudents(int &strCountS, studentInf *student) {
	/*������ ����������� ��������� �������*/
	for (int f = 0; f < strCountS; f++) {
		printf("%s\t%s\t%s\t%s\t%s\t%s\t%s", &student[f].surname, &student[f].name, &student[f].secondname, &student[f].enterYear, &student[f].group, &student[f].phone, &student[f].adress);
	}
	printf("\n");
}

int AddStudent(FILE *students, int &strCountS, studentInf *student) {
	/*���� � ���������� ������ ��� ����������*/
	printf("������� ������ �������� ����� ������(���, ��� �����������, ������, ����� ��������, �����):\n");
	scanf("%s%s%s%s%s%s%c", &student[strCountS].surname, &student[strCountS].name, &student[strCountS].secondname, &student[strCountS].enterYear, &student[strCountS].group, &student[strCountS].phone);
	fgets(student[strCountS].adress, 50, stdin);
	/*������� � ��������� ������ ������ "����� ������"*/
	for (int i = 0; i < strlen(student[strCountS].adress); i++) {
		if (student[strCountS].adress[i] == '\n') {
			student[strCountS].adress[i] = '\0';
			break;
		}
	}
	strCountS++;								//����������� ������� �����
	students = fopen("Students.txt", "wt");		//��������� ����
	/*���������� � ����*/
	for (int i = 0; i < strCountS; i++) {
		if (i != strCountS - 1) {
			fprintf(students, "%s %s %s %s %s %s %s", student[i].surname, student[i].name, student[i].secondname, student[i].enterYear, student[i].group, student[i].phone, student[i].adress);
		}
		if (i == strCountS - 1) {
			fprintf(students, "\n%s %s %s %s %s %s %s", student[i].surname, student[i].name, student[i].secondname, student[i].enterYear, student[i].group, student[i].phone, student[i].adress);
		}
	}
	fclose(students);							//��������� ����
	system("cls");
	return 10;
}

int DeleteStudent(FILE *students, int &strCountS, studentInf *student) {
	char deleteName[256];			//������ ��� ���������� �����
	char deleteSurname[256];		//������ �� ��������� �������
	char deleteSecondName[256];		//������ ��� ���������� ��������
	int j = -1;						//���� ��� ���������� ��������
	bool copy = false;				//���� ��� ����������� ��������� � ������
	/*������ � ��������� ������ � ��������*/
	printf("������� ��� ��������, �������� ������ ������� �� ������(����� �������):\n");
	scanf("%s%s%s", &deleteSurname, &deleteName, &deleteSecondName);
	for (int i = 0; i < strCountS; i++) {
		if (((strcmp(student[i].surname, deleteSurname)) == 0) && ((strcmp(student[i].name, deleteName)) == 0) && ((strcmp(student[i].secondname, deleteSecondName)) == 0)) {
			j = i;
			copy = true;
			break;
		}
		else if ((j == -1) && (i == strCountS - 1)) {
			printf("������� �� ������.\n");
			break;
		}
	}

	if (copy == true) {
		/*�������� ��������� ��������*/
		for (int i = j; i < strCountS - 1; i++) {
			strcpy(student[i].name, student[i + 1].name);
			strcpy(student[i].surname, student[i + 1].surname);
			strcpy(student[i].secondname, student[i + 1].secondname);
			strcpy(student[i].enterYear, student[i + 1].enterYear);
			strcpy(student[i].group, student[i + 1].group);
			strcpy(student[i].phone, student[i + 1].phone);
			strcpy(student[i].adress, student[i + 1].adress);
		}
		strCountS--;
		/*������� � ��������� ������ ������ "����� ������"*/
		for (int i = 0; i < strlen(student[strCountS - 1].adress); i++) {
			if (student[strCountS - 1].adress[i] == '\n') {
				student[strCountS - 1].adress[i] = '\0';
				break;
			}
		}
		/*�������������� ��������� � ����*/
		students = fopen("Students.txt", "wt");
		for (int i = 0; i < strCountS; i++) {
			fprintf(students, "%s %s %s %s %s %s %s", student[i].surname, student[i].name, student[i].secondname, &student[i].enterYear, &student[i].group, &student[i].phone, &student[i].adress);
		}

		fclose(students);			//��������� ����
	}
	return 11;
}

void getTeachers(int &strCountT, teacherInf *teacher) {
	/*������ ����������� ��������� �������������*/
	for (int f = 0; f < strCountT; f++) {
		printf("%s\t%s\t%s\t%s\n", &teacher[f].tSurname, &teacher[f].tName, &teacher[f].tSecondname, &teacher[f].tPhone);
	}
}

int AddTeacher(FILE *teachers, int &strCountT, teacherInf *teacher) {
	/*���� � ���������� ������ � �������������*/
	printf("������� ������ ������������� ����� ������(���, ����� ��������):\n");
	scanf("%s%s%s%s", &teacher[strCountT].tSurname, &teacher[strCountT].tName, &teacher[strCountT].tSecondname, &teacher[strCountT].tPhone);
	strCountT++;			//����������� ������� �����
	/*��������� ���� � ���������� � ���� ����������*/
	teachers = fopen("Teachers.txt", "wt");
	for (int i = 0; i < strCountT; i++) {
		fprintf(teachers, "%s %s %s %s\n", &teacher[i].tSurname, &teacher[i].tName, &teacher[i].tSecondname, &teacher[i].tPhone);
	}
	fclose(teachers);		//��������� ����
	system("cls");
	return 12;
}

int DeleteTeacher(FILE *teachers, int &strCountT, teacherInf *teacher) {
	char deleteName[256];			//������ ��� ���������� �����
	char deleteSurname[256];		//������ �� ��������� �������
	char deleteSecondName[256];		//������ ��� ���������� ��������
	int j = -1;						//���� ��� ���������� ��������
	bool copy = false;				//���� ��� ����������� ��������� � ������
	/*������ � ��������� ������ � �������������*/
	printf("������� ��� �������������, �������� ������ ������� �� ������(����� �������):\n");
	scanf("%s%s%s", &deleteSurname, &deleteName, &deleteSecondName);
	for (int i = 0; i < strCountT; i++) {
		if (((strcmp(teacher[i].tSurname, deleteSurname)) == 0) && ((strcmp(teacher[i].tName, deleteName)) == 0) && ((strcmp(teacher[i].tSecondname, deleteSecondName)) == 0)) {
			j = i;
			copy = true;
			break;
		}
		else if ((j == -1) && (i == strCountT - 1)) {
			printf("������������� �� ������.\n");
			system("pause");
			break;
		}
	}

	if (copy == true) {
		/*�������� ��������� �������������*/
		for (int i = j; i < strCountT - 1; i++) {
			strcpy(teacher[i].tSurname, teacher[i + 1].tSurname);
			strcpy(teacher[i].tName, teacher[i + 1].tName);
			strcpy(teacher[i].tSecondname, teacher[i + 1].tSecondname);
			strcpy(teacher[i].tPhone, teacher[i + 1].tPhone);
		}
		strCountT--;
		/*�������������� ��������� � ����*/
		teachers = fopen("Teachers.txt", "wt");
		for (int i = 0; i < strCountT; i++) {
			fprintf(teachers, "%s %s %s %s\n", &teacher[i].tSurname, &teacher[i].tName, &teacher[i].tSecondname, &teacher[i].tPhone);
		}
		fclose(teachers);
	}
	system("cls");
	return 13;
}

void getSchedule(int &strCountSc, scheduleInf *schedule, int *weekIndex, int *dateIndex, int &sizeWeekIndex, int &sizeDateIndex) {
	int f = -1;				//���������� ��� ������ ��������
	int i = 0;				//��������� ����������
	int j = 0;				//��������� ����������
	int k = 0;				//��������� ����������
	int y = -1;				//��������� ����������
	int num = -1;			//����� ������
	bool weekExist = false;	//���� ������������� ������
	char dateWritten[256];	//����
	bool dateExist = false;	//���� ������������� ����

	weekIndex[sizeWeekIndex] = 2 * weekIndex[sizeWeekIndex - 1] - weekIndex[sizeWeekIndex - 2]; //������ ���������� ������� ������

	printf("�������� ���������� ��������:\n1. ������� ��� ��������� ����������\n2. ������� ���������� ������������ ������\n3. ������� ���������� �� ������������ ����\n");
	scanf("%d", &f);
	if (f == 1) {
		//������ ����� ���������� ����������
		for (i = 0; i < strCountSc; i++) {
			if (i == weekIndex[k]) {
				printf("%s %d\n", schedule[i].week, schedule[i].numWeek);
				k++;
			}
			else if (i == dateIndex[j]) {
				printf("%s\n", schedule[i].date);
				j++;
			}
			else if (i != dateIndex[j]) {
				printf("%s %s %s %s %s %s\n", schedule[i].subject, schedule[i].classTime, schedule[i].numOfAudience, schedule[i].teacherN, schedule[i].teacherS, schedule[i].teacherSN);
			}
		}
	}
	if (f == 2) {
		printf("������� ����� ������: ");
		scanf("%d", &num);
		/*�������� �� ������������� ��������� ������*/
		for (y = 0; y < sizeWeekIndex; y++) {
			if (num == schedule[weekIndex[y]].numWeek) { //���� ����� ��������� ������ ��������� � �����-�� ������� ������ ������� �������� ������
				weekExist = true;
				break;
			}
			else if ((y == sizeWeekIndex - 1) && (weekExist == false)) {
				system("cls");
				printf("��������� ���� ������ ����������.\n");
				break;
			}
		}
		if (weekExist == true) {
			//������ ���������� �� ��������� ������
			for (i = weekIndex[y]; i < weekIndex[y + 1]; i++) {
				if (i == weekIndex[y]) {
					printf("%s %d\n", schedule[i].week, schedule[i].numWeek);
				}
				else if (i == dateIndex[(num - 1) * 5 + j]) {
					printf("%s\n", schedule[i].date);
					j++;
				}
				else {
					printf("%s %s %s %s %s %s\n", schedule[i].subject, schedule[i].classTime, schedule[i].numOfAudience, schedule[i].teacherN, schedule[i].teacherS, schedule[i].teacherSN);
				}
			}
		}
	}
	if (f == 3) {
		printf("������� ���� (� ������� dd:mm:yy): ");
		scanf("%s", &dateWritten);
		/*�������� �� ������������� ��������� ����*/
		if (strcmp(dateWritten, schedule[dateIndex[sizeDateIndex - 1]].date) == 0) {
			for (y = 0; y < sizeDateIndex; y++) {
				if (strcmp(dateWritten, schedule[dateIndex[y]].date) == 0) {
					dateExist = true;
					break;
				}
				else if ((y == sizeDateIndex - 1) && (dateExist == false)) {
					system("cls");
					printf("��������� ���� ���� ����������.\n");
				}
			}
			if (dateExist == true) {
				//������ ���������� �� ��������� ����
				for (i = dateIndex[y]; i < strCountSc; i++) {
					if (i == dateIndex[y]) {
						printf("%s\n", schedule[i].date);
					}
					else {
						printf("%s %s %s %s %s %s\n", schedule[i].subject, schedule[i].classTime, schedule[i].numOfAudience, schedule[i].teacherN, schedule[i].teacherS, schedule[i].teacherSN);
					}
				}
			}
		}

		else {
			//������ ���������� ������� ������� ���
			dateIndex[sizeDateIndex] = 2 * dateIndex[sizeDateIndex - 1] - dateIndex[sizeDateIndex - 2];
			/*�������� �� ������������� ��������� ����*/
			for (y = 0; y < sizeDateIndex; y++) {
				if (strcmp(dateWritten, schedule[dateIndex[y]].date) == 0) {
					dateExist = true;
					break;
				}
				else if ((y == sizeDateIndex - 1) && (dateExist == false)) {
					system("cls");
					printf("��������� ���� ���� ����������.\n");
				}
			}
			if (dateExist == true) {
				//������ ���������� �� ��������� ����
				for (i = dateIndex[y]; i < dateIndex[y + 1]; i++) {
					if (i == dateIndex[y]) {
						printf("%s\n", schedule[i].date);
					}
					else {
						printf("%s %s %s %s %s %s\n", schedule[i].subject, schedule[i].classTime, schedule[i].numOfAudience, schedule[i].teacherN, schedule[i].teacherS, schedule[i].teacherSN);
					}
				}
			}
		}
	}
}

void GetScheduleForT(int &strCountSc, scheduleInf *schedule, int *weekIndex, int *dateIndex, int &sizeWeekIndex, int &sizeDateIndex) {
	int i;							//��������� ����������
	int j;							//���������� ��� ����������� ������� �������������
	int y = 0;						//��������� ����������
	int k = 0;						//���������� ��� ���������� ������ ����				
	char tName[256];				//������ ��� �����
	char tSurName[256];				//������ ��� �������
	char tSecondName[256];			//������ ��� ��������
	bool teacherFound = false;		//���� "������ �� �������������"
	dateIndex[sizeDateIndex] = 2 * dateIndex[sizeDateIndex - 1] - dateIndex[sizeDateIndex - 2]; //������ ���������� ������ ������� �������� ���
	printf("������� ��� �������������, ����� ������� ��� ����������: ");
	scanf("%s%s%s", &tSurName, &tName, &tSecondName);
	for (i = dateIndex[y]; i < dateIndex[y + 1]; i++) {			//��������� ����� �������������� ����� ��������� ������

		if ((strcmp(tName, schedule[i].teacherN) == 0) && (strcmp(tSurName, schedule[i].teacherS) == 0) && (strcmp(tSecondName, schedule[i].teacherSN) == 0)) {
			teacherFound = true;
			j = i;
			k++;
		}
		if (teacherFound == true) {
			//������ ���������� ��� �������������
			if (k == 1) {
				printf("%s\n", schedule[dateIndex[y]].date);
			}
			printf("%s %s %s %s %s %s\n", schedule[j].subject, schedule[j].classTime, schedule[j].numOfAudience, schedule[j].teacherS, schedule[j].teacherN, schedule[j].teacherSN);
		}
		if (i == dateIndex[y + 1] - 1) {
			y++;
			k = 0;
		}
		teacherFound = false;		//�������� ����:"������������� �� ������"
	}
}

void getAbsent(int &strCountAb, absentInf *absent, int &strCountS, studentInf *student, int *absentIndex, int &sizeAbsentIndex) {
	int i = 0;							//��������� ����������
	int j;								//��������� ����������
	int y = 0;							//��������� ����������
	int k = 0;							//��������� ����������
	int t = 0;							//��������� ����������
	int t1 = 0;							//���������� ��� ����������� ���������� ������� ������� �������� �������������
	char nameS[256];					//������ ��� �����
	char surnameS[256];					//������ ��� �������
	char secondnameS[256];				//������ ��� ��������
	bool studentFoundGeneral = false;	//���� "������ �� ������� � ����� ������"
	bool studentFoundAbsent = false;	//���� "������ �� ������� � ������ �������������"
	absentIndex[sizeAbsentIndex] = 2 * absentIndex[sizeAbsentIndex - 1] - absentIndex[sizeAbsentIndex - 2]; //������ ���������� ������ ������� �������� �������������
	printf("������� ��� ��������, �������� �������� �� ������ �������: ");
	scanf("%s%s%s", &surnameS, &nameS, &secondnameS);
	for (i = 0; i < strCountS; i++) {
		//����� �������� � ����� ������
		if ((strcmp(nameS, student[i].name) == 0) && (strcmp(surnameS, student[i].surname) == 0) && (strcmp(secondnameS, student[i].secondname) == 0)) {
			studentFoundGeneral = true;
			printf("������� ������ � ����� ������.\n");
			break;
		}
		else if ((studentFoundGeneral == false) && (i == strCountS - 1)) {
			printf("������� �� ������ � ����� ������.\n");
		}
	}
	if (studentFoundGeneral == true) {
		//����� �������� � ������ �������������
		for (j = 0; j < strCountAb; j++) {
			if ((strcmp(nameS, absent[j].sName) == 0) && (strcmp(surnameS, absent[j].sSurName) == 0) && (strcmp(secondnameS, absent[j].sSecondName) == 0)) {
				studentFoundAbsent = true;
				break;
			}
		}
		if (studentFoundAbsent == true) {
			for (t = 0; t < sizeAbsentIndex; t++) {
				if (j == absentIndex[t]) {
					t1 = absentIndex[t + 1];	//���������� ��������� ������ ������� �������� �������������
					break;
				}
			}
			//������ �������� ��������������
			for (t = j; t < t1; t++) {
				if (t == j)
					printf("%s %s %s\n", absent[t].sSurName, absent[t].sName, absent[t].sSecondName);
				else if (t != j)
					printf("%s %s", absent[t].absentDate, absent[t].abSubject);
			}
			printf("\n");
		}
		else if ((studentFoundAbsent == false) && (j = strCountAb - 1)) {
			printf("������� ������� ��� �������.\n");
		}
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**************************************************************************************************************************************/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////