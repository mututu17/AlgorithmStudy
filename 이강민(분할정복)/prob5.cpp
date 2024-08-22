#include <iostream>
using namespace std;
char arr[6561][6561]; //별 or 공백을 저장할 배열
void devideAndConquer(int x, int y, int size, bool star)
{
	if (size == 1 && star)//재귀호출하여 size가 1이되면 star에 따라 
		arr[x][y] = '*'; //별 또는
	else if (size == 1 && !star)
		arr[x][y] = ' '; //공백 중 하나를 저장합니다
	else if (size != 1 && star)
	{
		for (int i = x; i < x + size; i += size / 3) //size를 3으로 나눠가면서 9칸으로 분할합니다.
		{
			for (int j = y; j < y + size; j += size / 3)
			{
				if (i == x + size / 3 && j == y + size / 3) //가운데 칸은 star를 표시하지 않도록 star를 0으로 만들어줍니다
					devideAndConquer(i, j, size / 3, 0);
				else
					devideAndConquer(i, j, size / 3, 1);
			}
		}
	}
	else //star가 0인 경우
	{
		for (int i = x; i < x + size; i += size / 3)
			for (int j = y; j < y + size; j += size / 3) //size를 줄일 때 9칸의 star는 모두 0으로 재귀호출
				devideAndConquer(i, j, size / 3, 0);
	}
	return;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N; //패턴의 크기 3^K  1<= K <= 8 3의 제곱 수
	cin >> N;
	devideAndConquer(0, 0, N, 1);
	for (int i = 0; i < N; i++) //입력 받은 크기만큼 배열에 저장된 별 패턴을 출력
	{
		for (int j = 0; j < N; j++)
		{
			cout << arr[i][j];
		}
		cout << '\n';
	}
}