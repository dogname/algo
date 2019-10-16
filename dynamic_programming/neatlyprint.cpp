#include <climits>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;
void neatlyprint(vector<string>& words, vector<int>& cube, vector<int>& beg, int w)
{
	vector<vector<int>> lineCube(words.size(), vector<int>(words.size()));
	vector<vector<int>> lineExtra(words.size(), vector<int>(words.size()));
	for (int i = 0; i < words.size(); ++i)
	{
		lineExtra[i][i] = w - words[i].length();
		for (int j = i + 1; j < words.size(); ++j)
		{
			lineExtra[i][j] = lineExtra[i][j - 1] - words[j].length() - 1;
		}
	}
	for (int i = 0; i < words.size(); ++i)
	{
		for (int j = i; j < words.size(); ++j)
		{
			if (lineExtra[i][j] < 0)
				lineCube[i][j] = INT_MAX;
			else if (j == words.size() - 1)
				lineCube[i][j] = 0;
			else
				lineCube[i][j] = pow(lineExtra[i][j], 3);
		}
	}
	cube[0] = lineCube[0][0];
	beg[0]  = 0;
	for (int j = 1; j < words.size(); ++j)
	{
		cube[j] = INT_MAX;
		for (int i = 0; i <= j; ++i)
		{
			long long tmp = (i < 1 ? 0 : cube[i - 1]) + (long long)lineCube[i][j];
			if (tmp < cube[j])
			{
				cube[j] = tmp;
				beg[j]  = i;
			}
		}
	}
}
void printWords(vector<string>& words, vector<int>& beg, int n)
{
	if (n < 0) return;
	printWords(words, beg, beg[n] - 1);
	for (int i = beg[n]; i < n; ++i)
	{
		std::cout << words[i] << " ";
	}
	std::cout << words[n] << "\n";
}
int main(int argc, char* argv[])
{
	vector<string> words{"aa", "bb", "casdaw", "asdadasd", "ad", "aasdda", "asdsx", "sdad", "sxz"};
	vector<int> cube(words.size());
	vector<int> beg(words.size());
	for (int i = 0; i < words.size(); ++i)
	{
		std::cout << cube[i] << " ";
	}
	std::cout << "\n";
	for (int i = 0; i < words.size(); ++i) std::cout << beg[i] << " ";
	std::cout << std::endl;
	neatlyprint(words, cube, beg, 20);
	printWords(words, beg, words.size() - 1);
	return 0;
}
