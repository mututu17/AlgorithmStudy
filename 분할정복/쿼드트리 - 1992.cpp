#include <iostream>
using namespace std;
int arr[64][64];
bool isSameAll(int x, int y, int size) //시작점과 크기를 받아요
{
	int color = arr[x][y]; //시작점이 0인지 1인지 구별해서
	for (int i = x; i < x + size; i++)
	{
		for (int j = y; j < y + size; j++)
		{
			if (arr[i][j] != color) //다른 것이 섞여있다면
				return 0; //거짓!
		}
	}
	return 1; //모두 같은 색이므로 참!
}
void devideAndConquer(int x, int y, int size) //시작점과 크기를 받아요
{

	if (isSameAll(x, y, size))
	{
		cout << arr[x][y]; //다 같은 숫자일 때 출력
	}
	else //전체를 한 번에 나타낼 수 없는 경우에
	{
		cout << "("; // 괄호로 묶어서 출력
		for (int i = 0; i < size; i += size / 2) //왼쪽 위, 오른쪽 위
		{
			for (int j = 0; j < size; j += size / 2)//왼쪽 아래. 오른쪽 아래 순으로 출력!
			{
				devideAndConquer(x + i, y + j, size / 2); // (0,0,4),(0,4,4),(4,0,4),(4,4,4) 이렇게 재귀호출
			}
		}
		cout << ")"; //괄호 닫아주기
	}
	return;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N; //영상의 크기 1 <= N <= 64 2의 제곱 수
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string temp;
		cin >> temp; //데이터가 띄어쓰기 없이 들어와서 string으로 받아요
		for (int j = 0; j < N; j++)
		{
			arr[i][j] = temp[j] - '0'; //string에서 하나씩 분할
		}
	}
	devideAndConquer(0, 0, N); //분할정복으로 데이터 압축하기
}