#include <stdio.h>
#pragma warning(disable:4996)
int max(int a, int b)
{
	return a > b ? a : b;
}
int main()
{
	int T;
	int arr[1001];
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		scanf("%d", &arr[i]);
		
	}
	int asc[1001];
	int des[1001];
	asc[0] = 1;
	des[T-1] = 1;
	for (int i = 1; i < T; i++)
	{
		asc[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (arr[i] > arr[j])
			{
				asc[i] = max(asc[i],asc[j] + 1);
			}
		}
	}
	for (int i = 1; i < T; i++)
	{
		des[T-1-i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (arr[T-i-1] > arr[T-j-1])
			{
				des[T-1-i] = max(des[T-1-i], des[T-j-1] + 1);
			}
		}
	}
	int max = 0;
	for (int i = 0; i < T; i++)
	{
		if (max < asc[i] + des[i] - 1)
		{
			max = asc[i] + des[i] - 1;
		}
	}
	
	printf("%d", max);
}