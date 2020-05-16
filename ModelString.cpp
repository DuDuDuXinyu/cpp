#include <iostream>
#pragma warning (disable:4996)

using namespace std;

#if 0
namespace mine
{
	//string类：动态类型的字符顺序表

	class string
	{
	public:
		/*string(const char* str = "")
		{
			if (nullptr == str)
			{
				//构造一个空的字符串""：是一个有效的字符串，只不过是字符串中只包含'\0'

				_str = new char[1];
				*_str = '\0';
			}
			else
			{
				//多申请一个空间，为了存放\0

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

	//对象销毁的时候，共用同一份资源的空间，多次释放的时候会报错
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

		//深拷贝

		/*方法一：
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

		//方法二：
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

		//优化
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

			//标准库中的string类容量没有算\0的空间
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
				//直接填充
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