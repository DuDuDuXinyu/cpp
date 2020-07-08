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
	m.insert(pair<string, string>("orange", "����"));
	m.insert(make_pair("apple", "ƻ��"));
	cout << m["apple"] << endl;
	cout << m["banana"] << endl;    //banana��Ӧ��key�����ڣ�map�Ƚ�<"banana", "">��ֵ���������в��룬Ȼ�󷵻�""

	m["banana"] = "�㽶";

	if (m.find("peach") == m.end())
	{
		m["peach"] = "����";
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

	// ��Χfor
	for (auto& e : m)
		cout << e.first << "--->" << e.second << endl;
	cout << endl;

	m.clear();
	cout << m.size() << endl;
}