#include <iostream>
using namespace std;
char arr[3072][6143]; //별 or 공백을 저장할 배열
void devideAndConquer(int x, int y, int size)
{
	if (size == 1)//재귀호출하여 size가 1이면 별 저장
		arr[x][y] = '*';
	else if (size == 3)
	{
		for (int i = 0; i < 3; i++)//x축
		{
			for (int j = 0; j < 3-i; j++) //y축
			{
				if (i != 0 || j != 1)
				{
					devideAndConquer(x - j, y + i, 1);
					devideAndConquer(x - j, y - i, 1);
				}
			}
		}
	}
	else
	{
		devideAndConquer(x, y + size/2, size/2);
		devideAndConquer(x, y - size/2, size/2);
		devideAndConquer(x - size/2, y, size/2);
	}
	return;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N; //패턴의 크기 3 * 2^K  0<= K <= 10 
	cin >> N;
	for (int i = 0; i < N; i++) //공백으로 초기화
	{
		for (int j = 0; j < 2 * N - 1; j++)
		{
			arr[i][j] = ' ';
		}
	}
	devideAndConquer(N-1, N-1, N);
	for (int i = 0; i < N; i++) //배열에 저장된 별 패턴을 출력
	{
		for (int j = 0; j < 2 * N - 1; j++)
		{
			cout << arr[i][j];
		}
		if(i != N-1)
			cout << '\n';
	}
}