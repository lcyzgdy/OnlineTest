#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
using namespace std;

string line;

enum State
{
	ReadDirection,
	ReadDistance,
	ReadEnd,
	Other
} state;

int main()
{
	while (getline(cin, line))
	{
		int dx, dy, dis;
		int rx, ry;
		rx = ry = 0;
		state = State::ReadDirection;
		for (int i = 0; i < line.length(); i++)
		{
			char c = line[i];
			switch (state)
			{
			case ReadDirection:
			{
				state = State::ReadDistance;
				if (c == 'W')
				{
					dx = 0; dy = 1;
				}
				else if (c == 'A')
				{
					dx = -1; dy = 0;
				}
				else if (c == 'S')
				{
					dx = 0; dy = -1;
				}
				else if (c == 'D')
				{
					dx = 1; dy = 0;
				}
				else if (c == ';')
				{
					state = State::ReadDirection;
				}
				else
				{
					state = State::Other;
				}
				dis = 0;
				break;
			}
			case ReadDistance:
			{
				if (c == ';')
				{
					state = State::ReadEnd;
				}
				else if (!(c >= '0' && c <= '9'))
				{
					state = State::Other;
				}
				else
				{
					dis = dis * 10 + (c - '0');
				}
				break;
			}
			case ReadEnd:
			{
				i--;
				rx += dis * dx;
				ry += dis * dy;
				state = State::ReadDirection;
				dis = 0;
				break;
			}
			case Other:
			{
				dis = 0;
				if (c == ';') state = State::ReadDirection;
				break;
			}
			default:
				break;
			}
		}
		rx += dis * dx;
		ry += dis * dy;
		cout << rx << ',' << ry << endl;
	}
	return 0;
}