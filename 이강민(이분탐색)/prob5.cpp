#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int main()
{
	map<int, int> map;//������ �ִ� ī�� ����
	int N; //������ �ִ� ī���� ��
	int M; //������ �ִ� �� Ȯ���ؾ� �ϴ� ī���� �� 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	int card;
	for (int i = 0; i < N; i++)
	{
		cin >> card;
		map[card]++;
	}
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> card; //������ �ִ� �� Ȯ���ؾ� �ϴ� ī��
		cout << map[card] << " ";
	}
}