#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int N, M; // ������ ũ�� N*M
vector<vector<int>> moving = { {-1,0}, {1,0}, {0,1}, {0,-1} };
vector<vector<int>> arr; // 2���� ���� ����
vector<vector<int>> visited; //�湮�ߴ� ĭ ǥ���ϱ�
vector<vector<int>> dist; //���� ĭ���� �̵��� �Ÿ��� ���
queue<pair<int, int>> q;

void BFS(int x, int y)
{
    visited[x][y] = 1;
    dist[x][y] = 1;
    q.push(make_pair(x, y));
    while (!q.empty())
    {
        int X = q.front().first;
        int Y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) //���� �̵��� ĭ�� ť�� �ֱ�
        {
            int next_x = X + moving[i][0];
            int next_y = Y + moving[i][1];
            if (0 <= next_x && next_x < N && 0 <= next_y && next_y < M)// 0 <= x < N, 0 <= y < M  
            {
                if (arr[next_x][next_y] == 1 && visited[next_x][next_y] == 0)
                { //�湮���� ���� ĭ�̰�, �̷��� �̵��� �� �ִ� ĭ
                    q.push(make_pair(next_x, next_y));
                    visited[next_x][next_y] = 1;
                    dist[next_x][next_y] = dist[X][Y] + 1;
                }
            }
        }
    }
}
int main()
{
    cin >> N >> M;
    arr.resize(N, vector<int>(M)); // 2���� ���� ũ�� ����
    visited.resize(N, vector<int>(M));
    dist.resize(N, vector<int>(M));
    for (int i = 0; i < N; i++) // N*M ���� �Է� �ޱ�
    {
        string line;
        cin >> line; // ���ڿ��� �Է� �ޱ�
        for (int j = 0; j < M; j++)
        {
            arr[i][j] = line[j] - '0'; // ���ڸ� ������ ��ȯ�Ͽ� ����
        }
    }
    BFS(0, 0);
    cout << dist[N - 1][M - 1];
    return 0;
}