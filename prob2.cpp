#include <iostream>
#include <vector>
using namespace std;

int m, n; // ������ ũ�� M*N
vector<vector<int>> moving = { {-1,0}, {1,0}, {0,1}, {0,-1} }; //�� �� �� ��
vector<vector<int>> arr; // 2���� ���� ����
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
bool canRipedAll()
{

}
void oneDayPass()
{
    vector<pair<int, int>> queue; //�� �� ���ο� queue�� ����� ������ ��� �ʿ� ����

    for (int i = 0; i < n; i++) //��� �丶�並 �˻��Ͽ� 
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 1) //���� �丶�䰡 �ִٸ� 
            {
                pair<int, int> coord; //���� �丶���� ��ǥ
                coord.first = i;
                coord.second = j;
                queue.push_back(coord); //���� �丶���� ��ǥ�� queue�� ������
            }
        }
    }
    for (int i = 0; i < queue.size(); i++)
    {
        int x = queue[i].first;
        int y = queue[i].second; //���� �丶���� ��ǥ�� �޾Ƽ�
        for (int j = 0; j < 4; j++)
        {
            int next_x = x + moving[j][0];
            int next_y = y + moving[j][1]; //���� �丶��(1)�� �� �� �� �� �丶�䰡
            if (next_x < n && next_x >= 0 && next_y < m && next_y >= 0) //��踦 �� ����� 
            {
                if (arr[next_x][next_y] == 0)  //������ �丶��(0)���
                    arr[next_x][next_y] = 1; //������ 
            }
        }
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
    int day = 0; //��� �丶�䰡 �ʹµ� �ɸ��� �ּ� �ϼ�
    if (canRipedAll())
    {
        cout << -1;
        return 0;
    }
    else
    {
        while (!isRipedAll()) //�丶�䰡 �� ���� ������ �ݺ�
        {
            oneDayPass();
            day++;
        }
        cout << day; //while ���� ���������� day���
        return 0;
    }
}