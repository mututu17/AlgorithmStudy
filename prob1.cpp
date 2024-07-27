#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 
using namespace std;

int N; // ������ ũ�� N*N
vector<vector<int>> moving = { {-1,0}, {1,0}, {0,1}, {0,-1} };
vector<vector<int>> arr; // 2���� ���� ����
vector<int> home_count;

int DFS(int x, int y)
{
    int count = 0;
    if (arr[x][y] == 1)
    {
        count = 1;
        arr[x][y] = 2; // visited ǥ��
        int next_x;
        int next_y;
        for (int k = 0; k < 4; k++)
        {
            next_x = x + moving[k][0];
            next_y = y + moving[k][1];
            if (next_x < N && next_x >= 0 && next_y < N && next_y >= 0) // ������ ������� Ȯ��
                count += DFS(next_x, next_y);
        }
    }
    return count;
}

int main()
{
    cin >> N;
    arr.resize(N, vector<int>(N)); // 2���� ���� ũ�� ����

    for (int i = 0; i < N; i++) // N*N ���� �Է� �ޱ�
    {
        string line;
        cin >> line; // ���ڿ��� �Է� �ޱ�
        for (int j = 0; j < N; j++)
        {
            arr[i][j] = line[j] - '0'; // ���ڸ� ������ ��ȯ�Ͽ� ����
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (arr[i][j] == 1)
            {
                int count = DFS(i, j);
                home_count.push_back(count);
            }
        }
    }

    cout << home_count.size() << endl;
    sort(home_count.begin(), home_count.end()); //������������ ����
    for (auto i : home_count)
        cout << i << endl;

    return 0;
}