#include <iostream>
#include <vector>
using namespace std;
vector<pair<int, int>> graph[100001];
bool visited[100001];
int leaf, max_d;
void DFS(int root, int dist)
{
	visited[root] = 1;
	for (int i = 0; i < graph[root].size(); i++) //����� ��� ��������
	{
		int V = graph[root][i].first;
		int d = graph[root][i].second;
		if (!visited[V]) //�湮���� ���� ���
		{
			DFS(V, dist + d);
		}
	}
	if (dist > max_d)
	{
		leaf = root;
		max_d = dist;
	}
	return;
}
int main()
{
	int N;
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
	DFS(1, 0); //������� ã��
	for (int j = 1; j <= N; j++) //visied �迭 �ʱ�ȭ
		visited[j] = 0;
	max_d = 0; //�ִ밪 �ʱ�ȭ
	DFS(leaf, 0); //������忡�� DFS�ϱ�
	cout << max_d;
	return 0;
}