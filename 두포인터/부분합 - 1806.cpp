#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int arr[100000];
	int N, S;
	int minLength = 0;
	cin >> N >> S;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	/*for (int i = 0; i < N; i++) 시간초과 때문에 두 포인터 알고리즘 사용해야함
	{
		int sum = 0;
		for (int j = i; j < N; j++)
		{
			sum += arr[j];
			if (sum >= S)
			{
				if (j - i + 1 < minLength || minLength == 0)
					minLength = j - i + 1;
				break;
			}
		}
	}*/
	int start = 0, end = 0, sum = 0;
	while (end < N)
	{
		sum += arr[end++];
		while (sum >= S)
		{
			if (end - start < minLength || minLength == 0)
				minLength = end - start;
			sum -= arr[start++];
		}
	}
	cout << minLength;
	return 0;
}