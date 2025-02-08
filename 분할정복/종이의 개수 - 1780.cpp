#include <iostream>
#include <vector>
#include <map>
using namespace std;
vector<vector<int>> V;
map<int, int> paper;
void divideAndConquer(int x, int y, int size) //시작점의 좌표, 종이의 크기
{
	int num = V[x][y]; //시작점의 숫자를 받아와서
	bool isSameNum = 1;
	for (int i = x; i < x + size; i++)
	{
		for (int j = y; j < y + size; j++)
		{
			if (V[i][j] != num) //시작점 숫자와 다른 숫자가 있으면 실패
				isSameNum = 0;
		}
	}
	if (isSameNum) //종이가 모두 같은 수로 되어있다면 사용한다.
	{
		paper[num]++;
		return;
	}
	else //그렇지 않다면 9개로 분할하여 반복한다.
	{
		for (int i = x; i < x + size; i += size / 3) //x좌표를 기준으로 size/3 만큼 증가 시켜서 분할함
		{ 
			for (int j = y; j < y + size; j += size / 3) //y좌표를 기준으로 size/3 만큼 증가 시켜서 분할함 
			{
				divideAndConquer(i, j, size / 3); //ex) 003, 033, 063/ 303, 333, 363/ 603, 633, 663
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N; //N*N 행렬 
	cin >> N; //항상 3^k 입력
	V.resize(N, vector<int>(N));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> V[i][j];
		}
	}
	divideAndConquer(0, 0, N);
	cout << paper[-1] << '\n';
	cout << paper[0] << '\n';
	cout << paper[1];
}