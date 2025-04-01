#include <iostream>
#include <map>
using namespace std;
int pizzaA[1000];
int pizzaB[1000];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int answer = 0;
	int S;
	cin >> S;
	int n, m;
	cin >> m >> n;
	for (int i = 0; i < m; i++)
		cin >> pizzaA[i];
	for (int i = 0; i < n; i++)
		cin >> pizzaB[i];
	map<int, int> map;
	for (int start = 0; start < m; start++)
	{
		int sum = 0;
		for (int i = 0; i < m - 1; i++)
		{
			sum += pizzaA[(start + i) % m];
			if (sum > S)
				break;
			map[sum]++;
		}
	} //공집합과 전체집합 제외
	int sum = 0;
	for (int i = 0; i < m; i++)
	{
		sum += pizzaA[i];
	}
	if (sum <= S)
		map[sum]++; //전체집합(A) 추가
	map[0]++; //공집합(A) 추가
	answer += map[S]; //공집합(B) 추가
	for (int start = 0; start < n; start++)
	{
		int sum = 0;
		for (int i = 0; i < n - 1; i++)
		{
			sum += pizzaB[(start + i) % n];
			if (sum > S)
				break;
			answer += map[S - sum];
		}
	}
	sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += pizzaB[i];
	}
	if (sum <= S)
		answer += map[S - sum]; //전체집합(B) 추가
	cout << answer;
	return 0;
}