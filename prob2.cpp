#include <iostream>
#include <vector>
using namespace std;
int m, n; // 지도의 크기 M*N
int day = 0; //모든 토마토가 익는데 걸리는 최소 일수
vector<vector<int>> moving = { {-1,0}, {1,0}, {0,1}, {0,-1} }; //상 하 좌 우
vector<vector<int>> arr; // 토마토 데이터를 받을 2차원 벡터 선언
vector<pair<int, int>> queue;
bool isRipedAll()
{
    for (int i = 0; i < n; i++) //모든 토마토를 검사하여
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 0) //안익은 토마토가 있다면 false
                return false;
        }
    }
    return true; //안익은 토마토가 없으니 true 
}
int oneDayPass()
{
    int q_size = queue.size();
    for (int i = 0; i < q_size; i++)
    {
        int x = queue[i].first;
        int y = queue[i].second; //익은 토마토의 좌표를 받아서
        for (int j = 0; j < 4; j++)
        {
            int next_x = x + moving[j][0];
            int next_y = y + moving[j][1]; //익은 토마토(1)의 상 하 좌 우 토마토가
            if (next_x < n && next_x >= 0 && next_y < m && next_y >= 0 && arr[next_x][next_y] == 0)
            { //경계를 안 벗어났고 안익은 토마토(0)라면 
                arr[next_x][next_y] = 1; //익히기 
                pair<int, int> coord(next_x, next_y);
                queue.push_back(coord); //새로 익은 토마토 큐에 추가하기
            }
        }
    }
    queue.erase(queue.begin(), queue.begin() + q_size);
    //상 하 좌 우 토마토를 익힌 토마토는 더 이상 토마토를 익힐 수 없으므로 제거함
    return queue.size();
}
void BFS()
{
    for (int i = 0; i < n; i++) //모든 토마토를 검사하여 
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 1) //익은 토마토가 있다면 
            {
                pair<int, int> coord; //익은 토마토의 좌표
                coord.first = i;
                coord.second = j;
                queue.push_back(coord); //익은 토마토의 좌표를 queue에 저장한다
            }
        }
    }
    while (oneDayPass())
    {
        day++;
    }
    return;
}
int main()
{
    cin >> m >> n;
    for (int i = 0; i < n; i++) // M*N 지도 입력 받기
    {
        vector<int> M;
        int data;
        for (int j = 0; j < m; j++)
        {
            cin >> data;
            M.push_back(data);
        }
        arr.push_back(M);
    }

    BFS();

    if (isRipedAll()) //모든 토마토가 익음
    {
        cout << day; //while 문을 빠져나오면 day출력
    }
    else
    {
        cout << "-1"; //익힐 수 없는 토마토가 존재함
    }
    return 0;
}