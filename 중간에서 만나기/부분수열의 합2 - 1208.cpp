#include <iostream>
#include <map>
using namespace std;
int N, S;
int arr[40];
map<int, int> total;
long long answer = 0;
void leftSum(int start, int sum)
{
	if (start == N / 2)
	{
		total[sum]++;
		return;
	}
	leftSum(start + 1, sum);
	leftSum(start + 1, sum + arr[start]);
}
void rightSum(int mid, int sum)
{
	if (mid == N)
	{
		answer += total[S - sum];
		return;
	}
	rightSum(mid + 1, sum);
	rightSum(mid + 1, sum + arr[mid]);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> S;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	leftSum(0, 0);
	rightSum(N / 2, 0);
	if (S == 0)
		answer--;
	cout << answer;
	return 0;
}