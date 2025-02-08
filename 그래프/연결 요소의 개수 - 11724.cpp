#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
int graph[1001][1001] = { 0, };
int visit[1001] = { 0, };
void DFS(int cur, int n)
{
	visit[cur] = 1;
	int i;
	for (i = 1; i <= n; i++)
	{
		if (graph[cur][i] == 1 && visit[i] == 0)
		{
			DFS(i, n);
		}
	}
}
int main()
{
	int v, e,start;
	scanf("%d %d", &v, &e);
	for (int i = 0; i < e; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		graph[x][y] = 1;
		graph[y][x] = 1;
	}
	int count = 0;
	int result = 0;
	while (1)
	{
		for (int i = 1; i <= v; i++)
		{
			if (visit[i] == 0)
			{
				start = i;
				break;
			}
			if (i == v)
				result = 1;
		}
		if (result == 0)
		{
			DFS(start, v);
			count++;
		}
		if (result == 1)
			break;
	}
	printf("%d", count);
}