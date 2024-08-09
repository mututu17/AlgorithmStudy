#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int N, M; // 지도의 크기 N*M
vector<vector<int>> moving = { {-1,0}, {1,0}, {0,1}, {0,-1} };
vector<vector<int>> arr; // 2차원 벡터 선언
vector<vector<int>> visited; //방문했던 칸 표시하기
vector<vector<int>> dist; //현재 칸까지 이동한 거리를 기록
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
        for (int i = 0; i < 4; i++) //다음 이동할 칸을 큐에 넣기
        {
            int next_x = X + moving[i][0];
            int next_y = Y + moving[i][1];
            if (0 <= next_x && next_x < N && 0 <= next_y && next_y < M)// 0 <= x < N, 0 <= y < M  
            {
                if (arr[next_x][next_y] == 1 && visited[next_x][next_y] == 0)
                { //방문한적 없는 칸이고, 미로의 이동할 수 있는 칸
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
    arr.resize(N, vector<int>(M)); // 2차원 벡터 크기 조정
    visited.resize(N, vector<int>(M));
    dist.resize(N, vector<int>(M));
    for (int i = 0; i < N; i++) // N*M 지도 입력 받기
    {
        string line;
        cin >> line; // 문자열로 입력 받기
        for (int j = 0; j < M; j++)
        {
            arr[i][j] = line[j] - '0'; // 문자를 정수로 변환하여 저장
        }
    }
    BFS(0, 0);
    cout << dist[N - 1][M - 1];
    return 0;
}