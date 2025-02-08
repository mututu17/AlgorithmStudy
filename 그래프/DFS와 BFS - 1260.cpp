#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
int graph[1001][1001] = { 0, };
int visit[1001] = { 0, };
int queue[1001];
int front = 0;
int rear = 0;
int size = 0;
void enqueue(int item)
{
	rear = (rear + 1) % 1000;
	queue[rear] = item;
	size++;
}
int dequeue()
{
	front = (front + 1) % 1000;
	size--;
	return queue[front];
}
void BFS(int cur, int n)
{
	visit[cur] = 1;
	int i;
    enqueue(cur);
	while (size != 0)
	{
		int V = dequeue();
		printf("%d ", V);
		for (i=1; i <= n; i++)
		{
			if (graph[V][i] == 1 && visit[i] == 0)
			{
				enqueue(i);
				visit[i] = 1;
			}
		}
	}
}
void DFS(int cur, int n)
{
	visit[cur] = 1;
	int i;
	for (i = 1; i <= n; i++)
	{
		if (graph[cur][i] == 1 && visit[i] == 0)
		{
			printf("%d ", i);
			DFS(i, n);
		}
	}
}
int main()
{
	int v, e, start;
	scanf("%d %d %d", &v, &e, &start);
	for (int i = 0; i < e; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		graph[x][y] = 1;
		graph[y][x] = 1;
	}
	printf("%d ", start);
	DFS(start, v);
	printf("\n");
	for (int i = 0; i < 1001; i++)
		visit[i] = 0;
	BFS(start, v);
}