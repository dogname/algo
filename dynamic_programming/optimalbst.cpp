#include <iostream>
#include <vector>
using namespace std;
void optimalBST(vector<double>& p, vector<double>& q, vector<vector<double>>& e, vector<vector<int>>& root)
{
	int n = p.size();
	vector<vector<double>> w(q.size(), vector<double>(q.size()));
	for (int i = 0; i < q.size(); ++i)
	{
		e[i][i] = q[i];
		w[i][i] = q[i];
	}
	for (int l = 0; l < n; ++l)
	{
		for (int i = 0; i < n - l; ++i)
		{
			int j   = i + l + 1;
			e[i][j] = 1.0 / 0.0;
			w[i][j] = w[i][j - 1] + p[j - 1] + q[j];
			for (int k = i; k < j; ++k)
			{
				double tmp = e[i][k] + e[k + 1][j] + w[i][j];
				if (tmp < e[i][j])
				{
					e[i][j]        = tmp;
					root[i][j - 1] = k;
				}
			}
		}
	}
}
int main(int argc, char* argv[])
{
	vector<double> p{0.04, 0.05, 0.08, 0.02, 0.10, 0.12, 0.14};
	vector<double> q{0.06, 0.06, 0.06, 0.06, 0.05, 0.05, 0.05, 0.05};
	vector<vector<double>> e(q.size(), vector<double>(q.size()));
	vector<vector<int>> root(p.size(), vector<int>(p.size()));
	optimalBST(p, q, e, root);
	for (int l = 0; l < q.size(); ++l)
	{
		for (int i = 0; i < q.size() - l; ++i)
		{
			int j = i + l;
			std::cout << e[i][j] << " ";
		}
		cout << "\n";
	}
	for (int l = 0; l < p.size(); ++l)
	{
		for (int i = 0; i < p.size() - l; ++i)
		{
			int j = i + l;
			std::cout << root[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}
