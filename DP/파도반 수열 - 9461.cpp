#include <stdio.h>
#pragma warning(disable:4996)
int main()
{
	int N, T;
	long long P[102];
	P[1] = 1;
	P[2] = 1;
	P[3] = 1;
	P[4] = 2;
	P[5] = 2;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		scanf("%d", &N);
		for (int i = 6; i <= N; i++)
		{
			P[i] = P[i - 1] + P[i - 5];
		}
		printf("%lld\n", P[N]);
	}
}