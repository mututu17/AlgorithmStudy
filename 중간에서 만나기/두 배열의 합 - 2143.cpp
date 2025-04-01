#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	int A[1000];
	int B[1000];
	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> A[i];
	cin >> m;
	for (int i = 0; i < m; i++)
		cin >> B[i];
	vector<int> VA;
	long long answer = 0;
	for (int start = 0; start < n; start++)
	{
		int sum = 0;
		for (int cur = start; cur < n; cur++)
		{
			sum += A[cur];
			VA.push_back(sum);
		}
	}
	sort(VA.begin(), VA.end());
	for (int start = 0; start < m; start++)
	{
		int sum = 0;
		for (int cur = start; cur < m; cur++)
		{
			sum += B[cur];
			answer += upper_bound(VA.begin(), VA.end(), T - sum) - lower_bound(VA.begin(), VA.end(), T - sum);
		}
	}
	cout << answer;
	return 0;
}