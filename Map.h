#pragma once

#include "RBTree.h"

#include <iostream>
using namespace std;

namespace mine
{
	template<class K,class V>
	class map
	{
		typedef pair<K, V> ValueType;

		struct KeyOfValue
		{
			const K& operator()(const ValueType& value)
			{
				return value.first;
			}
		};

	public:
		typedef RBTree<ValueType, KeyOfValue> RBTree;

		typename typedef RBTree::iterator iterator;

	public:
		map()
			:t()
		{}

		iterator begin()
		{
			return t.begin();
		}

		iterator end()
		{
			return t.end();
		}

		bool empty()const
		{
			return t.Empty();
		}

		size_t size()const
		{
			return t.Size();
		}

		V& operator[](const K& key)
		{
			return (*(insert(make_pair(key, V())).first)).second;
		}

		pair<iterator, bool> insert(const ValueType& value)
		{
			return t.Insert(value);
		}

		void clear()
		{
			t.Clear();
		}

		iterator find(const K& key)
		{
			return t.Find(make_pair(key, V));
		}
	private:
		RBTree t;
	};
}


#include <string>

void TestMap()
{
	mine::map<string, string> m;
	m.insert(pair<string, string>("orange", "橙子"));
	m.insert(make_pair("apple", "苹果"));
	cout << m["apple"] << endl;
	cout << m["banana"] << endl;    //banana对应的key不存在，map先将<"banana", "">键值对向红黑树中插入，然后返回""

	m["banana"] = "香蕉";

	if (m.find("peach") == m.end())
	{
		m["peach"] = "桃子";
	}

	cout << m.size() << endl;

	auto it = m.begin();
	while (it != m.end())
	{
		cout << (*it).first << "--->" << it->second << endl;
		++it;
	}
	cout << endl;

	cout << "=============================" << endl;

	// 范围for
	for (auto& e : m)
		cout << e.first << "--->" << e.second << endl;
	cout << endl;

	m.clear();
	cout << m.size() << endl;
}