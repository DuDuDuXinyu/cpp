#include <iostream>
#include <vector>
using namespace std;

class UnionFindSet
{
public:
	UnionFindSet(int n)
	{
		_v.resize(n, -1);
	}

	int FindRoot(int x)
	{
		while (_v[x] >= 0)
			x = _v[x];

		return x;
	}

	bool Union(int x1, int x2)
	{
		int root1 = FindRoot(x1);
		int root2 = FindRoot(x2);

		if (root1 == root2)
			return false;

		_v[root1] += _v[root2];
		_v[root2] = root1;

		return true;
	}

	size_t Size()
	{
		int n = 0;
		for (auto e : _v)
			n++;

		return n;
	}

private:
	vector<int> _v;
};

int main()
{
	vector<vector<int>> ufs(10, vector<int>(5));
	cout << ufs.size() << "  " << ufs[1].size() << endl;

	return 0;
}