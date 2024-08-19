#include <iostream>
#include <cmath>
using namespace std;
int locate[21]; //������ ��ġ ���
int whereToGo(int destination, int locate)
{
	for (int i = 1; i <= 3; i++)
	{
		if (destination != i && locate != i)
			return i;
	}
}
void HanoiTower(int N, int destination)
{
	if (N == 1)
	{
		cout << locate[N] << " " << destination << '\n';
		locate[N] = destination;
		return;
	}
	HanoiTower(N - 1, whereToGo(destination, locate[N - 1]));
	cout << locate[N] << " " << destination << '\n';
	locate[N] = destination;
	HanoiTower(N - 1, destination);
	return;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N; //������ ����
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		locate[i] = 1; //������ �ʱ���ġ
	}
	cout << (int)pow(2, N) - 1 << '\n';
	HanoiTower(N, 3); //N���� ������ 3�� ������� �ű�°� ��ǥ
	return 0;
}