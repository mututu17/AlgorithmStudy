#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
bool isPrime(int a)
{
	for (int i = 2; i <= sqrt(a); i++)
	{
		if (a % i == 0)
			return false;
	}
	return true;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<int> prime;
	int N;
	int answer = 0;
	cin >> N;
	for (int i = 2; i <= N; i++)
	{
		if (isPrime(i))
			prime.push_back(i);
	}
	int start = 0, end = 0, sum = 0;
	while (end < prime.size())
	{
		sum += prime[end++];
		while (sum >= N)
		{
			if (sum == N)
				answer++;
			sum -= prime[start++];
		}
	}
	cout << answer;
	return 0;
}