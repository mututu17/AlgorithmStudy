#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, S;
	int A[4000], B[4000], C[4000], D[4000];
	vector<int> AB;
	long long answer = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i] >> B[i] >> C[i] >> D[i];
	for (int a = 0; a < N; a++)
	{
		for (int b = 0; b < N; b++)
		{
			int sum = A[a] + B[b];
			AB.push_back(sum);
		}
	}
	sort(AB.begin(), AB.end());
	for (int c = 0; c < N; c++)
	{
		for (int d = 0; d < N; d++)
		{
			int CD = C[c] + D[d];
			// map은 시간 초과, 이분탐색은 중복된 원소를 처리해줄 수 없음
			/*int start = 0, end = AB.size() - 1;
			while (start <= end)
			{
				int mid = (start + end) / 2;
				if (AB[mid] + CD < 0)
				{
					start = mid + 1;
				}
				else if (AB[mid] + CD == 0)
				{
					answer++;
					break;
				}
				else
				{
					end = mid - 1;
				}
			}*/
			answer += upper_bound(AB.begin(),AB.end(),-CD) - lower_bound(AB.begin(), AB.end(), -CD);
		}
	}
	cout << answer;
	return 0;
}