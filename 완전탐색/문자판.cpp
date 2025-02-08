#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int N, M, K;
vector<vector<char>> map;
int DP[100][100][80]; //X, Y칸을 단어의 Z번째 인덱스로 설정했을 때 성공할 수 있는 경로의 개수 저장
int moving[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
string word;
bool isMovable(int x, int y, int dir, int k)
{
	int next_x = x + moving[dir][0] * k;
	int next_y = y + moving[dir][1] * k;
	return next_x >= 0 && next_x < N && next_y >= 0 && next_y < M;
}
int DFS(int x, int y, int level)
{
	if(DP[x][y][level] != -1) return DP[x][y][level];	//이미 방문했던 곳은 계산이 끝났기 때문에 더 계산할 필요 X(DP를 쓰는 이유)
	if (level == word.length()-1) //마지막 레벨은 1가지
	{
		return 1;
	}
	DP[x][y][level] = 0; //방문했음을 표시
	for (int i = 1; i <= K; i++)
	{
		for (int dir = 0; dir < 4; dir++)
		{
			if (isMovable(x, y, dir, i))
			{
				int next_x = x + moving[dir][0] * i;
				int next_y = y + moving[dir][1] * i;
				if (word[level+1] != map[next_x][next_y])
					continue;
				DP[x][y][level] = DP[x][y][level] + DFS(next_x, next_y, level + 1); //이 칸에 방문했을 때 성공할 수 있는 경로의 수 = 현재 칸의 경우의 수 + 다음 레벨의 경우의 수
			}
		}
	}
	return DP[x][y][level];
}
int main()
{

	cin >> N >> M >> K;
	map.resize(N, vector<char>(M));
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < M; j++)
		{
			map[i][j] = str[j];
		}
	}
	cin >> word;
	memset(DP, -1, sizeof(DP)); //초기값을 -1로 설정하여 방문 여부를 구분
	int pathCount = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if(map[i][j] == word[0])
				pathCount += DFS(i, j, 0);
		}
	}
	cout << pathCount;
}