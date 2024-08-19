#include <iostream>
#include <vector>
#include <map>
using namespace std;
vector<vector<int>> V;
map<int, int> paper;
void divideAndConquer(int x, int y, int size) //�������� ��ǥ, ������ ũ��
{
	int num = V[x][y]; //�������� ���ڸ� �޾ƿͼ�
	bool isSameNum = 1;
	for (int i = x; i < x + size; i++)
	{
		for (int j = y; j < y + size; j++)
		{
			if (V[i][j] != num) //������ ���ڿ� �ٸ� ���ڰ� ������ ����
				isSameNum = 0;
		}
	}
	if (isSameNum) //���̰� ��� ���� ���� �Ǿ��ִٸ� ����Ѵ�.
	{
		paper[num]++;
		return;
	}
	else //�׷��� �ʴٸ� 9���� �����Ͽ� �ݺ��Ѵ�.
	{
		for (int i = x; i < x + size; i += size / 3) //x��ǥ�� �������� size/3 ��ŭ ���� ���Ѽ� ������
		{ 
			for (int j = y; j < y + size; j += size / 3) //y��ǥ�� �������� size/3 ��ŭ ���� ���Ѽ� ������ 
			{
				divideAndConquer(i, j, size / 3); //ex) 003, 033, 063/ 303, 333, 363/ 603, 633, 663
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N; //N*N ��� 
	cin >> N; //�׻� 3^k �Է�
	V.resize(N, vector<int>(N));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> V[i][j];
		}
	}
	divideAndConquer(0, 0, N);
	cout << paper[-1] << '\n';
	cout << paper[0] << '\n';
	cout << paper[1];
}