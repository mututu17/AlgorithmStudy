#include <iostream>
#include <vector>
using namespace std;
int m, n; // ������ ũ�� M*N
int day = 0; //��� �丶�䰡 �ʹµ� �ɸ��� �ּ� �ϼ�
vector<vector<int>> moving = { {-1,0}, {1,0}, {0,1}, {0,-1} }; //�� �� �� ��
vector<vector<int>> arr; // �丶�� �����͸� ���� 2���� ���� ����
vector<pair<int, int>> queue;
bool isRipedAll()
{
    for (int i = 0; i < n; i++) //��� �丶�並 �˻��Ͽ�
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 0) //������ �丶�䰡 �ִٸ� false
                return false;
        }
    }
    return true; //������ �丶�䰡 ������ true 
}
int oneDayPass()
{
    int q_size = queue.size();
    for (int i = 0; i < q_size; i++)
    {
        int x = queue[i].first;
        int y = queue[i].second; //���� �丶���� ��ǥ�� �޾Ƽ�
        for (int j = 0; j < 4; j++)
        {
            int next_x = x + moving[j][0];
            int next_y = y + moving[j][1]; //���� �丶��(1)�� �� �� �� �� �丶�䰡
            if (next_x < n && next_x >= 0 && next_y < m && next_y >= 0 && arr[next_x][next_y] == 0)
            { //��踦 �� ����� ������ �丶��(0)��� 
                arr[next_x][next_y] = 1; //������ 
                pair<int, int> coord(next_x, next_y);
                queue.push_back(coord); //���� ���� �丶�� ť�� �߰��ϱ�
            }
        }
    }
    queue.erase(queue.begin(), queue.begin() + q_size);
    //�� �� �� �� �丶�並 ���� �丶��� �� �̻� �丶�並 ���� �� �����Ƿ� ������
    return queue.size();
}
void BFS()
{
    for (int i = 0; i < n; i++) //��� �丶�並 �˻��Ͽ� 
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 1) //���� �丶�䰡 �ִٸ� 
            {
                pair<int, int> coord; //���� �丶���� ��ǥ
                coord.first = i;
                coord.second = j;
                queue.push_back(coord); //���� �丶���� ��ǥ�� queue�� �����Ѵ�
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
    for (int i = 0; i < n; i++) // M*N ���� �Է� �ޱ�
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

    if (isRipedAll()) //��� �丶�䰡 ����
    {
        cout << day; //while ���� ���������� day���
    }
    else
    {
        cout << "-1"; //���� �� ���� �丶�䰡 ������
    }
    return 0;
}