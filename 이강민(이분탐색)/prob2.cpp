#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int tree[10001];
	int N; //�� �� �ִ� ������ �� 
	int M; //������ ���������� ������ ���� 
	int result = 0; //���ܱ⿡ ������ �� �ִ� �ִ� ����
	int max_tree = 0; //�� �� �ִ� ���� �� ���� ���� ����
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> tree[i];
		max_tree = max(max_tree, tree[i]);
	}
	int left = 0; //�� �����ڴ�.
	int right = max_tree - 1; // ���� ���� �����鸸 1m�� ����.
	int mid;
	while (left <= right)
	{
		mid = (right + left) / 2;
		long long count = 0;
		for (int i = 0; i < N; i++)
		{
			if (tree[i] > mid)
				count += tree[i] - mid; //��� ���� ����
		}
		if (count >= M) //���ܱ� ������ �� ū ���� ��� ����
		{
			left = mid + 1;
			result = max(result, mid);
		}
		else //������ �����ϱ� ���ؼ� ���̸� ����
		{
			right = mid - 1;
		}
	}
	cout << result;
}