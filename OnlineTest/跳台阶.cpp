#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
	int jumpFloor(int number) {
		int a[40] = { 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811, 514229, 832040, 1346269, 2178309, 3524578, 5702887, 9227465, 14930352, 24157817, 39088169, 63245986 };
		return a[number];
	}
};

int main()
{
	int n;
	cin >> n;
	Solution a;
	cout << a.jumpFloor(n) << endl;
	return 0;
}