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
	int T, N, tmp;
	int count = 0;
	scanf("%d", &T);
	for(int i = 0; i < T; i++)
	{
		scanf("%d", &N);
		for (int j = 1; j <= N; j++)
		{
			scanf("%d", &tmp);
			graph[j][tmp] = 1;
		}
		for (int j = 1; j <= N; j++)
		{
			if (visit[j] == 0)
			{
				DFS(j, N);
				count++;
			}	
		}
		printf("%d\n", count);
		count = 0;
		for (int j = 0; j < 1001; j++)
			visit[j] = 0;
		for (int x = 0; x < 1001; x++)
		{
			for (int y = 0; y < 1001; y++)
				graph[x][y] = 0;
		}
	}
}