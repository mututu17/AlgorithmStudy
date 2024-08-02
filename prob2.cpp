#include <iostream>
#include <vector>
using namespace std;

int m, n; // 지도의 크기 M*N
vector<vector<int>> moving = { {-1,0}, {1,0}, {0,1}, {0,-1} }; //상 하 좌 우
vector<vector<int>> arr; // 2차원 벡터 선언
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
bool canRipedAll()
{

}
void oneDayPass()
{
    vector<pair<int, int>> queue; //매 번 새로운 queue를 만들기 때문에 비울 필요 없음

    for (int i = 0; i < n; i++) //모든 토마토를 검사하여 
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 1) //익은 토마토가 있다면 
            {
                pair<int, int> coord; //익은 토마토의 좌표
                coord.first = i;
                coord.second = j;
                queue.push_back(coord); //익은 토마토의 좌표를 queue에 저장함
            }
        }
    }
    for (int i = 0; i < queue.size(); i++)
    {
        int x = queue[i].first;
        int y = queue[i].second; //익은 토마토의 좌표를 받아서
        for (int j = 0; j < 4; j++)
        {
            int next_x = x + moving[j][0];
            int next_y = y + moving[j][1]; //익은 토마토(1)의 상 하 좌 우 토마토가
            if (next_x < n && next_x >= 0 && next_y < m && next_y >= 0) //경계를 안 벗어났고 
            {
                if (arr[next_x][next_y] == 0)  //안익은 토마토(0)라면
                    arr[next_x][next_y] = 1; //익히기 
            }
        }
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
    int day = 0; //모든 토마토가 익는데 걸리는 최소 일수
    if (canRipedAll())
    {
        cout << -1;
        return 0;
    }
    else
    {
        while (!isRipedAll()) //토마토가 다 익을 때까지 반복
        {
            oneDayPass();
            day++;
        }
        cout << day; //while 문을 빠져나오면 day출력
        return 0;
    }
}