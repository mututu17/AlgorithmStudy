#include <iostream>
using namespace std;
char arr[6561][6561]; //�� or ������ ������ �迭
void devideAndConquer(int x, int y, int size, bool star)
{
	if (size == 1 && star)//���ȣ���Ͽ� size�� 1�̵Ǹ� star�� ���� 
		arr[x][y] = '*'; //�� �Ǵ�
	else if (size == 1 && !star)
		arr[x][y] = ' '; //���� �� �ϳ��� �����մϴ�
	else if (size != 1 && star)
	{
		for (int i = x; i < x + size; i += size / 3) //size�� 3���� �������鼭 9ĭ���� �����մϴ�.
		{
			for (int j = y; j < y + size; j += size / 3)
			{
				if (i == x + size / 3 && j == y + size / 3) //��� ĭ�� star�� ǥ������ �ʵ��� star�� 0���� ������ݴϴ�
					devideAndConquer(i, j, size / 3, 0);
				else
					devideAndConquer(i, j, size / 3, 1);
			}
		}
	}
	else //star�� 0�� ���
	{
		for (int i = x; i < x + size; i += size / 3)
			for (int j = y; j < y + size; j += size / 3) //size�� ���� �� 9ĭ�� star�� ��� 0���� ���ȣ��
				devideAndConquer(i, j, size / 3, 0);
	}
	return;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N; //������ ũ�� 3^K  1<= K <= 8 3�� ���� ��
	cin >> N;
	devideAndConquer(0, 0, N, 1);
	for (int i = 0; i < N; i++) //�Է� ���� ũ�⸸ŭ �迭�� ����� �� ������ ���
	{
		for (int j = 0; j < N; j++)
		{
			cout << arr[i][j];
		}
		cout << '\n';
	}
}