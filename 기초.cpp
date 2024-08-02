// c++ 기초 
#include <iostream> // iosteam 이라는 헤더 라이브러리 
#include <string.h> // c++ 에서 문자열 선언시 string 라이브러리 사용
using namespace std; // 네임스페이스 설명 std :: cout
#define N 6
int main() {
	// 1. hello world 출력 
	printf("hello world !\n");
	cout << "hello world !!\n" << endl; //cout : 자료형 상관없이 출력 가능 /endl : endline,라인의 끝, 줄바꿈, ** endl은 줄바꿈시 속도가 느림

	// 2. 자료형 변수   선언 및 초기화 
	int a = 3;
	char b = 'B';
	float c = 3.14;
	string str1 = "pinapple"; // 문자열  string 선언필요
	string str2 = "pen";
	string sum = str2 + " " + str1;
	cout << a <<"\n" << b << "\n" << c << "\n" << sum << endl; // cout문 안에서 줄바꿈 시 <<"\n"로 표기

	//3. 표준입출력  cin:입력 스트림 객체(표기: >>) / cout:출력 스트림 객체(표기: <<)
	cout << "\n"<<"정수, 실수, 문자열 입력 : " << endl;
 	int x; //정수
	float y; //실수
	string z; // 문자열
	cin >> x >> y >> z;
	cout << "출력값: " << x << "," << y << "," << z << endl;

	//4. if-else 조건문 (c문법과 동일)
	cout << "\n" <<"간단한 정수형 비교 : cmp_num1 >,<,= cmp_num2 " << endl;
	int  cmp_num1, cmp_num2;
	cin >> cmp_num1 >> cmp_num2;

	if (cmp_num1 > cmp_num2) {
		cout << "cmp_num1이 cmp_num2 보다 크다" << endl;
	}
	else if (cmp_num1 < cmp_num2) {
		cout << "cmp_num2가 cmp_num1 보다 크다" << endl;
	}
	else
		cout << "cmp_num1 와 cmp_num2는 같다 " << endl;

	//5. 간단한 계산기 
	cout <<"\n" << "간단한 계산기 :" << endl;
	double num1, num2,result;
	char op; //연산기호 선언
	
	cin >> num1 >> op >> num2;
	// 연산 기호에 따라 result 값 반환 후 출력
	if (op == '+') {  
		result = num1 + num2;
		cout << "값 = "<< result << endl;
	}
	else if (op == '-') {
		result = num1 - num2;
		cout << "값 = " << result << endl;
	}
	else if (op == '*') {
		result = num1 * num2;
		cout << "값 = " << result << endl;
	}
	else if (op == '/') {
		result = num1 / num2;
		cout << "값 = " << result << endl;
	}
	else {
		cout << "*형식 오류*" << endl; 
		return 1; // 식이 잘못되었을 시 오류발생 문자 출력 후 종료 
	}

	// for 반복문 
	cout <<"\n"<<"별 피라미드 만들기 : " << endl; // 진짜 1시간 걸림 ㅠ -> 내 개 똥같은 실력 돌았구요
	for (int i = 0; i < N; i++) { // 총 N 번만큼 실행
		for (int j = N - 1 - i; j > 0; j--) { // N-1-i 만큼 공백 출력 (첫줄은 공백)
			cout << "  "; // ★은 2바이트 차지하므로 공백 두칸이어야 함!
		}
		for (int k = 0; k < i; k++) { // k가 0부터 i보타 작을때까지 ★출력 
			cout << "★";
		}
		for (int q = 0; q < i - 1; q++) { // 가운데를 기준으로 오른쪽 방향 ★출력
			cout << "★";
		}
		cout << endl;
	}
	
	//while 반복문 
	cout <<"\n" << "팩토리얼 계산 : ";
	int f_num; // 팩토리얼 숫자
	int factorial = 1; // 팩토리얼 변수 선언
	cin >> f_num;

	while (f_num >=1){ // 팩토리얼 숫자가 1과 같거나 클때까지 반복
		factorial *= f_num; // 팩토리얼에 숫자를 곱해나감 -> factorial = factorial * f_num
		f_num--; // 팩토리얼 숫자 감소
	}
	cout << "값 = " << factorial << endl;

	return 0;
}