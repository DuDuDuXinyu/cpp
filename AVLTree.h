#pragma once

#include <iostream>
using namespace std;

template<class T>
struct AVLTreeNode
{
	AVLTreeNode<T>* _left;
	AVLTreeNode<T>* _right;
	AVLTreeNode<T>* _parent;
	T _data;
	int _bf;	//Æ½ºâÒò×Ó

	AVLTreeNode(const T& data=T())
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _data(data)
		, _bf(0) 
	{}
};

template<class T>
class AVLTree
{
	typedef AVLTreeNode<T> Node;
public:
	AVLTree()
		:_root(nullptr)
	{}
	bool Insert(const T& data)
	{
		if (nullptr == _root)
		{
			_root = new Node(data);
			return true;
		}

		Node* cur = _root;
		Node* pParent = nullptr;
		while (cur)
		{
			pParent = cur;
			if (cur->_data > data)
				cur = cur->_left;
			else if (cur->_data < data)
				cur = cur->_right;
			else
				return false;
		}

		cur = new Node(data);
		if (data < pParent->_data)
			pParent->_left = cur;
		else
			pParent->_right = cur;

		cur->_parent = pParent;

		while (pParent)
		{
			if (cur == pParent->_left)
				pParent->_bf--;
			else
				pParent->_bf++;

			if (0 == pParent->_bf)
				return true;
			else if (1 == pParent->_bf || -1 == pParent->_bf)
			{
				cur = pParent;
				pParent = cur->_parent;
			}
			else
			{
				if (2 == pParent->_bf)
				{
					if (1 == cur->_bf)
						RotateLeft(pParent);
					else
						RotateRL(pParent);
				}
				else
				{
					if (-1 == cur->_bf)
						RotateRight(pParent);
					else
						RotateLR(pParent);
				}
				break;
			}
		}
		return true;
	}
	
	void InOrder()
	{
		_InOrder(_root);
	}

private:
	void _InOrder(Node* root)
	{
		if (root)
		{
			_InOrder(root->_left);
			cout << root->_data << " ";
			_InOrder(root->_right);
		}
	}

	void RotateLeft(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		parent->_right = subRL;

		if (subRL)
			subRL->_parent = parent;

		subR->_left = parent;
		Node* PParent = parent->_parent;

		parent->_parent = subR;
		subR->_parent = PParent;

		if (nullptr == PParent)
		{
			_root = subR;
			subR->_parent = nullptr;
		}
		else
		{
			if (PParent->_left == parent)
				PParent->_left = subR;
			else
				PParent->_left = subR;
		}
		parent->_bf = subR->_bf = 0;
	}

	void RotateRight(Node* pParent)
	{
		Node* pSubL = pParent->_left;
		Node* pSubLR = pSubL->_left;

		pParent->_left = pSubLR;

		if (pSubLR)
			pSubLR->_parent = pParent;

		pSubL->_right = pParent;

		Node* pPParent = pParent->_parent;
		pParent->_parent = pSubL;
		pSubL->_parent = pPParent;

		if (nullptr == pPParent)
		{
			_root = pSubL;
			pSubL->_parent = nullptr;
		}
		else
		{
			if (pPParent->_left == pParent)
				pPParent->_left = pSubL;
			else
				pPParent->_right = pSubL;
		}
		pParent->_bf = pSubL->_bf = 0;
	}

	void RotateRL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		int bf = subRL->_bf;
		RotateRight(parent->_right);
		RotateLeft(parent);

		if (1 == bf)
			parent->_bf = -1;
		else if (-1 == bf)
			subR->_bf = 1;
	}

	void RotateLR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		int bf = subLR->_bf;
		RotateLeft(parent->_left);
		RotateRight(parent);

		if (1 == bf)
			subL->_bf = -1;
		else if (-1 == bf)
			parent->_bf = 1;
	}

private:
	Node* _root;
};

void TestAVLTree()
{
	int array[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };

	AVLTree<int> t;
	for (auto e : array)
		t.Insert(e);

	t.InOrder();
}