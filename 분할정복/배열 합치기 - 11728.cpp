#include <iostream>
#include <vector>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M; //배열 A, B의 크기
	vector<int> V;
	cin >> N >> M;
	vector<int> A(N);
	vector<int> B(M);
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	for (int i = 0; i < M; i++)
	{
		cin >> B[i];
	}
	auto A_it = A.begin();
	auto B_it = B.begin();
	while (A_it != A.end() && B_it != B.end())
	{
		if (*A_it <= *B_it)
		{
			V.push_back(*A_it);
			A_it++;
		}
		else
		{
			V.push_back(*B_it);
			B_it++;
		}
	}
	while (A_it != A.end())
	{
		V.push_back(*A_it);
		A_it++;
	}
	while (B_it != B.end())
	{
		V.push_back(*B_it);
		B_it++;
	}
	for (auto t : V)
	{
		cout << t << " ";
	}
}