#include <iostream>
#include <utility>
using namespace std;
pair<char, char> tree[26]; //왼쪽 자식과 오른쪽 자식을 저장할 수 있는 알파뱃 트리 생성
void preorder(char root) //전위 순회 root-left-right
{
	if (root == '.')
		return;
	cout << root;
	preorder(tree[root - 'A'].first);
	preorder(tree[root - 'A'].second);
}
void inorder(char root) //중위 순회  left-root-right
{
	if (tree[root - 'A'].first != '.')
		inorder(tree[root - 'A'].first);
	cout << root;
	if (tree[root - 'A'].second != '.')
		inorder(tree[root - 'A'].second);
	return;
}
void postorder(char root) //후위 순회 left-right-root
{
	if (tree[root - 'A'].first != '.')
		postorder(tree[root - 'A'].first);
	if (tree[root - 'A'].second != '.')
		postorder(tree[root - 'A'].second);
	cout << root;
	return;
}
int main()
{
	int N; //트리의 노드 개수
	cin >> N;
	for (int i = 0; i < N; i++) //트리 정보 입력 받기
	{
		char root, left, right; //입력 1,2,3
		cin >> root >> left >> right;
		tree[root - 'A'].first = left;
		tree[root - 'A'].second = right;
	}
	preorder('A');
	cout << '\n';
	inorder('A');
	cout << '\n';
	postorder('A');
	return 0;
}