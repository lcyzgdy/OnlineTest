#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<string> sen;

int main()
{
	string word;
	while (getline(cin, word))
	{
		string l;
		cout << l.length() << endl;
		for (int i = 0; i < word.length(); i++)
		{
			if (word[i] >= 'a' && word[i] <= 'z' || (word[i] >= 'A' && word[i] <= 'Z'))
			{
				l += word[i];
			}
			else
			{
				if (l.length() > 0 && l != "" && l[0] != '\0') sen.emplace_back(l);
				l.clear();
			}
		}
		if (l.length() > 0) sen.emplace_back(l);
		for (int i = sen.size() - 1; i > 0; i--)
		{
			cout << sen[i] << ' ';
		}
		if (sen.size() > 0)cout << sen[0] << endl;
		sen.clear();
	}

	return 0;
}