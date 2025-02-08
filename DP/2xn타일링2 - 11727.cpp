#include <stdio.h>
#pragma warning(disable:4996)
int main()
{
	int N;
	int arr[1001];
	scanf("%d", &N);
	arr[1] = 1;
	arr[2] = 3;
	for (int i = 3; i <= N; i++)
	{
		arr[i] = ((arr[i - 1] + 2 * arr[i - 2]) % 10007);
	}
	
	printf("%d", arr[N]);
}