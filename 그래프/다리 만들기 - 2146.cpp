#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N; //지도의 크기
int color = 1; //대륙의 개수
vector<vector<int>> map;
vector<vector<int>> continent_color;
int dir_x[4] = { 0, 0, -1, 1 }; //상 하 좌 우
int dir_y[4] = { 1, -1, 0, 0 };
void obeserveContinent() //서로 다른 대륙을 구별하기 위해 다른 색으로 색칠하는 함수
{
	continent_color.resize(N, vector<int>(N));
	queue<pair<int, int>> q;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == 1 && continent_color[i][j] == 0)
			{
				q.push(make_pair(i, j));
				continent_color[i][j] = color; //방문했음 표시, 대륙을 색칠하여 다른 대륙을 구분하기
				while (!q.empty())
				{
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					for (int k = 0; k < 4; k++)
					{
						int new_x = x + dir_x[k];
						int new_y = y + dir_y[k];
						if (0 <= new_x && new_x < N && 0 <= new_y && new_y < N)
						{
							if (continent_color[new_x][new_y] == 0 && map[new_x][new_y] == 1)
							{
								q.push(make_pair(new_x, new_y));
								continent_color[new_x][new_y] = color; //방문했음 표시, 대륙을 색칠하여 다른 대륙을 구분하기
							}
						}
					}
				}
				color++;
			}
		}
	}
	return;
}
int calculate_min_distance(int color)
{
	for (int i = 0; i < N; i++) //지도를 0으로 초기화
	{
		for (int j = 0; j < N; j++)
		{
			map[i][j] = 0;
		}
	}
	queue<pair<int, int>> q;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (continent_color[i][j] == color) //대륙과 인접한 바다 칸을 큐에 넣을 것임
			{
				for (int k = 0; k < 4; k++)
				{
					int new_x = i + dir_x[k];
					int new_y = j + dir_y[k];
					if (0 <= new_x && new_x < N && 0 <= new_y && new_y < N)
					{
						if (continent_color[new_x][new_y] == 0)
						{
							q.push(make_pair(new_x, new_y));
							map[new_x][new_y] = 1; //대륙에서 해당 칸까지 이동하는 데 필요한 거리
						}
					}
				}
			}
		}
	}
	int count = 100000;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++)
		{
			int new_x = x + dir_x[k];
			int new_y = y + dir_y[k];
			if (0 <= new_x && new_x < N && 0 <= new_y && new_y < N)
			{
				if (continent_color[new_x][new_y] == 0 && map[new_x][new_y] == 0)
				{
					q.push(make_pair(new_x, new_y));
					map[new_x][new_y] = map[x][y] + 1; //해당 칸까지 도착하는데 필요한 거리 구하기
				}
				if (continent_color[new_x][new_y] != color && continent_color[new_x][new_y] != 0 && count > map[x][y])
				{
					count = map[x][y];
				}
			}
		}
	}
	return count;
}
int main()
{

	cin >> N;
	map.resize(N, vector<int>(N)); //2차원 벡터 초기화

	for (int i = 0; i < N; i++) //지도 데이터 입력 받기
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
		}
	}
	obeserveContinent(); //대륙을 서로 다른 색으로 색칠함
	int min = calculate_min_distance(1);
	for (int i = 2; i < color; i++)
	{
		int result = calculate_min_distance(i);
		if (min > result)
			min = result;
	}
	cout << min;
}