//#include <iostream>
//
//using namespace std;
//
//int main() {
//	int Calender[] = { 0,31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//	int month, day;
//	int currentMonth = 0;
//	int dateDay = 99;
//
//	cin >> month >> day;
//    dateDay -= (Calender[month] - day);
//	for (int i = month + 1; dateDay >Calender[i]; i++) {
//		dateDay -= Calender[i];
//		currentMonth = i;
//	}
//
//	cout << "100일 되는 날은 " << currentMonth + 1 << "월 " << dateDay << "일";
//}