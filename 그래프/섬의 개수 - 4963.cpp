#include <stdio.h>
#pragma warning(disable:4996)
int arr[51][51] = { 0, };
int visit[51][51] = { 0, };
void DFS(int curA, int curB, int h, int w)
{
	visit[curA][curB] = 1;
	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			if (curA + i >= 0 && curB + j >= 0 && curA + i <= h && curB + j <= w)
			{
				if (visit[curA + i][curB + j] == 0 && arr[curA + i][curB + j] == 1)
				{
					DFS(curA + i, curB + j, h, w);
				}
			}
		}
	}
}
int main()
{
	int w, h;
	scanf("%d %d", &w, &h);
	while (w != 0 || h != 0)
	{
		int land = 0;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				scanf("%d", &arr[i][j]);
			}
		}
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (arr[i][j] == 1 && visit[i][j] == 0)
				{
					DFS(i, j, h, w);
					land++;
				}
			}
		}
		printf("%d\n", land);
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				visit[i][j] = 0;
				arr[i][j] = 0;
			}
		}
		scanf("%d %d", &w, &h);
	}
}