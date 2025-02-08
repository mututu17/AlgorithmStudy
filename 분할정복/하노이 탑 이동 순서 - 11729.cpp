#include <iostream>
#include <cmath>
using namespace std;
int locate[21]; //원판의 위치 기록
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
	int N; //원판의 개수
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		locate[i] = 1; //원판의 초기위치
	}
	cout << (int)pow(2, N) - 1 << '\n';
	HanoiTower(N, 3); //N개의 원판을 3번 기둥으로 옮기는게 목표
	return 0;
}