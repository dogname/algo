#include <iostream>
#include <climits>
#include <vector>
using namespace std;
void matrixChainOrder(vector<int>& p, vector<vector<int>>& m, vector<vector<int>>& s)
{
	int n = m.size();
	for (int i = 0; i < n; ++i)
	{
		m[i][i] = 0;
	}
	for (int l = 2; l <= n; ++l)
	{
        for(int i = 0; i <= n - l;++i)
        {
			int j = i + l - 1;
			m[i][j] = INT_MAX;
			for (int k = i; k < j; ++k)
			{
				int q = m[i][k] + m[k + 1][j] + p[i] * p[k + 1] * p[j + 1];
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
			}
		}
	}
}

void printParens(vector<vector<int>>& s, int beg, int end)
{
	if (beg == end)
		std::cout << "A";
	else
	{
		cout << "(";
		printParens(s, beg, s[beg][end]);
		printParens(s, s[beg][end] + 1, end);
		cout << ")";
	}
}
int main(int argc, char* argv[])
{
	vector<int> p{30, 35, 15, 5, 10, 20, 25};
	vector<vector<int>> m(p.size() - 1, vector<int>(p.size() - 1));
	vector<vector<int>> s(p.size() - 1, vector<int>(p.size() - 1));
    matrixChainOrder(p, m, s);
	printParens(s, 0, s.size() - 1);
	cout << "\n";
	return 0;
}
