#include <stdio.h>
#pragma warning(disable:4996)
int max(int a, int b)
{
	return a > b ? a : b;
}
int main()
{
	int N;
	int DP[1002];
	int P[1002];
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)//카드 가격 입력 받기
	{
		scanf("%d", &P[i]);
	}
	DP[0] = 0;
	DP[1] = P[1]; //카드 1장을 사기위한 최댓값
	for (int i = 1; i <= N; i++) //DP[N]을 구하기 위한 계산
	{
		DP[i] = P[i];
		for (int j = 0; j <= i; j++)
		{
			DP[i] = max(DP[i], DP[j] + DP[i - j]); //DP[j] + DP[i-j] 로 DP[i]구하기
		}
		
	}
	printf("%d", DP[N]); //카드 N개를 사기 위한 최댓값
}