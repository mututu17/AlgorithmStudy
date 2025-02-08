#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int main()
{
	map<int, int> map;//가지고 있는 카드 저장
	int N; //가지고 있는 카드의 수
	int M; //가지고 있는 지 확인해야 하는 카드의 수 
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
		cin >> card; //가지고 있는 지 확인해야 하는 카드
		cout << map[card] << " ";
	}
}