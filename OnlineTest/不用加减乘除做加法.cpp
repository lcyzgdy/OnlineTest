class Solution {
public:
	int Add(int num1, int num2)
	{
		int sign = num1 & num2;
		int by = num1 ^ num2;
		while (sign)
		{
			int a = by;
			int b = sign << 1;
			sign = a & b;
			by = a ^ b;
		}
		return by;
	}
};