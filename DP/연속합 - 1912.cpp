#include <stdio.h>
#pragma warning(disable:4996)
int max(int a, int b)
{
	return a > b ? a : b;
}
int main()
{
	
	int N;
	int arr[100001];
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}
	int DP[100001]; 
	DP[0] = arr[0];
	int MAX = arr[0];
	for (int i = 1; i < N; i++)
	{
		DP[i] = max(DP[i-1]+arr[i], arr[i]);
		MAX = max(MAX, DP[i]);
	}
	
		printf("%d", MAX);
}