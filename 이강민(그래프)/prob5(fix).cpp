#include <iostream>
#include <utility>
using namespace std;
pair<char, char> tree[26]; //���� �ڽİ� ������ �ڽ��� ������ �� �ִ� ���Ĺ� Ʈ�� ����
void preorder(char root) //���� ��ȸ root-left-right
{
	if (root == '.')
		return;
	cout << root;
	preorder(tree[root - 'A'].first);
	preorder(tree[root - 'A'].second);
}
void inorder(char root) //���� ��ȸ  left-root-right
{
	if (root == '.')
		return;
	inorder(tree[root - 'A'].first);
	cout << root;
	inorder(tree[root - 'A'].second);
}
void postorder(char root) //���� ��ȸ left-right-root
{
	if (root == '.')
		return;
	postorder(tree[root - 'A'].first);
	postorder(tree[root - 'A'].second);
	cout << root;
}
int main()
{
	int N; //Ʈ���� ��� ����
	cin >> N;
	for (int i = 0; i < N; i++) //Ʈ�� ���� �Է� �ޱ�
	{
		char root, left, right; //�Է� 1,2,3
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