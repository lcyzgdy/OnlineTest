#include<vector>
using namespace std;

class Solution {
public:
	vector<int> multiply(const vector<int>& A) {
		vector<int> B(A.size());
		int mul = 1;
		for (int i = 0; i < A.size(); mul *= A[i++])
		{
			B[i] = mul;
		}
		mul = 1;
		for (int i = A.size() - 1; i >= 0; mul *= A[i--])
		{
			B[i] *= mul;
		}
		return std::move(B);
	}
};