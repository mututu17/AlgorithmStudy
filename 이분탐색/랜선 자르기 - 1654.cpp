#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int LAN[10001];
	int K; //처음 가지고 있는 랜선 수 (10000이하)
	int N; //만들어야 하는 랜선 수 
	long long result = 0; //조건을 만족하는 랜선의 최대 길이 
	int MAX_LAN = 0; //가지고 있는 랜선 중 최고값
	cin >> K >> N;
	for (int i = 0; i < K; i++)
	{
		cin >> LAN[i];
		MAX_LAN = max(MAX_LAN, LAN[i]);
	}
	long long left = 1;
	long long right = MAX_LAN;
	long long mid;
	while (left <= right)
	{
		mid = (right + left) / 2;
		int count = 0;
		for (int i = 0; i < K; i++)
		{
			count += LAN[i] / mid;
		}
		if (count >= N)
		{
			left = mid + 1;
			result = max(result, mid);
		}
		else
		{
			right = mid - 1;
		}
	}
	cout << result;
}