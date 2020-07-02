



















//#include <iostream>
//using namespace std;
//
////FUNCTIONS PROTOTYPES
//struct Time {
//	int Hours;
//	int Minutes;
//};
//
////FUNCTION OVERLOAD
//Time operator + (const Time &a, const Time &b) {
//	Time SumTime;
//	SumTime.Minutes = a.Minutes + b.Minutes;
//	SumTime.Hours = a.Hours + b.Hours + SumTime.Minutes/60;
//	SumTime.Minutes %= 60;
//
//	return SumTime;
//}//Time operator +
//
////MAIN PROGRAMM
//int main() {
//
//	setlocale(LC_ALL, "russian");
//	system("color F0");
//
//	Time ATime = { 4, 40 };
//	Time BTime = { 3, 35 };
//	Time CTime;
//
//	cout << "\nINITIAL DATA\n";
//	cout << " ATime: Hours = " << ATime.Hours << "\t Minutes = " << ATime.Minutes << endl;
//	cout << " BTime: Hours = " << BTime.Hours << "\t Minutes = " << BTime.Minutes << endl;
//
//	CTime = ATime + BTime;
//
//	cout << "\n\t OPERATOR FORM OF CALLING\n";
//	cout <<"\nCTime = ATime + BTime: \n "<< " CTime: Hours = " << CTime.Hours << "\t Minutes = " << CTime.Minutes << endl;
//
//	//FUNCTIONAL FORM OF CALLING
//	cout << "\n\tFUNCTIONAL FORM OF CALLING\n";
//	cout << "\nCTime = operator + (ATime, BTime): \n " << " CTime: Hours = " << CTime.Hours << "\t Minutes = " << CTime.Minutes << endl;
//	
//	cout << endl;
//	system("pause");
//	return 0;
//}