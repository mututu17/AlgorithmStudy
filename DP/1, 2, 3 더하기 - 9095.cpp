#include <iostream>
#include <algorithm>
using namespace std; 
int xPlusAdd(int x,int add, int n)
{
	if (x + add > n)
		return 0;
	else if (x + add == n)
		return 1;
	else
	{
		return xPlusAdd(x + add, 1, n) + xPlusAdd(x + add, 2, n) + xPlusAdd(x + add, 3, n);
	}
}
int main()
{
	int T; //테스트 케이스의 수
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int n;
		cin >> n;
		int count = xPlusAdd(0,1,n) + xPlusAdd(0, 2, n) + xPlusAdd(0, 3, n);
		cout << count << '\n';
	}
}