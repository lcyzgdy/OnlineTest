//#include<iostream>
//#include<cstring>
//#include<cmath>
//using namespace std;
//
//struct Vector2
//{
//	int x, y;
//};
//
//float Dis(int x, int y)
//{
//	return sqrt(x * x + y * y);
//}
//
//float Angle(int x1, int y1, int x2, int y2)
//{
//	//cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
//	return acosf((x1 * x2 + y1 * y2) / Dis(x1, y1) * Dis(x2, y2));
//}
//
//int main()
//{
//	int t;
//	cin >> t;
//	int x[4];
//	int y[4];
//	int vx[16];
//	int vy[16];
//	while (t--)
//	{
//		memset(x, 0, sizeof(x));
//		memset(y, 0, sizeof(y));
//		memset(vx, 0, sizeof(vx));
//		memset(vy, 0, sizeof(vy));
//		cin >> x[0] >> x[1] >> x[2] >> x[3];
//		cin >> y[0] >> y[1] >> y[2] >> y[3];
//		int p = 0;
//		for (int i = 0; i < 4; i++)
//		{
//			for (int j = i + 1; j < 4; j++)
//			{
//				vx[p] = x[i] - x[j];
//				vy[p++] = y[i] - y[j];
//			}
//		}
//		float mind = 2147483647;
//		for (int i = 0; i < p; i++)
//		{
//			if (mind > Dis(vx[i], vy[i]) && Dis(vx[i], vy[i]) > 0) mind = Dis(vx[i], vy[i]);
//		}
//		//cout << mind << endl;
//		int edgeCount = 0;
//		for (int i = 0; i < p; i++)
//		{
//			if (mind == Dis(vx[i], vy[i])) edgeCount++;
//		}
//		if (edgeCount != 4) { cout << "No" << endl; continue; }
//		float angle = 1.5708f;
//		for (int i = 0; i < p; i++)
//		{
//			if (Dis(vx[i], vy[i]) != mind) continue;
//			for (int j = i + 1; j < p; j++)
//			{
//				if (Dis(vx[j], vy[j]) != mind) continue;
//				if (Angle(vx[i], vy[i], vx[j], vy[j]) - angle >= 0.0001f) { cout << "No" << endl; goto lo; }
//			}
//		}
//		cout << "Yes" << endl;
//	lo:
//		continue;
//	}
//}