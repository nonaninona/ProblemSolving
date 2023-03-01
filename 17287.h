#pragma once
#include <iostream>
#include <climits>
using namespace std;

string str;

int main_17287() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> str;
	int multiple = 0;
	int maxV = INT_MIN;
	for (int i = 0; i < str.length(); i++) {
		char c = str[i];
		if (c == '(')
			multiple += 1;
		else if (c == ')')
			multiple -= 1;
		else if (c == '{')
			multiple += 2;
		else if (c == '}')
			multiple -= 2;
		else if (c == '[')
			multiple += 3;
		else if (c == ']')
			multiple -= 3;
		else
			if (maxV < multiple)
				maxV = multiple;

	}

	cout << maxV << endl;

	return 0;
}