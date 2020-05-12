#include <iostream>
#include <string>
using namespace std;


//string的初始化
void TestString1()
{
	string s1;
	string s2("hello world");
	string s3(10, '$');
	string s4(s2);
	string s5 = "zbc";
	//s2和s5使用的是同一个方法构造的string类对象
	//string(const char*)

	//s6不是创建了一个对象
	//而是声明了一个无参的返回值为string类型的函数
	string s6();

	cin >> s1;
	cout << s1 << endl;
	cout << s2 << endl; 
	cout << s3 << endl; 
	cout << s4 << endl; 

	//从第一个字符开始一个个的比较
	if (s5 > s2)
	{
		cout << 123 << endl;
	}

	s1 = s2;
	cout << s1 << endl;

	//可以拼接
	s3 = s1 + s2;
	cout << s3 << endl;
}

void TestString2()
{
	string s("little man,huge dream!");
	cout << s.size() << endl;
	cout << s.length() << endl;
	cout << s.capacity() << endl;

	s.clear();	
	if (s.empty())
	{
		cout << "空字符串" << endl;
	}
	else
	{
		cout << "非空字符串" << endl;
	}
}

/*reserve:
扩容函数--只是扩容，不改变有效元素个数
reserve(n)：n只有比当前string的容量大的时候才会扩容
并且不是扩大为n
reserve(n)：n小于当前string的容量的时候自动忽略该操作
除非n<15的时候空间缩小为15
15是底层数组的大小实际上不是缩小
也就是说reserve不会缩写容量只会扩容
*/
void TestString3()
{
	string s("hello");
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.reserve(20);
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.reserve(40);
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.reserve(50);
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.reserve(60);
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.reserve(80);
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.reserve(40);
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.reserve(20);
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.reserve(10);
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;
}


//resize(size_t n,char ch)：将string中的有效字符改变为n个多出的字符用ch来填充
//resize(size_t n)：将string中的有效字符改变为n个多出的字符用0来填充
/*
resize(newsize,ch)：假设string的有效个数为size，容量为capacity
newsize < size：只是将有效元素改为newsize即可，不会缩小容量
size<newsize<capacity：直接将有效元素个数增加到newsize多出的newsize-size用ch填充，没有ch用0填充
newsize>capacity：扩容-->申请新空间，拷贝元素释放就空间，将有效元素改为newsize
*/
void TestString4()
{
	string s("hello");
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.resize(10, '!');
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.resize(20, '$');
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.resize(40, '&');
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.resize(30);
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.resize(20);
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.resize(10);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
}

void TestPushBack() {
	string s;
	s.reserve(100);
	size_t sz = s.capacity();
	cout << sz << endl;
	cout << "making s grow:\n";  
	for (int i = 0; i < 100; ++i) 
	{
		s.push_back('c');    
		if (sz != s.capacity()) //新旧容量不一样的时候打印一次容量
		{ 
			sz = s.capacity();   
			cout << "capacity changed: " << sz << '\n';
		} 
	}
}

void TestString5()
{
	string s1("hello");
	
	//越界
	//s1[10] = '!';	assert触发
	//s1.at(10) = '!';	抛异常

	cout << s1[0] << endl;
	s1[0] = 'H';
	cout << s1 << endl;

	//如果s1中的字母不是大写，将其改为大写
	for (size_t i = 0; i < s1.size(); i++)
	{
		if (s1[i] >= 'a' && s1[i] <= 'z')
			s1[i] -= 32;
	}

	//迭代器：将其当成一个指针来用
	//string::iterator it = s1.begin();定义太复杂使用auto简化代码
	//begin和end是正向迭代器，end指向\0
	auto it = s1.begin();
	while (it != s1.end())
	{
		cout << *it;
		it++;
	}
	cout << endl;

	//string本身就是一个范围确定的序列，可以支持范围auto
	for (auto c : s1)
		cout << c;
	cout << endl;

	const string s2("world");
	//s2[0] = 'W';

	//反向迭代器，begin指向\0
	auto rit = s2.rbegin();
	while (rit != s2.rend())
	{
		cout << *rit;
		rit++;
	}
	cout << endl;
}

void TestString6()
{
	string s;
	s.push_back('I');
	s.append(" love ");
	
	string ss("you");
	s.append(ss);

	s += " !!!";

	//在该位置的前一个位置插入
	s.insert(s.find('!'), "~_~");

	//从该位置开始删除
	//一个参数都不给就是清空操作
	//第二个参数n就删除n个，否则直接删到末尾
	s.erase(s.find('!')-1);

	cout << s << endl;
}

void TestString7()
{
	//截取文件后缀
	string strFile("F:workspace/text.cpp");
	string strFix = strFile.substr(strFile.rfind('.' )+ 1);
	cout << strFix << endl;

	string url = "http:\\www.baidu.com\\123456.html";
	size_t pos = url.find(":\\")+2;
	string net = url.substr(pos, url.find("\\", pos) - pos);
	cout << net << endl;
}

int main()
{
	//TestString1();
	//TestString2();
	//TestString3
	//TestString4();
	//TestPushBack();
	//TestString5();
	//TestString6();
	TestString7();

	return 0;
}