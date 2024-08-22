#include <iostream>
using namespace std;
int arr[64][64];
bool isSameAll(int x, int y, int size) //�������� ũ�⸦ �޾ƿ�
{
	int color = arr[x][y]; //�������� 0���� 1���� �����ؼ�
	for (int i = x; i < x + size; i++)
	{
		for (int j = y; j < y + size; j++)
		{
			if (arr[i][j] != color) //�ٸ� ���� �����ִٸ�
				return 0; //����!
		}
	}
	return 1; //��� ���� ���̹Ƿ� ��!
}
void devideAndConquer(int x, int y, int size) //�������� ũ�⸦ �޾ƿ�
{

	if (isSameAll(x, y, size))
	{
		cout << arr[x][y]; //�� ���� ������ �� ���
	}
	else //��ü�� �� ���� ��Ÿ�� �� ���� ��쿡
	{
		cout << "("; // ��ȣ�� ��� ���
		for (int i = 0; i < size; i += size / 2) //���� ��, ������ ��
		{
			for (int j = 0; j < size; j += size / 2)//���� �Ʒ�. ������ �Ʒ� ������ ���!
			{
				devideAndConquer(x + i, y + j, size / 2); // (0,0,4),(0,4,4),(4,0,4),(4,4,4) �̷��� ���ȣ��
			}
		}
		cout << ")"; //��ȣ �ݾ��ֱ�
	}
	return;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N; //������ ũ�� 1 <= N <= 64 2�� ���� ��
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string temp;
		cin >> temp; //�����Ͱ� ���� ���� ���ͼ� string���� �޾ƿ�
		for (int j = 0; j < N; j++)
		{
			arr[i][j] = temp[j] - '0'; //string���� �ϳ��� ����
		}
	}
	devideAndConquer(0, 0, N); //������������ ������ �����ϱ�
}