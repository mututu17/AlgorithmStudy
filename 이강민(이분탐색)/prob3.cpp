#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int House[10001]; //���� ��ǥ ����
	int N; //�����⸦ ��ġ�� �� �ִ� ���� ����
	int C; //��ġ�ؾ� �ϴ� �������� �� 
	int result = 0; //���� ������ ������ ������ �ִ� �Ÿ�
	cin >> N >> C;
	for (int i = 0; i < N; i++)
	{
		cin >> House[i];
	}
	sort(House, House + N); //������������ ����
	int left = 1; //�ּ� �Ÿ� 
	int right = House[N - 1] - House[0]; // �ִ� �Ÿ�(������ �� - ù ��° ��)
	int mid;
	while (left <= right)
	{
		mid = (right + left) / 2;
		int count = 1; //ù ��° ���� ������ ��ġ
		int lastRoute = House[0]; //�������� ��ġ�� �������� ��ġ
		for (int i = 0; i < N; i++)
		{
			if (House[i] - lastRoute >= mid) //������ �ִ� �Ÿ� �̻��� ���� �����⸦ ��ġ�ϱ�
			{
				lastRoute = House[i];
				count++;
			}
		}
		if (count >= C) //������ ���� ã������ �� Ž��
		{
			left = mid + 1;
			result = max(result, mid);
		}
		else //������ �����ϴ� ���� ã�� ���� �� Ž��
		{
			right = mid - 1;
		}
	}
	cout << result;
}