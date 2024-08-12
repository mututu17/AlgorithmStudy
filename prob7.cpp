#include <iostream>
#include <vector>
using namespace std;
vector<pair<int, int>> graph[100001];
bool visited[100001];
int N;
int DFS(int root)
{
	visited[root] = 1;
	int max_dist = 0;
	for (int i = 0; i < graph[root].size(); i++) //����� ��� ��������
	{
		int V = graph[root][i].first;
		int d = graph[root][i].second;
		if (!visited[V]) //�湮���� ���� ���
		{
			int dist = DFS(V) + d;
			if (dist > max_dist)
				max_dist = dist;
		}
	}
	return max_dist;
}
int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++) // 1 ~ N ����
	{
		int v1, v2, dist;
		cin >> v1;
		while (1) //-1�� �Էµ� �� ���� ����� ������ ���� �Է¹ޱ�
		{
			cin >> v2;
			if (v2 == -1)
				break;
			cin >> dist;
			graph[v1].push_back(make_pair(v2, dist));
		}
	}
	int max = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++) //visied �迭 �ʱ�ȭ
			visited[j] = 0;
		int D = DFS(i);
		if (D > max)
			max = D;
	}
	cout << max;

	return 0;
}