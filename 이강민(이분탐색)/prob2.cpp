#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int tree[10001];
	int N; //벨 수 있는 나무의 수 
	int M; //집으로 가져가려는 나무의 길이 
	int result = 0; //절단기에 설정할 수 있는 최대 높이
	int max_tree = 0; //벨 수 있는 나무 중 가장 높은 나무
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> tree[i];
		max_tree = max(max_tree, tree[i]);
	}
	int left = 0; //다 베어비겠다.
	int right = max_tree - 1; // 가장 높은 나무들만 1m씩 벤다.
	int mid;
	while (left <= right)
	{
		mid = (right + left) / 2;
		long long count = 0;
		for (int i = 0; i < N; i++)
		{
			if (tree[i] > mid)
				count += tree[i] - mid; //베어서 얻은 나무
		}
		if (count >= M) //절단기 높이의 더 큰 값을 얻기 위함
		{
			left = mid + 1;
			result = max(result, mid);
		}
		else //조건을 충족하기 위해서 높이를 낮춤
		{
			right = mid - 1;
		}
	}
	cout << result;
}