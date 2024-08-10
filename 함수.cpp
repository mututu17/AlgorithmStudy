#include <iostream>
#include <string.h>
#include <time.h>
#include <stdlib.h>

using namespace std;
#define SIZE 10
int binary_serach(int list[], int n, int key);
int rand_index(int list[]);
int rand_index_print(int list[]);
int selection_sort(int list[]);


int main()
{
	// 난수를 배열에 저장한 후 선택 정렬로 정렬하여 2진 탐색을 이용하여 배열에 저장된 값 중 입력받은 값의 index를 찾는 프로그램
	int key;
	int index[SIZE] = {};
	cout << "Before sorted : " << endl;
	rand_index(index); 
	rand_index_print(index);  // 랜덤한 숫자가 저장된 배열 출력 

	cout << "\n\n" << "Ater sorted : " << endl;
	selection_sort(index);    // 선택정렬 호출
	while (1)
	{
		cout << "\n\n" << "탐색할 값 - 입력: " << endl;
		cin >> key;
		cout << "탐색한 결과(Index) : " << "\n";
		int result = binary_serach(index, SIZE, key); // 2진 탐색 함수 출력 * 함수를 호출만 하면 값을 나타낼 수 없음. 출력함수에 호출해야 값이 반환됨
		if (result != -1) //실행 오류가 아니면 result 출력
		{
			cout << result;
			break;
		}
		//-1인 경우에 다시 탐색할 값을 입력 받음
	}
	return 0;
}


int rand_index(int list[]) {     // 1~100까지의 랜덤한 난수를 배열에 저장하는 함수(중복 제외)  
	srand((unsigned)time(NULL));
	for (int i = 0; i < SIZE; i++) {
		list[i] = (rand() % 100) + 1;
		for (int j = 0; j < i; j++) {  
			if (list[i] == list[j]) { // 중복인 숫자 제외
				i--;
				break;
			}
		}
	}
	return 0;
}

int rand_index_print(int list[]) {      // 저장된 배열의 값을 출력하는 함수 
	for (int i = 0; i < SIZE; i++) {
		cout << list[i] << ",";
	}
	return 0;
}

int selection_sort(int list[]) {            // 선택정렬 함수 
	int least, temp;
	for (int i = 0; i < SIZE - 1; i++) {
		for (int j = i + 1; j < SIZE; j++) {  // 가장 작은 값을 찾음
			}
		}
		temp = list[i];                  // 가장 작은 값을 0번째 index와 서로 자리를 바꿈   
		list[i] = list[least];
		list[least] = temp;
	}
	for (int k = 0; k < SIZE; k++) {    // 정렬된 숫자 출력
		cout << list[k] << ",";
	}
	return 0;
}

int binary_serach(int list[], int n, int input) { // 2진 탐색 함수

	int low, high, middle,i;
	low = 0;                  //초기 low 값은 index 0
	high = n - 1;				// 초기 high 값은 index n-1

	while (low <= high) {
		middle = (low + high) / 2;      // middle 은 low와 high의 중간 
		if (input == list[middle]) {    // 입력 받은 탐색 값이 list[middle] 값이면 middle 반환
			return middle;
		}
		else if (input > list[middle]) { // 탐색 값이 list[middle] 보다 크면
			low = middle + 1;            //  middle index의 오른쪽을 기준으로 다시 low 값 재설정 (low = middle +1 )
		}
		else {
			high = middle - 1;			// 작다면 middle index 오른쪽을 기준으로 high 값 재설정 (high = middle -1 )
		}
	}

	//입력에 없는 값이면 -1이 출력될 것이고 있는 값이면 인덱스가 출력되기 때문에 0이 출력될 일은 이론 상 없음 
	return 0; //오류 
}