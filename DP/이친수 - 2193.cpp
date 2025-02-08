#include <stdio.h>
#pragma warning(disable:4996)
int main()
{
	int N;
	scanf("%d", &N);
	long long arr[91][3];
	arr[1][1] = 1;
	arr[1][0] = 0;
	arr[2][0] = 1;
	arr[2][1] = 0;
	for (int i = 3; i <= N; i++)
	{
		arr[i][1] = arr[i - 1][0];
		arr[i][0] = arr[i - 1][0] + arr[i - 1][1];

	}
	long long sum = arr[N][1] + arr[N][0];
	printf("%lld", sum);
}