#include <iostream>
#include <queue>
#include <set>
#include <map>
using namespace std;
int A, B, C;
set<int> availableList;
map<pair<int, pair<int, int>>, bool> visit;
pair<int, int> pourXintoY(int x, int y, int Y)
{
	//X Y는 물통의 최대 용량
	//x y는 물통에 현재 들어있는 물의 양
	if (x + y > Y) //x를 다 부을 수 없어서 y의 최대 용량까지 붓는다. 
	{
		x = x - Y + y;
		y = Y;
	}
	else //다 붓는다.
	{
		y = x + y;
		x = 0;
	}
	return make_pair(x, y);
}
void BFS()
{
	queue<pair<int, pair<int, int>>> q;
	pair<int, pair<int, int>> p = make_pair(0, make_pair(0, C));
	visit[p] = 1;
	q.push(p);
	while (!q.empty())
	{
		int a = q.front().first;
		int b = q.front().second.first;
		int c = q.front().second.second;
		q.pop();
		if (a == 0 && C != 0)
		{
			availableList.insert(c);
		}
		pair<int, int> P;
		if (a != 0)
		{
			P = pourXintoY(a, b, B);
			p = make_pair(P.first, make_pair(P.second, c));
			if (!visit[p])
			{
				visit[p] = 1;
				q.push(p);
			}
			P = pourXintoY(a, c, C);
			p = make_pair(P.first, make_pair(b, P.second));
			if (!visit[p])
			{
				visit[p] = 1;
				q.push(p);
			}
		}
		if (b != 0)
		{
			P = pourXintoY(b, a, A);
			p = make_pair(P.second, make_pair(P.first, c));
			if (!visit[p])
			{
				visit[p] = 1;
				q.push(p);
			}
			P = pourXintoY(b, c, C);
			p = make_pair(a, make_pair(P.first, P.second));
			if (!visit[p])
			{
				visit[p] = 1;
				q.push(p);
			}
		}
		if (c != 0)
		{
			P = pourXintoY(c, a, A);
			p = make_pair(P.second, make_pair(b, P.first));
			if (!visit[p])
			{
				visit[p] = 1;
				q.push(p);
			}
			P = pourXintoY(c, b, B);
			p = make_pair(a, make_pair(P.second, P.first));
			if (!visit[p])
			{
				visit[p] = 1;
				q.push(p);
			}
		}
	}
	return;
}
int main()
{
	cin >> A >> B >> C;
	BFS();
	for (auto l : availableList)
		cout << l << " ";
}