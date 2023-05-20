#include <iostream>
#include <string>
using namespace std;
//void computeLPS(string pat, int* lps)
int computeLPS(string pat, int* lps)
{
	int j = 0;

	lps[0] = 0; // lps[0] is always 0 

	int i = 1;
	while (i < pat.size()) {
	//while (i < n) {
		if (pat[i] == pat[j]) {
			j++;
			lps[i] = j;
			i++;
		}
		else
		{
			if (j != 0) {
				j = lps[j - 1];
			}
			else
			{
				lps[i] = 0;
				i++;
			}
		}
	}
	int a = 0;
	int countZerro = 0;
	while (a < pat.size()) {
		if (lps[a] == 0)
			++countZerro;
		a++;
	}
	return countZerro;
}
int KMPSearch(const string& pat, const string& txt) //возращаем счетсик совпадений
{
	int* lps = new int[pat.size()];
	computeLPS(pat, lps);

	int i = 0;
	int j = 0;
	int count = 0; // счетчик совпадений
	while (i < txt.size()) {
		char tempA = pat[j];
		char tempB = txt[i];
		if (pat[j] == txt[i])
		{
			j++;
			i++;
			++count;
		}
		if (j == pat.size()) {
			cout << "Found pattern at index" << i - j << endl;
			j = lps[j - 1];
		}
		else if (i < txt.size() && pat[j] != txt[i]) {
			if (j != 0)
			{
				j = lps[j - 1];
			}
			else
			{
				i = i + 1;
			}
		}
	}
	delete lps;
	return count;
}

