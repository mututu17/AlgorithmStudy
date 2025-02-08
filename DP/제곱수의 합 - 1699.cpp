#include <stdio.h>
#pragma warning(disable:4996)
int min(int a, int b)
{
	return a > b ? b : a;
}
int main()
{
	int a, N;
	scanf("%d", &N);
	int DP[100001];
	DP[0] = 0;
	DP[1] = 1;
	DP[2] = 2;
	DP[3] = 3;
	for (int i = 4; i <= N; i++)
	{
		DP[i] = i;
		for (int j = 1; j * j <= i; j++)
		{
			DP[i] = min(DP[i], DP[i - j * j] + 1);
		}

	}
	printf("%d", DP[N]);
}