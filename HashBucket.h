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

	// ע�⣺HashBucket�ĵ�������֧��--�Ĳ���
	//��Ϊ��ײ�ʹ�õ��ǵ�������������--��ǰ�ƶ�

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

template <class T,class K,class KOFV,class DF>
class HashBucket
{
	friend class HashBucketIterator<T, K, KOFV, DF>;

	typedef HashBUcket<T> Node;
	typedef HashBucket<T, K, KOFV, DF> Self;

public:
	typedef HashBucketIterator<T, K, KOFV, DF> iterator;

public:
	HashBucket(size_t initCap=10)
		:_table(GetNextPrime(initCap))
		,_size(0)
	{}

	~HashBucket()
	{
		Clear();
	}

	iterator begin()
	{
		for (size_t bucketNo = 0; bucketNo < BucketCount(); bucketNo++)
		{
			if (_table[bucketNo])
				return iterator(this, _table[bucketNo]);
		}
	}

	iterator end()
	{
		return iterator(this, nullptr);
	}

	pair<iterator, bool> Insert(const T& data)
	{
		CheckCapacity();

		size_t bucketNo = HashFunc(KOFV()(data));
		Node* cur = _table[bucketNo];

		while (cur)
		{
			if (KOFV()(cur->data) == KOFV()(data))
				return make_pair(iterator(this, cur), false);

			cur = cur->_next;
		}

		cur = cur->_next;

		cur = new Node(data);
		_table[bucketNo] = cur;
		_size++;
		return make_pair(iterator(this, cur), ture);
	}

	size_t Delete(const K& key)
	{
		size_t bucketNo = HashFunc(key);

		Node* cur = _table[bucketNo];
		Node* prev = nullptr;

		while (cur)
		{
			if (KOFV()(cur->_data) == key)
			{
				if (prev == nullptr)
				{
					_table[bucketNo] = cur->_next;
				}
				else
				{
					prev->_next = cur->_next;
				}

				delete cur;
				_size--;
				return 1;
			}

			prev = cur;
			cur = cur->_next;
		}

		return 0;
	}

	iterator Find(const K& key)
	{
		size_t bucketNo = HashFunc(key);

		Node* cur = _table[bucketNo];

		while (cur)
		{
			if (KOFV()(cur->_data) == key)
				return iterator(this, cur);

			cur = cur->_next;
		}

		return end();
	}

	size_t Size()const
	{
		return _size;
	}

	bool Empty()const
	{
		return 0 == _size;
	}

	void Clear()
	{
		for (size_t bucketNo = 0; bucketNo < _table.capacity(); bucketNo++)
		{
			Node* cur = _table[bucketNo];
			while (cur)
			{
				_table[bucketNo] = cur->_next;
				delete cur;
				cur = _table[bucketNo];
			}
		}

		_size = 0;
	}

	size_t BucketCount()const
	{
		return _table.capacity();
	}

	size_t BucketSize(size_t bucketNo)const
	{
		Node* cur = _table[bucketNo];
		size_t count = 0;
		while (cur)
		{
			count++;
			cur = cur->_next;
		}
		return count;
	}

	size_t Bucket(const K& key)const
	{
		return HashFunc(key);
	}

	void PrintHashBucket()
	{
		for (size_t bucketNo = 0; bucketNo < _table.capacity(); ++bucketNo)
		{
			cout << "table[" << bucketNo << "]:";
			Node* cur = _table[bucketNo];
			while (cur)
			{
				cout << cur->_data << "--->";
				cur = cur->_next;
			}

			cout << "NULL" << endl;
		}
		cout << endl;
	}

	void Swap(Self& ht)
	{
		_table.swap(ht._table);
		swap(_size, ht._size); 
	}

private:
	size_t HashFunc(const K& key)const
	{
		return DF()(key) % _table.capacity();
	}
	/*
	// ˼�����������ݷ�ʽ���õĵط������
	void CheckCapacity()
	{
		// ����ϣ������ЧԪ�ظ�����Ͱ�ĸ������ʱ��������
		if (_size == _table.capacity())
		{
			// �����µĹ�ϣ��
			HashBucket<T> newHt(_size*2);

			// ���ɹ�ϣ��(this)�е�Ԫ�ز��뵽�¹�ϣ����
			for (size_t i = 0; i < _table.capacity(); ++i)
			{
				Node* cur = _table[i];
				while (cur)
				{
					newHt.Insert(cur->_data);
					cur = cur->_next;
				}
			}

			// ��������ϣ����Ԫ�ؽ���--->����֮��
			// this�д洢newHt�еĽڵ㣬newHt�д洢�ľ��Ǿ�this�нڵ�
			// ���˺�����������newHtҪ�����٣�newHtͰ�еĽڵ�ͻᱻ�ͷ�-->����ԭthis�еĽڵ�������
			this->Swap(newHt);
		}
	}
	*/

	void CheckCapacity()
	{
		// ����ϣ������ЧԪ�ظ�����Ͱ�ĸ������ʱ��������
		if (_size == _table.capacity())
		{
			// �����µĹ�ϣ��
			Self newHt(GetNextPrime(_size));

			// ���ɹ�ϣ��(this)�е�Ԫ�ز��뵽�¹�ϣ����
			for (size_t i = 0; i < _table.capacity(); ++i)
			{
				Node* cur = _table[i];
				while (cur)
				{
					// ��cur�ڵ�Ӿɹ�ϣͰ��ɾ��--ͷɾ
					_table[i] = cur->_next;

					// ��cur�ڵ����µĹ�ϣͰ�в���
					// ����Ԫ�����¹�ϣ���е�Ͱ��
					size_t bucketNo = newHt.HashFunc(KOFV()(cur->_data));

					// ͷ��
					cur->_next = newHt._table[bucketNo];
					newHt._table[bucketNo] = cur;

					cur = _table[i];
				}
			}

			// ��������ϣ����Ԫ�ؽ���--->����֮��
			// �ɹ�ϣͰ�����еĽڵ��Ѿ����Ƶ��¹�ϣͰ���ˣ��ɹ�ϣͰ����Ϊ��
			// this�д洢newHt�еĽڵ㣬newHt�д洢�ľ��Ǿ�this�нڵ�
			// ���˺�����������newHtҪ�����٣�newHtͰ�еĽڵ�ͻᱻ�ͷ�-->����ԭthis�еĽڵ�������
			this->Swap(newHt);
		}
	}
private:
	vector<Node*> _table;
	size_t _size;  // ��ʾ��ϣ������ЧԪ�صĸ���
};