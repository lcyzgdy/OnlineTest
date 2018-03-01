#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
#include<map>
#include<vector>
using namespace std;

char pq[2018];

bool Cmp(char a, char b)
{
	if ((a >= 'a' && a <= 'z') && (b >= 'a' && b <= 'z')) return a <= b;
	else if ((a >= 'A' && a <= 'Z') && (b >= 'a' && b <= 'z')) return a - 'A' + 'a' <= b;
	else if ((a >= 'a' && a <= 'z') && (b >= 'A' && b <= 'Z')) return a <= b - 'A' + 'a';
	else return a <= b;
}

void MergeSort(int l, int r)
{
	if (l >= r) return;
	int mid = (l + r) >> 1;
	MergeSort(l, mid);
	MergeSort(mid + 1, r);
	char temp[2018];
	memset(temp, 0, sizeof(temp));
	for (int i = l; i <= r; i++)
	{
		temp[i] = pq[i];
	}
	int ll = l; int rr = mid + 1;
	for (int i = l; i <= r; i++)
	{
		if (ll > mid)
		{
			pq[i] = temp[rr];
			rr++;
		}
		else if (rr > r)
		{
			pq[i] = temp[ll];
			ll++;
		}
		else if (Cmp(temp[ll], temp[rr]))
		{
			pq[i] = temp[ll];
			ll++;
		}
		else
		{
			pq[i] = temp[rr];
			rr++;
		}
	}
}

void BubbleSort(int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (!Cmp(pq[j], pq[j + 1]))
			{
				char c = pq[j + 1];
				pq[j + 1] = pq[j];
				pq[j] = c;
			}
		}
	}
}

int main()
{
	bool spaceFlag = false;
	string l;
	while (getline(cin, l))
	{
		//cout << l << endl;
		vector<pair<char, int>> pos;
		memset(pq, 0, sizeof(pq));
		int p = 0;
		for (int i = 0; i < l.length(); i++)
		{
			if ((l[i] >= 'a' && l[i] <= 'z') || (l[i] >= 'A' && l[i] <= 'Z'))
			{
				pq[p] = l[i];
				p++;
			}
			else pos.emplace_back(pair<char, int>(l[i], i));
		}
		//MergeSort(0, p - 1);
		BubbleSort(p);
		char temp[2018];
		memset(temp, 0, sizeof(temp));
		for (auto&& i : pos)
		{
			temp[i.second] = i.first;
		}
		int i = 0;
		for (int k = 0; k < p; k++)
		{
			while (temp[i] != 0) i++;
			temp[i] = pq[k];
		}
		for (int i = 0; i < 2018; i++)
		{
			if (temp[i] == 0) break;
			cout << temp[i];
		}
		cout << endl;
	}
	return 0;
}