#include <stdio.h>
#pragma warning(disable:4996)
int MAX(int a, int b, int c)
{
	if (a > b)
	{
		if (a > c)
			return a;
		else return c;
	}
	else
	{
		if (b > c)
			return b;
		else return c;
	}
}
int main()
{
	int T;
	scanf("%d", &T);
	int arr[10002];
	int DP[10002];
	for (int i = 1; i <= T; i++)
	{
		scanf("%d", &arr[i]);
	}
	DP[0] = 0;
	DP[1] = arr[1];
	DP[2] = DP[1] + arr[2];
	for (int i = 3; i <= T; i++)
	{
		DP[i] = MAX(DP[i - 1], DP[i - 2] + arr[i], DP[i - 3] + arr[i - 1] + arr[i]);
	}
	printf("%d", DP[T]);
}