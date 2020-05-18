#include <iostream>
#include <assert.h>
#pragma warning (disable:4996)

using namespace std;

#if 0
namespace mine
{
	//string�ࣺ��̬���͵��ַ�˳���

	class string
	{
	public:
		/*string(const char* str = "")
		{
			if (nullptr == str)
			{
				//����һ���յ��ַ���""����һ����Ч���ַ�����ֻ�������ַ�����ֻ����'\0'

				_str = new char[1];
				*_str = '\0';
			}
			else
			{
				//������һ���ռ䣬Ϊ�˴��\0

				_str = new char[strlen(str) + 1];
				strcpy(_str, str);
			}
		}*/

		string(const char* str = "")
		{
			if (nullptr == str)
				str = "";

			_str = new char[strlen(str) + 1];
			strcpy(_str, str);
		}


		~string()
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
			}
		}
	private:
		char* _str;
	};
}

void TestString()
{
	mine::string s1;
	mine::string s2("hello");

	//�������ٵ�ʱ�򣬹���ͬһ����Դ�Ŀռ䣬����ͷŵ�ʱ��ᱨ��
	//mine::string s3(s1);
}

int main()
{
	TestString();
	return 0;
}
#endif 

#if 0
namespace mine
{
	class string
	{
	public:
		string(const char* str = "")
		{
			if (nullptr == str)
				str = "";

			_str = new char[strlen(str) + 1];
			strcpy(_str, str);
		}

		//���

		/*����һ��
		string(const string& s)
			:_str(new char[strlen(s._str) + 1])
		{
			strcpy(_str,s._str);
		}

		string& operator=(const string& s)
		{
			if (this != &s)
			{
				char* temp = new char[strlen(s._str) + 1];
				strcpy(temp, s._str);
				delete[] _str;
				_str = temp;
			}
			return *this;
		}
		*/

		//��������
		string(const string& s) 
			:_str(nullptr)
		{
			string str(s._str);
			swap(_str, str._str);
		}

		/*string& operator=(string s)
		{
			swap(_str, s._str);
			return *this;
		}*/

		//�Ż�
		string& operator=(const string& s)
		{
			if (this != &s)
			{
				string str(s);
				swap(_str, str._str);
			}
			return *this;
		}

		~string()
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
			}
		}
	private:
		char* _str;
	};
}

void TestString()
{
	mine::string s1("hello");
	mine::string s2(s1);
	mine::string s3;
	s3 = s2;
}

int main()
{
	TestString();
	return 0;
}
#endif 

namespace mine
{
	class string
	{
		friend ostream& operator<<(ostream& _cout, const mine::string& s);

	public:
		typedef char* iterator;

	public:
		string(const char* str = "")
		{
			if (nullptr == str)
				str = "";

			//��׼���е�string������û����\0�Ŀռ�
			_size = strlen(str);
			_capacity = _size <= 15 ? 15 : strlen(str);
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		string(const string& s, size_t pos, size_t n = npos)
		{
			size_t len = s.size();
			if (pos > len)
				pos = len;

			if (n > len - pos)
				n = len - pos;

			_str = new char[n - 1];
			strncpy(_str, s.c_str() + pos, n);
			_size = n;
			_capacity = n;
			_str[_size] = '\0';
		}

		string(const string& s)
			:_str(nullptr)
		{
			string str(s._str);
			this->swap(str);
		}

		string& operator=(const string& s)
		{
			if (this != &s)
			{
				string str(s._str);
				this->swap(str);
			}
			
			return *this;
		}

		size_t capacity()const
		{
			return _capacity;
		}

		size_t size()const 
		{
			return _size;
		}

		bool empty()const
		{
			return 0 == _size;
		}

		void reserve(size_t newCapacity)
		{
			size_t oldCapacity = capacity();

			if (newCapacity > oldCapacity)
			{
				char* temp = new char[newCapacity + 1];
				strcpy(temp, _str);
				delete[] _str;
				_str = temp;
				_capacity = newCapacity;
			}
		}

		void resize(size_t newsize, char ch)
		{
			size_t oldsize = size();
			//if (newsize < oldsize)
			//{
			//	_size = newsize;
			//	_str[_size] = '\0';
			//}
			//else if (newsize < _capacity)
			//{
			//	//ֱ�����
			//	memset(_str + _size, ch, newsize - oldsize);
			//	_size = newsize;
			//	_str[_size] = '\0';
			//}
			//else
			//{
			//	reserve(newsize);
			//	memset(_str + _size, ch, newsize - oldsize);
			//	_size = newsize;
			//	_str[_size] = '\0';
			//}

			if (newsize > oldsize)
			{
				if (newsize > capacity())
					reserve(newsize);

				memset(_str + _size, ch, newsize - oldsize);
			}
			_size = newsize;
			_str[_size] = '\0';
		}

		void resize(size_t newsize)
		{
			resize(newsize, 0);
		}

		void clear()
		{
			_size = 0;
			*_str = '\0';
		}

		//������

		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		void swap(string& s)
		{
			std::swap(_str, s._str);
			std::swap(_capacity, s._capacity);
			std::swap(_size, s._size);
		}

		~string()
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
				_capacity = 0;
				_size = 0;
			}
		}

		char& operator[](size_t index)
		{
			assert(index < _size);
			return _str[index];
		}

		const char& operator[](size_t index)const
		{
			assert(index < _size);
			return _str[index];
		}

		void push_back(char ch)
		{
			if (_size == _capacity)
				reserve(_size * 2);

			_str[_size++] = ch;
			_str[_size] = '\0';
		}

		string& operator +=(const char* s)
		{
			int len = strlen(s);
			reserve(_size + len);
			strcpy(_str + _size, s);
			_size += len;
			return *this;
		}

		const char* c_str()const
		{
			return _str;
		}

		size_t find(char ch, size_t pos)const
		{
			for (int i = pos; i < _size; i++)
			{
				if (ch == _str[i])
					return i;
			}
			return npos;
		}

		size_t rfind(char ch, size_t pos)
		{
			for (int i = pos != npos ? pos : _size - 1; i >= 0; i--)
			{
				if (ch == _str[i])
					return i;
			}
			return npos;
		}

		// ��posλ�ÿ�ʼ����ȡn���ַ�����һ���µ��ַ�������
		// "hello"---> pos:2   n: 5
		string substr(size_t pos = 0, size_t n = npos)const
		{
			if (pos > _size)
				pos = _size;

			if (n > _size - pos)
				n = _size - pos;

			return string(*this, pos, n);
		}

	private:
		char* _str;
		size_t _capacity;
		size_t _size;

		static size_t npos;
	};
	size_t string::npos = -1;
}

ostream& mine::operator<<(ostream& _cout, const mine::string& s)
{
	// _cout << s._str;
	for (size_t i = 0; i < s.size(); ++i)
	{
		if (s[i] == '\0')
			cout << ' ';
		else
			cout << s[i];
	}
	return _cout;
}