#include <iostream>
#include <vector>
using namespace std;

struct Node
{
	char value;
	Node* left;
	Node* right;
};
int N;

void preorder(const vector<Node>& tree, int node)
{
	cout << tree[node].value;
	if (tree[node].left != NULL)
	{
		preorder(tree, tree[node].left->value - 65);
	}
	if (tree[node].right != NULL)
	{
		preorder(tree, tree[node].right->value - 65);
	}
}

void inorder(const vector<Node>& tree, int node)
{
	if (tree[node].left != NULL)
	{
		inorder(tree, tree[node].left->value - 65);
	}
	cout << tree[node].value;
	if (tree[node].right != NULL)
	{
		inorder(tree, tree[node].right->value - 65);
	}
}

void postorder(const vector<Node>& tree, int node)
{
	if (tree[node].left != NULL)
	{
		postorder(tree, tree[node].left->value - 65);
	}
	if (tree[node].right != NULL)
	{
		postorder(tree, tree[node].right->value - 65);
	}
	cout << tree[node].value;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	vector<Node> tree(N);
	for (int i = 0; i < N; i++)
	{
		char temp, temp1;
		cin >> temp;
		tree[temp - 65].value = temp;

		cin >> temp1; // L
		if (temp1 != '.')
		{
			tree[temp - 65].left = &tree[temp1 - 65];
		}

		cin >> temp1; // R
		if (temp1 != '.')
		{
			tree[temp - 65].right = &tree[temp1 - 65];
		}
	}

	preorder(tree, 0);
	cout << '\n';
	inorder(tree, 0);
	cout << '\n';
	postorder(tree, 0);

	return 0;
}