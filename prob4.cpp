#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N; //������ ũ��
int color = 1; //����� ����
vector<vector<int>> map;
vector<vector<int>> continent_color;
int dir_x[4] = { 0, 0, -1, 1 }; //�� �� �� ��
int dir_y[4] = { 1, -1, 0, 0 };
void obeserveContinent() //���� �ٸ� ����� �����ϱ� ���� �ٸ� ������ ��ĥ�ϴ� �Լ�
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
				continent_color[i][j] = color; //�湮���� ǥ��, ����� ��ĥ�Ͽ� �ٸ� ����� �����ϱ�
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
								continent_color[new_x][new_y] = color; //�湮���� ǥ��, ����� ��ĥ�Ͽ� �ٸ� ����� �����ϱ�
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
	for (int i = 0; i < N; i++) //������ 0���� �ʱ�ȭ
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
			if (continent_color[i][j] == color) //����� ������ �ٴ� ĭ�� ť�� ���� ����
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
							map[new_x][new_y] = 1; //������� �ش� ĭ���� �̵��ϴ� �� �ʿ��� �Ÿ�
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
					map[new_x][new_y] = map[x][y] + 1; //�ش� ĭ���� �����ϴµ� �ʿ��� �Ÿ� ���ϱ�
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
	map.resize(N, vector<int>(N)); //2���� ���� �ʱ�ȭ

	for (int i = 0; i < N; i++) //���� ������ �Է� �ޱ�
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
		}
	}
	obeserveContinent(); //����� ���� �ٸ� ������ ��ĥ��
	int min = calculate_min_distance(1);
	for (int i = 2; i < color; i++)
	{
		int result = calculate_min_distance(i);
		if (min > result)
			min = result;
	}
	cout << min;
}