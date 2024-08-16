#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int list[10001]; //������ �ִ� ī�� ����
	int N; //������ �ִ� ī���� ��
	int M; //������ �ִ� �� Ȯ���ؾ� �ϴ� ī���� �� 
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> list[i];
	}
	sort(list, list + N); //������������ ����
	cin >> M;
	int card;
	int mid;
	for (int i = 0; i < M; i++)
	{
		int left = 0;
		int right = N - 1;
		cin >> card; //������ �ִ� �� Ȯ���ؾ� �ϴ� ī��
		int found = 0;
		while (left <= right)
		{
			mid = (right + left) / 2;
			if (list[mid] < card) //ã�� �ִ� ���� Ŀ�� mid �����ʿ��� ã�ƾ���
			{
				left = mid + 1;
			}
			else if (list[mid] == card) //ã�Ҵ�.
			{
				found++;
				int T = mid + 1;
				while (list[T] == card) //���������� �� �ִ��� ã��
				{
					found++;
					T++;
				}
				T = mid - 1;
				while (list[T] == card)//�������� �� �ִ��� ã��
				{
					found++;
					T--;
				}
				break;
			}
			else //ã�� �ִ� ���� �۾Ƽ� mid ���ʿ��� ã�ƾ���
			{
				right = mid - 1;
			}
		}
		cout << found << " ";
	}
}