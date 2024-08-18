#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int LAN[10001];
	int K; //ó�� ������ �ִ� ���� �� (10000����)
	int N; //������ �ϴ� ���� �� 
	long long result = 0; //������ �����ϴ� ������ �ִ� ���� 
	int MAX_LAN = 0; //������ �ִ� ���� �� �ְ�
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