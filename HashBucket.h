#pragma once

#include <iostream>
using namespace std;

#include <vector>
#include <string>

template <class T>
struct HashNode
{
	HashNode<T>* _next;
	T _data;

	HashNode(const T& data = T())
		:_next(nullptr)
		,_data(data)
	{}
};

struct StrInt
{
	size_t operator()(const string& s)
	{
		const char* str = s.c_str();
		unsigned int seed = 131;
		unsigned int hash = 0;

		while (*str)
			hash = hash * seed + (*str++);

		return (hash & 0x7FFFFFFF);
	}
};

template <class T>
struct DefInt
{
	size_t operator()(const T& data)
	{
		return data;
	}
};

template <class T,class K,class KOFV,class DF=DefInt<T>>
class HashBucket;

template <class T, class K, class KOFV, class HF = DefInt<T>>
class HashBucketIterator
{
	typedef HashNode<T> Node;
	typedef HashBucketIterator<T, K, KOFV, HF> Self;
public:
	HashBucketIterator(HashBucket<T,K,KOFV,HF>* ht,Node* node)
		:_node(node)
		,_ht(ht)
	{}

	T& operator*()
	{
		return _node->_data;
	}

	T& operator->()
	{
		return &(operator());
	}

	Self& operator++()
	{
		Next();
		return *this;
	}

	Self& operator++(this)
	{
		Self temp(*this);
		Next();
		return temp;
	}

	// 注意：HashBucket的迭代器不支持--的操作
	//因为其底层使用的是单链表，单链表不能--往前移动

	bool operator==(const Self& s)
	{
		return _ht == s._ht && _node == s._node;
	}

	bool operator!=(const Self& s)
	{
		return !(*this == s);
	}

private:
	void Next()
	{
		if (_node->_next)
			_node = _node->_next;
		else
		{
			size_t bucketNo = _ht->HashFunc(KOFV()(_node->_data)) + 1;

			for (; bucketNo < _ht->BucketCount(); bucketNo++)
			{
				if (_ht->_table[bucketNo])
				{
					_node = _ht->_table[bucketNo];
					return;
				}
			}

			_node = nullptr;
		}
	}

private:
	Node* _node;
	HashBucket<T, K, KOFV, HF>* _ht;
};
