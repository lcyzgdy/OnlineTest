#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<functional>
#include<map>
#include<string>
#include<sstream>
using namespace std;

map<string, size_t> fileError;
vector<string> queue;

int main()
{
	string fullFile;
	int line;
	while (cin >> fullFile >> line)
	{
		//cout << fullFile << ' ' << line << endl;
		string fileName;
		if (fullFile == "END") break;
		if (!fullFile.find('\\'))
		{
			fileName = fullFile;
		}
		else
		{
			fileName = fullFile.substr(fullFile.find_last_of('\\') + 1);
		}
		if (fileName.length() > 16) fileName = fileName.substr(fileName.length() - 16);

		stringstream ss;
		ss << fileName << ' ' << line;
		fileError[ss.str()]++;
		if (queue.size() < 8)
		{
			queue.emplace_back(ss.str());
		}
		else
		{
			if (find(queue.begin(), queue.end(), ss.str()) == queue.end())
			{
				queue.emplace_back(ss.str());
			}
		}
	}
	for (int i = queue.size() - 8; i < (int)queue.size(); i++)
	{
		if (i < 0) i = 0;
		cout << queue[i] << ' ' << fileError[queue[i]] << endl;
	}
	return 0;
}