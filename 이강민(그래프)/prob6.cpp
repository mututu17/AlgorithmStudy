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
	for (int i = 0; i < graph[root].size(); i++) //연결된 노드 꺼내오기
	{
		int V = graph[root][i];
		if (!visited[V]) //방문하지 않은 노드
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
		graph[v1].push_back(v2); //정점 v1과 v2의 연결을 의미
		graph[v2].push_back(v1); //반대로도 연결
	}
	DFS(1);
	for (int i = 2; i <= N; i++)
	{
		cout << parent[i] << '\n';
	}
	return 0;
}