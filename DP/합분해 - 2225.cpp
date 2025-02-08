#include <stdio.h>
#pragma warning(disable:4996)
int main()
{
	int N, K;
	scanf("%d %d", &N, &K);
	long long DP[201][201] = { 0 };
	for (int i = 0; i <= N; i++)
	{
		DP[i][1] = 1;
	}

	for (int j = 2; j <= K; j++) // DP[N][2] 부터 DP[N][K]까지 전부 계산하기 위함
	{
		for (int i = 0; i <= N; i++) //DP[0][K] 부터 DP[N][K]까지 전부 계산하기 위함
		{
			for (int l = 0; l <= i; l++) //DP[i][j]를 계산하기 위함
			{
				DP[i][j] += DP[i-l][j-1] %1000000000;
			}
		}
		
	}
	printf("%d", DP[N][K] % 1000000000);
}