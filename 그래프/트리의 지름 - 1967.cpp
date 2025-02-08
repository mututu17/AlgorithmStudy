#include <iostream>
#include <vector>
using namespace std;
vector<pair<int, int>> graph[10001];
bool visited[10001];
int leaf, max_d;
void DFS(int root, int dist)
{
	visited[root] = 1;
	for (int i = 0; i < graph[root].size(); i++) //연결된 노드 꺼내오기
	{
		int V = graph[root][i].first;
		int d = graph[root][i].second;
		if (!visited[V]) //방문하지 않은 노드
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
	for (int i = 0; i < N - 1; i++) // 1 ~ N 정점
	{
		int v1, v2, dist;
		cin >> v1 >> v2 >> dist;
		graph[v1].push_back(make_pair(v2, dist));
		graph[v2].push_back(make_pair(v1, dist));

	}
	DFS(1, 0); //리프노드 찾기
	for (int j = 1; j <= N; j++) //visied 배열 초기화
		visited[j] = 0;
	max_d = 0; //최대값 초기화
	DFS(leaf, 0); //리프노드에서 DFS하기
	cout << max_d;
	return 0;
}