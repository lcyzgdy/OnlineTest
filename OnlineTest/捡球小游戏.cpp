#include<iostream>
#include<algorithm>
using namespace std;

struct Ball
{
	int n;
	int m;
} b[4];

int n1, n2, n3, n4;
int m1, m2, m3, m4;

int g[31][31][31][31];
int f[31][31][31][31];

int main()
{
	cin >> n1 >> n2 >> n3 >> n4;
	cin >> m1 >> m2 >> m3 >> m4;
	for (int a = 0; a <= n1; a++)
	{
		for (int b = 0; b <= n2; b++)
		{
			for (int c = 0; c <= n3; c++)
			{
				for (int d = 0; d <= n4; d++)
				{
					f[a][b][c][d] = max({ a - 1 < 0 ? 0 : (f[(a - 1 < 0 ? 0 : a - 1)][b][c][d] + ((a - 1)*m1 + b * m2 + c * m3 + d * m4) % 10 * m1),
						b - 1 < 0 ? 0 : (f[a][b - 1][c][d] + (a*m1 + (b - 1)*m2 + c * m3 + d * m4) % 10 * m2),
						c - 1 < 0 ? 0 : (f[a][b][c - 1][d] + (a*m1 + b * m2 + (c - 1) * m3 + d * m4) % 10 * m3),
						d - 1 < 0 ? 0 : (f[a][b][c][d - 1] + (a*m1 + b * m2 + c * m3 + (d - 1)*m4) % 10 * m4)
						});
				}
			}
		}
	}
	cout << f[n1][n2][n3][n4];
}