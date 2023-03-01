#pragma once
#include <iostream>
#include <algorithm>
using namespace std;

int A, B, C, X, Y, Z;

int main_26070() {
	cin >> A;
	cin >> B;
	cin >> C;
	cin >> X;
	cin >> Y;
	cin >> Z;


	long long ret = 0;
	for (int i = 0; i < 3; i++) {
		int minimum = min(A, X);
		ret += minimum;
		X -= minimum;
		A -= minimum;

		minimum = min(B, Y);
		ret += minimum;
		Y -= minimum;
		B -= minimum;

		minimum = min(C, Z);
		ret += minimum;
		Z -= minimum;
		C -= minimum;

		int nY = X / 3 + Y % 3;
		int nZ = Y / 3 + Z % 3;
		int nX = Z / 3 + X % 3;
		X = nX;
		Y = nY;
		Z = nZ;
	}

	cout << ret << endl;

	return 0;
}