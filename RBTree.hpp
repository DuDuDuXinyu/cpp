#pragma once

enum Color{RED, BLACK};

//������ڵ�Ķ���
template <class T>
struct RBTreeNode
{
	RBTreeNode(const T& x, Color c = RED)
		:left(nullptr)
		, right(nullptr)
		, parent(nullptr)
		, data(x)
		, color(c)
	{}

	RBTreeNode<T>* left;
	RBTreeNode<T>* right;
	RBTreeNode<T>* parent;
	T data;
	Color color;
};

template <class T>
class RBTree
{
	typedef RBTreeNode<T> Node;
public:
	RBTree()
	{
		head = new Node();
		head->left = head;
		head->right = head;
		head->parent = nullptr;
	}

	bool Insert(const T& data)
	{
		//���ն����������Ĺ�������½ڵ�
		Node*& root = GetRoot();

		//����
		if (nullptr == root)
		{
			root = new Node(data, BLACK);
			root->parent = head;
			head->left = root;
			head->right = root;
			return true;
		}

		//�ҵ�������ڵ��ں�����е�λ��
		Node* cur = root;
		Node* parent = head;
		while (cur)
		{
			parent = cur;
			if (data < cur->data)
				cur = cur->left;
			else if (data > cur->data)
				cur = cur->right;
			else
				return false;
		}

		//�����½ڵ�
		cur = new Node(data);
		if (data < parent->data)
			parent->left = cur;
		else
			parent->right = cur;

		cur->parent = parent;

		//����²���ڵ�����˫�׽ڵ����ɫ�Ƿ�Ϊ��ɫ
		if (RED == parent->color)
		{

		}

		//�½ڵ����󣬺�ɫ���е���������С�ڵ㷢�ͱ仯
		root->color = BLACK;
		head->left = LeftMost();
		head->right = RightMost();

		return true;
	}

private:
	Node* GetRoot()
	{
		return head->parent;
	}

	Node* LeftMost()
	{
		Node* root = GetRoot();
		if (nullptr == root)
			return head;

		Node* cur = root;
		while (cur->left)
			cur = cur->left;

		return cur;
	}

	Node* RightMost()
	{
		Node* root = GetRoot();
		if (nullptr == root)
			return head;

		Node* cur = root;
		while (cur->right)
			cur = cur->right;

		return cur;
	}
private:
	Node* head;	//ָ�������е�ͷ���
};