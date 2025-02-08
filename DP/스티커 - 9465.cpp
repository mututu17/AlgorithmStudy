#include <stdio.h>
#pragma warning(disable:4996)
int MAX(int a, int b)
{
	return a > b ? a : b;
}
int main()
{
	int T, N;
	scanf("%d", &T);
	int arr[2][100002];
	int DP[2][100002];
	while (T-- > 0)
	{
		scanf("%d", &N);
		for (int j = 1; j <= N; j++)
		{
			scanf("%d", &arr[0][j]);
		}
		for (int j = 1; j <= N; j++)
		{
			scanf("%d", &arr[1][j]);
		}
		arr[0][0] = 0;
		arr[1][0] = 0;
		DP[0][0] = 0;
		DP[1][0] = 0;
		DP[0][1] = arr[0][1];
		DP[1][1] = arr[1][1];
		for (int a = 2; a <= N; a++)
		{
			DP[0][a] = MAX(DP[1][a - 1], DP[1][a - 2]) + arr[0][a];
			DP[1][a] = MAX(DP[0][a - 1], DP[0][a - 2]) + arr[1][a];
		}
		printf("%d\n", MAX(DP[0][N], DP[1][N]));
	}


}