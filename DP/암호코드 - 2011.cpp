#include <stdio.h>
#pragma warning(disable:4996)
int main()
{
	char secret[5001];
	int DP[5002];
	int N = 0;
	int result = 1;
	scanf("%s", secret);
	DP[0] = 1;
	DP[1] = 1;
	for (int i = 2; i <= 5000; i++)
	{
		DP[i] = (DP[i - 1] + DP[i - 2]) %1000000;
	}
	for (int i = 0; secret[i] != '\0'; i++)
	{
		if (secret[i] - '0' == 1) 
		{
			
			N++;
			if (secret[i + 1] - '0' == 0)
			{
				N--;
			}
			if (secret[i + 1] == '\0')
			{
				result = (result * DP[N]) % 1000000;
			}
			
		}
		else if (secret[i] - '0' == 2)
		{
			if (secret[i + 1] - '0' >= 1 && secret[i + 1] - '0' <= 6)
			{
				N++;
			}
		    else if (secret[i + 1] == '\0')
			{
				N++;
				result = (result * DP[N]) % 1000000;
			}

		}
		else if (secret[i] - '0' == 0)
		{
			if (i == 0)
			{
				result = 0;
				break;
			}
			else if (secret[i - 1] - '0' != 1 && secret[i - 1] - '0' != 2)
			{
				result = 0;
				break;
			}
			else
			{
				result = (result * DP[N]) % 1000000;
				N = 0;
			}
		}
		else 
		{
			N++;
			result = (result * DP[N]) %1000000;
			N = 0;
		}
	}
	printf("%d", result%1000000);
	return 0;
}