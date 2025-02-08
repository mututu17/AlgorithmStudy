#include <stdio.h>
#pragma warning(disable:4996)
int main()
{
	int N;
	scanf("%d", &N);
	int arr[1001][10];
	for (int i = 0; i < 10; i++)
	{
		arr[1][i] = 1;
	}
	for (int i = 2; i <= N; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			int sum = 0;
			for (int k = 0; k <= j; k++)
			{
				
				sum += (arr[i - 1][k]) % 10007;
			}
			arr[i][j] = sum;
		}
	}
	int sum2 = 0;
	for (int i = 0; i <= 9; i++)
	{
		sum2 = (sum2 + arr[N][i]) % 10007;
	}
	printf("%d", sum2 % 10007);
}