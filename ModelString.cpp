#include <iostream>
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

		string(const string& s)
			:_str(nullptr)
		{
			string str(s._str);
			this->swap(str);
		}

		string& operator=(string s)
		{
			this->swap(s);
			return *this;
		}

		size_t capacity()
		{
			return _capacity;
		}

		size_t size()
		{
			return _size;
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
			if (newsize < oldsize)
			{
				_size = newsize;
				_str[_size] = '\0';
			}
			else if (newsize < _capacity)
			{
				//ֱ�����
				memset(_str + _size, ch, newsize - oldsize);
				_size = newsize;
				_str[_size] = '\0';
			}
			else
			{
				reserve(newsize);
				memset(_str + _size, ch, newsize - oldsize);
				_size = newsize;
				_str[_size] = '\0';
			}
		}

		void resize(size_t newsize)
		{
			resize(newsize, 0);
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
	private:
		char* _str;
		size_t _capacity;
		size_t _size;
	};
}