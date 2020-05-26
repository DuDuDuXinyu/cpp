#pragma once

namespace mine
{
	template <class T>
	struct ListNode
	{
		ListNode<T>* next;
		ListNode<T>* prev;
		T val;

		ListNode(const T& value=T())
			:next(nullptr)
			,prev(nullptr)
			,val(value)
		{}
	};

	//list的迭代器必须对原生态的指针进行封装

	template<class T,class Ref ,class Ptr>
	struct ListIterator
	{
	public:
		typedef ListNode<T> Node;
		typedef ListIterator<T, Ref, Ptr> Self;
	public:
		ListIterator(Node* node=nullptr)
			:_node(node)
		{}

		Ref operator*()
		{
			return _node->val;
		}

		Ptr operator->()
		{
			return &(operator*());
		}

		//前置++
		Self& operator++()
		{
			_node = _node->next;
			return *this;
		}

		//后置++
		Self operator++(int)
		{
			Self temp(*this);
			_node = _node->next;
			return temp;
		}

		//前置--
		Self& operator--()
		{
			_node = _node->prev;
			return *this;
		}

		// 后置--
		Self operator--(int)
		{
			Self temp(*this);
			_node = _node->prev;
			return temp;
		}

		bool operator!=(const Self& s)const
		{
			return _node != s._node;
		}

		bool operator==(const Self& s)const
		{
			return _node == s._node;
		}

		Node* _node;
	};

	template<class T>
	class list
	{
		typedef ListNode<T> Node;
	public:
		typedef ListIterator<T, T&, T*> iterator;
		typedef ListIterator<T, const T&, const T*> const_iterator;

	public:
		list() 
		{
			CreateHead();
		}

		list(int n, const T& value = T())
		{
			CreateHead();
			for (int i = 0; i < n; i++)
				push_back(value);
		}

		template<class Iterator>
		list(Iterator first, Iterator last)
		{
			CreateHead();
			while (first != last)
			{
				push_back(*first++);
			}
		}
	
		list(list<T>& L)
		{
			CreateHead();
			auto it = L.begin();

			while (it != L.end())
				push_back(*it++);
		}

		~list()
		{
			erase(begin(), end());
			delete head;
			head = nullptr;
		}

		iterator begin()
		{
			return iterator(head->next);
		}

		iterator end()
		{
			return iterator(head);
		}

		const_iterator cbegin()const
		{
			return const_iterator(head->next);
		}

		const_iterator cend()const
		{
			return const_iterator(head);
		}

		size_t size()const
		{
			size_t count = 0;
			auto it = cbegin();
			while (it != cend())
				it++, count++;

			return count;
		}

		bool empty()const
		{
			return head->next == head;
		}

		void resize(size_t newsize, const T& data = T())
		{
			size_t oldsize = size();
			if(newsize<oldsize)
				for (size_t i = newsize; i < oldsize; ++i)
					pop_back();
			else
				for (size_t i = oldsize; i < newsize; ++i)
					push_back(data);
		}

		T& front()
		{
			return head->next->val;
		}

		const T& front()const
		{
			return head->next->val;
		}

		T& back()
		{
			return head->prev->val;
		}

		const T& back()const
		{
			return head->prev->val;
		}

		void push_back(const T& data)
		{
			insert(end(), data);
		}

		void pop_back()
		{
			auto it = end();
			erase(--it);
		}

		void push_front(const T& data)
		{
			insert(begin(), data);
		}

		void pop_front()
		{
			erase(begin());
		}

		// 在pos位置插入值为data的元素，返回新插入元素的位置
		iterator insert(iterator pos, const T& data)
		{
			Node* newNode = new Node(data);
			newNode->prev = pos._node->prev;
			newNode->next = pos._node;
			newNode->prev->next = newNode;
			pos._node->prev = newNode;

			return iterator(newNode);
		}

		iterator erase(iterator pos)
		{
			Node* ret = pos._node->next;

			Node* cur = pos._node;
			cur->prev->next = cur->next;
			cur->next->prev = cur->prev;
			delete cur;

			return iterator(ret);
		}

		iterator erase(iterator first, iterator last)
		{
			while (first != last)
				first = erase(first);

			return end();
		}

		void clear()
		{
			erase(begin(), end());
		}

		void swap(list<T>& L)
		{
			std::swap(head, L.head);
		}

	private:
		void CreateHead()
		{
			head = new Node;
			head->prev = head;
			head->next = head;
		}

		Node* head;
	};
}