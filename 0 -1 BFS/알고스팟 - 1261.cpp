#include <iostream>
#include <vector>
#include <deque>
using namespace std;
int moving[4][2] = { { 0,-1 }, { 0, 1 }, {1,0}, {-1,0} };
int N, M;
vector<vector<int>> maze;
vector<vector<int>> dist;
void BFS()
{
	deque<pair<int, int>> dq;
	dist[0][0] = 0;
	dq.push_front({ 0,0 });
	while (!dq.empty())
	{
			
		int cur_x = dq.front().first;
		int cur_y = dq.front().second;
		dq.pop_front();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur_x + moving[dir][0];
			int ny = cur_y + moving[dir][1];
			if (nx >= 0 && nx < M && ny >= 0 && ny < N)
			{
				int newdist = dist[cur_x][cur_y] + maze[nx][ny];
				if (newdist < dist[nx][ny])
				{
					dist[nx][ny] = newdist;
					if (maze[nx][ny] == 0)
						dq.push_front({ nx,ny });
					else //벽을 깨고 도착
						dq.push_back({ nx,ny }); //DFS가 끝난 후에 실행될 경우의 수	
				}
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	maze.resize(M, vector<int>(N));
	dist.resize(M, vector<int>(N,1e9));
	for (int i = 0; i < M; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < N; j++)
		{
			maze[i][j] = s[j] - '0';
		}
	}
	BFS();
	cout << dist[M - 1][N - 1];
	return 0;
}