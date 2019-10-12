#include <iostream>
#include <vector>
#include <string>
using namespace std;
void lcsSolver(string& X, string& Y, vector<vector<int>>& c)
{
	int m = X.length();
	int n = Y.length();
	for (int i = 0; i <= m; ++i) c[i][0] = 0;
	for (int j = 1; j <= n; ++j) c[0][j] = 0;
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= n; ++j)
		{
			if (X[i - 1] == Y[j - 1])
				c[i][j] = c[i - 1][j - 1] + 1;
			else
				c[i][j] = c[i - 1][j] < c[i][j - 1] ? c[i][j - 1] : c[i - 1][j];
		}
}

void printLCS(string& X, vector<vector<int>>& c, int i, int j)
{
	if (i == 0 || j == 0) return;
	if (c[i][j] != c[i - 1][j] && c[i][j] != c[i][j - 1])
	{
		printLCS(X, c, i - 1, j - 1);
		cout << X[i-1];
	}
	else if (c[i][j] == c[i - 1][j])
		printLCS(X, c, i - 1, j);
	else
		printLCS(X, c, i, j - 1);
}

int main(int argc, char *argv[])
{
	string s1 = "ACCGGTCGAGTGCGCGGAAGCCGGCCGAA";
	string s2 = "GTCGTTCGGAATGCCGTTGCTCTGTAAA";
    vector<vector<int>> c(s1.length()+1,vector<int>(s2.length()+1));
    lcsSolver(s1, s2, c);
    printLCS(s1, c, s1.length(), s2.length());
    cout << "\n";
	return 0;
}
