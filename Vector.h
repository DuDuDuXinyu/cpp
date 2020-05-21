#pragma once

#include <assert.h>

namespace mine
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
	public:
		vector()
			:start(nullptr)
			,finish(nullptr)
			,end_of_storage(nullptr)
		{}
		vector(int n, const T& data = T())
		{
			start = new T[n];
			for (size_t i = 0; i < n; i++)
				start[i] = data;
			finish = start + n;
			end_of_storage = finish;
		}

		template<class Iterator, class Iterator>
		vector(Iterator first, Iterator last)
		{
			size_t size = 0;
			auto it = first;
			while (it++ != last)
				size++;
			start = new T[size];
			finish = start;
			while (first != last)
				*finish++ = *first++;
			end_of_storage = finish;
		}

		vector(const vector<T>& v)
		{
			start = new T[v.size()];
			finish = start;
			auto it = v.begin();
			while (it != v.end())
				*finish++ = *it++;
			end_of_storage = finish;
		}

		vector<T>& operator=(const vector<T>& v);

		~vector()
		{
			if (start)
				delete[] start;

			start = finish = end_of_storage = nullptr;
		}

		iterator begin()
		{
			return start;
		}
		iterator end()
		{
			return finish;
		}

		const_iterator begin()const
		{
			return start;
		}
		const_iterator end()const
		{
			return finish;
		}

		size_t size()const
		{
			return finish - start;
		}
		size_t capacity()const
		{
			return end_of_storage - start;
		}
		bool empty()const
		{
			return start == finish;
		}
		void resize(size_t newsize, const T& data == T())
		{
			size_t oldsize = size();
			if (newsize <= oldsize)
			{
				finish = start + newsize;
			}
			else
			{
				if (newsize > capacity())
				{
					reserve(newsize);
				}
				
				for (size_t i = oldsize; i < newsize; i++)
					*finish++ = data;
			}
		}

		void reserve(size_t newcapacity)
		{
			size_t oldcapacity = capacity();
			if (newcapacity > oldcapacity)
			{
				T* temp = new T[newcapacity];

				size_t oldsize = size();
				if (start)
				{
					//Ç³¿½±´
					//memcpy(temp, start, oldsize * sizeof(T));
					for (size_t i = 0; i < oldsize; i++)
						temp[i] = start[i];

					delete[]start;
				}
				start = temp;
				finish = start + oldsize;
				end_of_storage = start + newcapacity;
			}
		}

		T& operator[](size_t index)
		{
			assert(index < size());
			return start[index];
		}
		const T& operator[](size_t index)const
		{
			assert(index < size());
			return start[index];
		}

		T& front()
		{
			return *start;
		}
		const T& front()const
		{
			return *start;
		}
		T& back()
		{
			return *(finish-1);
		}
		const T& back()const
		{
			return *(finish - 1);
		}

		void push_back(const T& data)
		{
			if (finish == end_of_storage)
				reserve(2 * capacity());

			*finish++ = data;
		}
		void pop_back()
		{
			erase(end() - 1);
		}
		iterator insert(iterator pos, const T& data)
		{
			if (pos<start || pos>end())
				return end();

			if (finish == end_of_storage)
				reserve(2 * capacity());

			auto cur = finish - 1;
			auto next = finish;
			while (cur >= pos)
				*next-- = *cur--;

			*next = data;
			finish++;
			return pos;
		}

		iterator erase(iterator pos)
		{
			if (pos < start || pos >= finish)
				return finish;

			auto prev = pos;
			auto cur = pos + 1;

			while (cur <= finish)
				*prev++ = *cur++;

			finish--;
			return pos;
		}

		void clear()
		{
			finish = start;
		}
	private:
		iterator start;
		iterator finish;
		iterator end_of_storage;
	};
}