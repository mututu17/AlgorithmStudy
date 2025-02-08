#include <stdio.h>
int N;
int arr[1000001];
int min(int a, int b)
{
	if (a > b)
	{
		return b;
	}
	else return a;
}
void solution()
{
	arr[1] = 0;
	int temp;
	for (int i = 2; i <= N; i++)
	{
		arr[i] = arr[i - 1] + 1;
		if (i % 3 == 0)
		{
			temp = arr[i / 3] + 1;
			arr[i] = min(temp, arr[i]);
		}
		if (i % 2 == 0)
		{
			temp = arr[i / 2] + 1;
			arr[i] = min(temp, arr[i]);
		}
	}
	printf("%d", arr[N]);
}
int main()
{

	scanf("%d", &N);
	solution();
}