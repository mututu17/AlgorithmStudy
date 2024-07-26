#include <iostream>
#include <string.h>
#include <time.h>
#include <stdlib.h>

using namespace std;

int main() {
	
	//1. n번 동안 2개 정수 입력받아 덧셈하기
	cout << "2개 정수 입력받아 덧셈하기: " << endl;
	int a, b, n;
	int i = 0;
	cout << "반복 횟수 : ";
	cin >> n;
	
	while(i < n) {
		cin >> a >> b;
		int result = a + b;
		cout << "sum =  " << result << endl;
		i++;
	}

	//2. 윤년 프로그램  *윤년: 4로 나눴을 때 0으로 떨어짐과 동시에 100으로 나눴을때 나머지가 0이 아니거나 400으로 나눴을때 0으로 떨어지면 윤년
	cout <<"\n" << "윤년 프로그램 :" << endl;
	int year;
	cin >> year;
	if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)) {  
		cout << "-> 윤년입니다. " << endl;
	}
	else
		cout << "-> 윤년이 아닙니다." << endl;
	
	//3. 정수의 누적 
	cout << "\n" << "정수의 누적 (1~50까지 덧셈) : " << endl;
	int intger= 0;
	for (int i = 1; i <= 100; i++) {
		intger += i;
	}
	cout << intger << endl;
	
	//4. 최대,최소값 찾기
	cout << "\n" << "최대, 최소값 찾기 :" << endl;
	int num, Number;
	int max_num, min_num;
	cout << "숫자 개수 : ";
	cin >> Number;
	for (int i = 0; i < Number; i++) {
		cin >> num;
		if (i == 0) {   // i가 0일 때, 처음 num값이 입력을 max,min 으로 초기화
			max_num = min_num = num;
		}
		else if (num > max_num) {
			max_num = num;
		}
		else if (num < min_num) {
			min_num = num;
		}
	}
	cout << "Max : " << max_num << " / Min : " << min_num << endl;
	
	//5. 정수의 자리수 출력
	cout << "\n" << " 정수 N의 자리수 출력 : (1의자리 부터)"<< endl; 
	int intger_number; // N자리 정수
	int remiander_number; // 나머지 숫자
	cin >> intger_number;
	                                                // 이걸 30분 동안 헤메고 있었던게 레전드...
	while (1) { // 무한 반복문 
		remiander_number = intger_number % 10;  // 정수 를 10으로 나눈 나머지 값을 remiander_number에 저장
		intger_number /= 10;                   // 나머지를 제외한 자리수 정수를 기존의 정수 변수에 저장 
		if ((remiander_number % 10)==0){      // 나머지 숫자가 10으로 나눴을 때 0이면 -> 0 % 10 = 0 이므로 
			break;                           // 반복문 중지 
		}
		else
			cout << remiander_number << endl; // 각 자리수 작은 수 부터 출력 
	}

	//6. 정수 약수 계산하기
	cout << "\n" << "약수 계산하기" << endl;
	int number;        //입력 받을 정수 선언
	int divisor_num;   // 약수 변수 선언
	cin >> number;
	for (divisor_num = 1; divisor_num <= number; divisor_num++) { // 1부터 입력받은 정수까지 반복문 실행
		if (number % divisor_num == 0) { //나눴을 때 나머지가 0, 딱 떨어지면 약수 
			cout << divisor_num << ",";    // 약수 변수 출력
		}
	}
	
	//7. 정수 N의 소수  
	cout << "\n\n" << "1부터 N까지의 소수" << endl;
	int N, prime;
	int is_prime = 0;
	cout << "N : ";
	cin >> N;
	
	for (prime = 2; prime <= N; prime++) {    // 1을 제외한 N까지의 숫자만큼 반복 
		is_prime = 0;                         // 소수판별 변수를 0으로 초기화
		for (int i = 2; i < prime; i++) {     
			if ((prime % i) == 0) {           // 해당 숫자가 2~N-1까지 나눴을때 나머지가 0이면
				is_prime = 1;                 // 1과 자신 이외에 약수가 있으므로 1로 저장하고 
				break;                        // 반복 중지
			}
		}
		if ((is_prime == 0)) {              //  is_prime == 0인 즉 나머지가 0이 아닌 숫자만 출력 ?
		cout << prime << ",";
			}
	
	}
	/*  기존의 틀린 코드 
	for (prime = 2; prime <= N; prime++) {                      
		for (int i = 2; i < prime; i++) {
			if ((prime % i) == 0) {
				break;
			}
			else {
				cout << prime << ",";    
				// else 조건은 맞지만 각 숫자가 나눠질때 나머지가 0이아니면 나눠지는 횟수만큼 중복해서 출력해버림
			}
		}

	}
	*/


	return 0;
}