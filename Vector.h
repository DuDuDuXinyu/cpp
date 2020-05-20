#pragma once
namespace mine
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
	public:
		vector()
			:start(nullptr)
			,finish(nullptr)
			,end_of_storage(nullptr)
		{}
		vector(size_t n, const T& data = T())
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
			while (it != last)
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
				delete[] start
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

			}
			else
			{
				if (newsize > capacity())
				{
					reserve(newsize);
				}
			}
		}

		void reserve(size_t newcapacity)
		{

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

		T& front()const
		{
			return *start;
		}
		const T& front()const
		{
			return *start;
		}
		T& back()const
		{
			return *(finish-1);
		}
		const T& back()const
		{
			return *(finish - 1);
		}

		void push_back(const T& data)
		{
			insert(end(), data);
		}
		void pop_back()
		{
			insert(end() - 1);
		}
		iterator insert(iterator pos, const T& data);
		iterator erase(iterator pos);

	private:
		iterator start;
		iterator finish;
		iterator end_of_storage;
	};
}