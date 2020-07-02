#pragma once

#include <iostream>
using namespace std;

enum Color{RED,BLACK};

template<class T>
struct RBTreeNode
{
	RBTreeNode(const T& data=T(),Color color=RED)
		:_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
		,_data(data)
		,_color(color)
	{}

	RBTreeNode<T>* _left;
	RBTreeNode<T>* _right;
	RBTreeNode<T>* _parent;
	T _data;
	Color _color;
};

template <class T>
class RBTree
{
	typedef RBTreeNode<T> Node;
public:
	RBTree()
	{
		head = new Node;
		head->_left = head;
		head->_right = head;
		head->_parent = nullptr;
	}

	bool Insert(const T& data)
	{
		Node root = GetRoot(); 

		if (NULL == root)  
		{
			root = new Node(data, BLACK);
			root->_parent = head;

			head->_left = root;
			head->_right = root;
			return true;
		}

		Node* cur = root;
		Node* parent = nullptr;
		while (cur)
		{
			parent = cur;
			if (data < cur->_data)
				cur = cur->_left;
			else if (data > cur->_data)
				cur = cur->_right;
			else
				return false;
		}

		cur = new Node(data);
		if (data < parent->_data)
			parent->_left = cur;
		else
			parent->_right = cur;

		cur->_parent = parent;


	}

	void InOrder()
	{
		_InOrder(GetRoot());
		cout << endl;
	}

	Node* LeftMost()
	{
		Node* root = GetRoot();
		if (nullptr == root)
			return head;

		Node* cur = root;
		while (cur->_left)
			cur = cur->_left;

		return cur;	 
	}

	Node* RightMost()
	{
		Node* root = GetRoot();
		if (nullptr == root)
			return head;

		Node* cur = root;
		while (cur->_right)
			cur = cur->_right;

		return cur;
	}

	bool IsValidRBTree()
	{
		Node* root = GetRoot();
		if (nullptr == root)
			return true;

		if(root->_color==RED)
		{
			cout << "违反性质二：根节点必须是黑色--->根节点不是黑色的" << endl;
			return false;
		}

		size_t blackCount = 0;
		Node* cur = root;
		while (cur)
		{
			if (BLACK == cur->_color)
				blackCount++;

			cur = cur->_left;
		}

		size_t pathCount = 0;
		return _IsValidRBTree(root, blackCount, pathCount);
	}

private:
	Node*& GetRoot()
	{
		return head->_parent;
	}

	bool _IsValidRBTree(Node* root, const size_t blackCount, size_t pathCount)
	{
		if (root == nullptr)
			return true;

		if (BLACK == root->_color)
			pathCount++;

		Node* parent = root->_parent;
		if (parent != head)
		{
			if (RED == root->_color && parent->_color = RED)
			{
				cout << "违反了性质3：没有连在一起的红色节点--->现在有" << endl;
				return false;
			}
		}

		if (nullptr == root->_left && nullptr == root->_right)
		{
			if (pathCount != blackCount)
			{
				cout << "违反了性质4：每天路径中黑色节点个数相等--->现在不相等" << endl;
				return false;
			}
		}

		return _IsValidRBTree(root->_left, blackCount, pathCount) &&
			_IsValidRBTree(root->_right, blackCount, pathCount);
	}

	void _InOrder(Node* root)
	{
		if (root)
		{
			_InOrder(root->_left);
			cout << root->_data << " ";
			_InOrder(root->_right);
		}
	}
private:
	Node* head;
};