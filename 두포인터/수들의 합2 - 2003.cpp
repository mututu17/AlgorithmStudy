#include <iostream>
using namespace std;
int main()
{
	int arr[10000];
	int N, M;
	int result = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < N; i++)
	{
		int sum = 0;
		for (int j = i; j < N; j++)
		{
			sum += arr[j];
			if (sum == M)
			{
				result++;
				break;
			}
		}
	}
	cout << result;
	return 0;
}