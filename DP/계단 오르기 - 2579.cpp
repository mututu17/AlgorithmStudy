#include <stdio.h>
#pragma warning(disable:4996)
int max(int a, int b)
{
	return a > b ? a : b;
}
int main()
{
	
	int N;
	int arr[301];
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}
	int DP1[301];
	int DP2[301];
	DP1[0] = arr[0];
	DP2[0] = arr[0];
	DP1[1] = arr[1] + arr[0];
	DP2[1] = arr[1];
	for (int i = 2; i < N-1; i++)
	{
		DP1[i] = DP2[i-1] + arr[i];
		DP2[i] = max(DP1[i-2] + arr[i], DP2[i-2] + arr[i]);
	}
	DP1[N-1] = DP2[N-2] + arr[N-1];
	DP2[N-1] = max(DP1[N-3] + arr[N-1], DP2[N-3] + arr[N-1]);
	printf("%d", max(DP1[N-1],DP2[N-1]));
		
}