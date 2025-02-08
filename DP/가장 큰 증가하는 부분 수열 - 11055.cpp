#include <stdio.h>
#pragma warning(disable:4996)
int max(int a, int b)
{
	return a > b ? a : b;
}
int main()
{
	int T;
	int arr[1001];
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		scanf("%d", &arr[i]);
		
	}
	int DP[1001];
	DP[0] = arr[0];
	for (int i = 1; i < T; i++)
	{
		DP[i] = arr[i];
		for (int j = 0; j < i; j++)
		{
			if (arr[i] > arr[j])
			{
				DP[i] = max(DP[i],DP[j] + arr[i]);
			}
		}
	}
	int max = 0;
	for (int i = 0; i < T; i++)
	{
		if (max < DP[i])
		{
			max = DP[i];
		}
	}
	
	printf("%d", max);
}