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
	for (int i = 1; i <= N; i++) //1 ~ N�߿� ����� ��� ã��
	{
		if (matrix[root][i] == 1 && visited[i] == 0) //������ְ� �湮���� ���� ���
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
	matrix.resize(N + 1, vector<int>(N + 1)); //0 ~ N-1 �� ���°� �ƴ϶� 1 ~ N�� ���� ����
	visited.resize(N + 1);
	parent.resize(N + 1);
	for (int i = 0; i < N - 1; i++)
	{
		int v1, v2;
		cin >> v1 >> v2;
		matrix[v1][v2] = 1; //���� v1�� v2�� ������ �ǹ�
		matrix[v2][v1] = 1; //�ݴ�ε� ����
	}
	DFS(1);
	for (int i = 2; i <= N; i++)
	{
		cout << parent[i] << '\n';
	}
	return 0;
}