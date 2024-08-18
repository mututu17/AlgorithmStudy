#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int House[10001]; //집의 좌표 저장
	int N; //공유기를 설치할 수 있는 집의 개수
	int C; //설치해야 하는 공유기의 수 
	int result = 0; //가장 인접한 공유기 사이의 최대 거리
	cin >> N >> C;
	for (int i = 0; i < N; i++)
	{
		cin >> House[i];
	}
	sort(House, House + N); //오름차순으로 정렬
	int left = 1; //최소 거리 
	int right = House[N - 1] - House[0]; // 최대 거리(마지막 집 - 첫 번째 집)
	int mid;
	while (left <= right)
	{
		mid = (right + left) / 2;
		int count = 1; //첫 번째 집에 공유기 설치
		int lastRoute = House[0]; //마지막에 설치한 공유기의 위치
		for (int i = 0; i < N; i++)
		{
			if (House[i] - lastRoute >= mid) //설정한 최대 거리 이상인 곳에 공유기를 설치하기
			{
				lastRoute = House[i];
				count++;
			}
		}
		if (count >= C) //최적의 값을 찾기위해 더 탐색
		{
			left = mid + 1;
			result = max(result, mid);
		}
		else //조건을 만족하는 답을 찾기 위해 더 탐색
		{
			right = mid - 1;
		}
	}
	cout << result;
}