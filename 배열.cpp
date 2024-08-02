#include <iostream>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define SIZE 6
using namespace std;

int main()
{	
	//배열에 저장된 값에서 최대.최소값 찾기
	int prices[SIZE] = { 0 };        // 배열 초기값 초기화
	int minimum,maximum;
	cout << "최대/최소값 찾기 - 난수 생성 :" << endl;
	srand((unsigned)time(NULL)); // 난수 생성 *time.h 라이브러리 함수를 사용해서 고정된 랜덤 숫자(seed)가 아닌 시간에 따른 완전한 랜덤 수 생성
	for (int i = 0; i < SIZE; i++) {
		prices[i] = (rand() % 100) + 1; // 1부터 100까지의 숫자 사이에서 랜덤 숫자 생성
		cout << prices[i] << ",";
	}
	cout << "\n\n";
	minimum = maximum = prices[0];
	for (int i = 1; i < SIZE; i++)
	{
		if (prices[i] < minimum)
			minimum = prices[i];
		else if (prices[i] > maximum) {
			maximum = prices[i];
		}
	}
	cout << "최소값은 " << minimum << ", 최대값은 "<< maximum <<" 입니다.\n\n";
	
	//버블 정렬
	int list[SIZE] = {};
	for (int i = 0; i < SIZE; i++) {
		list[i] = (rand() % 100) + 1;
	}
	cout << "Before bubble sort :"<<endl;
	for (int i = 0; i < SIZE; i++) {
		cout << list[i] << ",";
	}
	// 배열의 요소를 정렬한다. 
	for (int k = 0; k < SIZE; k++) {        
		for (int i = 0; i < SIZE - 1; i++) {   //제일 마지막 index의 값은 어짜피 정렬된 값이 들어가므로 (SIZE -1)동안 반복한다.   
			if (list[i] > list[i + 1]) {	// 처음 list[0]과 list[1]을 비교해서 큰 값이 뒤로 가게 서로 저장된 값을 바꿈 
				int tmp = list[i];         // 값을 서로 바꾸기 위해 값을 임시 저장할 변수 tmp를 선언
				list[i] = list[i + 1];		 
				list[i + 1] = tmp;         // 저장해뒀던 값을 다시 list[i+1]에 저장
			}
		}
	}
	cout << "\n\n" << "After bubble sort :" << endl; 
	for (int i = 0; i < SIZE; i++) {
		cout << list[i] << ",";     // 버블정렬 된 값을 출력.
	}

	//배열에서 특정한 값 탐색하기
	int key, i;
	int list_2[SIZE] = {0};
	cout << "\n\n"<<"특정한 값 탐색하기 : " << endl;
	cout <<"[ ";
	for (i = 0; i < SIZE; i++) {
		list_2[i] = (rand() % 100 ) + 1;   // 1 ~100 사이 랜덤한 숫자 배열에 저장
		cout <<list_2[i] << ",";
	}
	cout << "]\n";

	int k=0;
	do{
		cout << "탐색 할 값을 입력하시오:";
		cin >> key;
		for (int i = 0; i < SIZE; i++) {
			if (list_2[i] == key) {         // 입력받은 key 값이 인덱스에 저장되있는 값과 일치하면
				cout << "탐색 성공! 인덱스 = " << i;  // i 출력 후 종료 
				return 0;
			}
		}
		cout << "탐색오류" << endl;
	} while (key != list_2[i]);

	return 0;
}
