#include <algorithm>
#include <iostream>
#include <vector>
using std::vector;
const int cost = 2;
int cutRod(vector<int>& p, int n, vector<int>& s)
{
	vector<int> r(n + 1, 0);
	r[0] = 0;
	for (int i = 1; i <= n; ++i)
	{
		int q = 0;
		for (int j = 1; j < i; ++j)
		{
			if (q < p[j] + r[i - j] - cost)
			{
				q    = p[j] + r[i - j] - cost;
				s[i] = j;
			}
		}
		if (q < p[i])
		{
			q    = p[i];
			s[i] = i;
		}
		r[i] = q;
	}
	return r[n];
}

int main(int argc, char* argv[])
{
	using std::cout;
	vector<int> price = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
	vector<int> s(price.size(), 0);
	for (int n = 1; n < 11; ++n)
	{
		int res = cutRod(price, n, s);
        cout << n << "结果\n";
		cout << res << "\n";
		cout << "长度分别为:\n";
        int k = n;
		while (k)
		{
			cout << s[k] << " ";
			k -= s[k];
		}
		cout << "\n";
	}
	return 0;
}
