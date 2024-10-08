#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int list[10001]; //가지고 있는 카드 저장
	int N; //가지고 있는 카드의 수
	int M; //가지고 있는 지 확인해야 하는 카드의 수 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> list[i];
	}
	sort(list, list + N); //오름차순으로 정렬
	cin >> M;
	int card;
	int mid;
	for (int i = 0; i < M; i++)
	{
		int left = 0;
		int right = N - 1;
		cin >> card; //가지고 있는 지 확인해야 하는 카드
		bool found = 0;
		while (left <= right)
		{
			mid = (right + left) / 2;
			if (list[mid] < card) //찾고 있는 값이 커서 mid 오른쪽에서 찾아야함
			{
				left = mid + 1;
			}
			else if (list[mid] == card) //찾았다.
			{
				found = 1;
				break;
			}
			else //찾고 있는 값이 작아서 mid 왼쪽에서 찾아야함
			{
				right = mid - 1;
			}
		}
		cout << found << " ";
	}
}