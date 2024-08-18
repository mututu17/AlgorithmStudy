#include <iostream>
#include <vector>
using namespace std;
vector<int> graph[100001];
bool visited[100001];
int parent[100001];
int N;
void DFS(int root)
{
	visited[root] = 1;
	for (int i = 0; i < graph[root].size(); i++) //����� ��� ��������
	{
		int V = graph[root][i];
		if (!visited[V]) //�湮���� ���� ���
		{
			parent[V] = root;
			DFS(V);
		}
	}
	return;
}
int main()
{
	cin >> N;
	for (int i = 0; i < N - 1; i++)
	{
		int v1, v2;
		cin >> v1 >> v2;
		graph[v1].push_back(v2); //���� v1�� v2�� ������ �ǹ�
		graph[v2].push_back(v1); //�ݴ�ε� ����
	}
	DFS(1);
	for (int i = 2; i <= N; i++)
	{
		cout << parent[i] << '\n';
	}
	return 0;
}