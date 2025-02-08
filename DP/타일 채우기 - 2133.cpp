#include <stdio.h>
#pragma warning(disable:4996)
int main()
{
	int N;
	scanf("%d", &N);
	int DP[32] = { 0 };
	DP[0] = 1;
	DP[2] = 3;
	for (int i = 4; i <= N; i += 2)
	{
		DP[i] = (3 * DP[i - 2]);
		for (int j = 4; j <= i; j += 2)
		{
			DP[i] = DP[i] + (2 * DP[i - j]);
		}
	}
	printf("%d", DP[N]);
}