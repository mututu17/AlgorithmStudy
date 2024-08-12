#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> matrix;
vector<int> visited;
vector<int> parent;
int N;
void DFS(int root)
{
	visited[root] = 1;
	for (int i = 1; i <= N; i++) //1 ~ N중에 연결된 노드 찾기
	{
		if (matrix[root][i] == 1 && visited[i] == 0) //연결되있고 방문하지 않은 노드
		{
			parent[i] = root;
			DFS(i);
		}
	}
	return;
}
int main()
{
	cin >> N;
	matrix.resize(N + 1, vector<int>(N + 1)); //0 ~ N-1 을 쓰는게 아니라 1 ~ N을 쓰기 위함
	visited.resize(N + 1);
	parent.resize(N + 1);
	for (int i = 0; i < N - 1; i++)
	{
		int v1, v2;
		cin >> v1 >> v2;
		matrix[v1][v2] = 1; //정점 v1과 v2의 연결을 의미
		matrix[v2][v1] = 1; //반대로도 연결
	}
	DFS(1);
	for (int i = 2; i <= N; i++)
	{
		cout << parent[i] << '\n';
	}
	return 0;
}