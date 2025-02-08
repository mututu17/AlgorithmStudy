#include <stdio.h>
#include <math.h>
#pragma warning(disable:4996)
int visit[240001] = {0, }; 
int P;
int CalculateD(int N)
{
	int sum = 0;
	while (N)
	{
		sum += pow((N % 10), P);
		N /= 10;
	}
	return sum;
}
void DFS(int start)
{
	visit[start]++;
	if (visit[start] == 3)
		return;
	else
	{
		int next = CalculateD(start);
		DFS(next);
	}
}

int main()
{
	int A;
	scanf("%d %d", &A, &P);
	DFS(A);
	int sum = 0;
	for (int i = 0; i <= 240000; i++)
	{
		if (visit[i] == 1)
			sum++;
	}
	printf("%d", sum);
}