#include <iostream>
#include <string>
using namespace std;


//string�ĳ�ʼ��
void TestString1()
{
	string s1;
	string s2("hello world");
	string s3(10, '$');
	string s4(s2);
	string s5 = "zbc";
	//s2��s5ʹ�õ���ͬһ�����������string�����
	//string(const char*)

	//s6���Ǵ�����һ������
	//����������һ���޲εķ���ֵΪstring���͵ĺ���
	string s6();

	cin >> s1;
	cout << s1 << endl;
	cout << s2 << endl; 
	cout << s3 << endl; 
	cout << s4 << endl; 

	//�ӵ�һ���ַ���ʼһ�����ıȽ�
	if (s5 > s2)
	{
		cout << 123 << endl;
	}

	s1 = s2;
	cout << s1 << endl;

	//����ƴ��
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
		cout << "���ַ���" << endl;
	}
	else
	{
		cout << "�ǿ��ַ���" << endl;
	}
}

/*reserve:
���ݺ���--ֻ�����ݣ����ı���ЧԪ�ظ���
reserve(n)��nֻ�бȵ�ǰstring���������ʱ��Ż�����
���Ҳ�������Ϊn
reserve(n)��nС�ڵ�ǰstring��������ʱ���Զ����Ըò���
����n<15��ʱ��ռ���СΪ15
15�ǵײ�����Ĵ�Сʵ���ϲ�����С
Ҳ����˵reserve������д����ֻ������
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


//resize(size_t n,char ch)����string�е���Ч�ַ��ı�Ϊn��������ַ���ch�����
//resize(size_t n)����string�е���Ч�ַ��ı�Ϊn��������ַ���0�����
/*
resize(newsize,ch)������string����Ч����Ϊsize������Ϊcapacity
newsize < size��ֻ�ǽ���ЧԪ�ظ�Ϊnewsize���ɣ�������С����
size<newsize<capacity��ֱ�ӽ���ЧԪ�ظ������ӵ�newsize�����newsize-size��ch��䣬û��ch��0���
newsize>capacity������-->�����¿ռ䣬����Ԫ���ͷžͿռ䣬����ЧԪ�ظ�Ϊnewsize
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
		if (sz != s.capacity()) //�¾�������һ����ʱ���ӡһ������
		{ 
			sz = s.capacity();   
			cout << "capacity changed: " << sz << '\n';
		} 
	}
}

void TestString5()
{
	string s1("hello");
	
	//Խ��
	//s1[10] = '!';	assert����
	//s1.at(10) = '!';	���쳣

	cout << s1[0] << endl;
	s1[0] = 'H';
	cout << s1 << endl;

	//���s1�е���ĸ���Ǵ�д�������Ϊ��д
	for (size_t i = 0; i < s1.size(); i++)
	{
		if (s1[i] >= 'a' && s1[i] <= 'z')
			s1[i] -= 32;
	}

	//�����������䵱��һ��ָ������
	//string::iterator it = s1.begin();����̫����ʹ��auto�򻯴���
	//begin��end�������������endָ��\0
	auto it = s1.begin();
	while (it != s1.end())
	{
		cout << *it;
		it++;
	}
	cout << endl;

	//string�������һ����Χȷ�������У�����֧�ַ�Χauto
	for (auto c : s1)
		cout << c;
	cout << endl;

	const string s2("world");
	//s2[0] = 'W';

	//�����������beginָ��\0
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

	//�ڸ�λ�õ�ǰһ��λ�ò���
	s.insert(s.find('!'), "~_~");

	//�Ӹ�λ�ÿ�ʼɾ��
	//һ������������������ղ���
	//�ڶ�������n��ɾ��n��������ֱ��ɾ��ĩβ
	s.erase(s.find('!')-1);

	cout << s << endl;
}

void TestString7()
{
	//��ȡ�ļ���׺
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