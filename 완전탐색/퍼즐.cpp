#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <string>
using namespace std;
map <string,bool> visit;
int puzzle[3][3];
int moving[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };
string puzzleTostr()
{
	string str = "";
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			str += to_string(puzzle[i][j]);
		}
	}
	return str;
}
void strTopuzzle(string str)
{
	int idx = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			puzzle[i][j] = str[idx++] - '0';
		}
	}
	return;
}
pair<int, int> find0()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (puzzle[i][j] == 0)
				return make_pair(i, j);
		}
	}
}
bool isMovable(int x, int y, int dir)
{
	int next_x = x + moving[dir][0];
	int next_y = y + moving[dir][1];
	return next_x >= 0 && next_x < 3 && next_y >= 0 && next_y < 3;
}
int BFS()
{
	queue<string> q;
	string s = puzzleTostr();
	visit[s] = 1;
	q.push(s);
	int count = 0;
	while (!q.empty())
	{
		int Qsize = q.size();
		for (int i = 0; i < Qsize; i++)
		{
			string str = q.front();
			q.pop();
			if (str == "123456780")
			{
				return count;
			}
			strTopuzzle(str);
			pair<int, int> p = find0();
			int x = p.first;
			int y = p.second;
			for (int dir = 0; dir < 4; dir++)
			{
				if (isMovable(x, y, dir))
				{
					int next_x = x + moving[dir][0];
					int next_y = y + moving[dir][1];
					swap(puzzle[x][y], puzzle[next_x][next_y]);
					string temp = puzzleTostr();
					if (!visit[temp])
					{
						visit[temp] = 1;
						q.push(temp);
					}
						
					swap(puzzle[x][y], puzzle[next_x][next_y]);
				}
			}
		}
		count++;
	}
	return -1;
}
int main()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> puzzle[i][j];
		}
	}
	cout << BFS();
}