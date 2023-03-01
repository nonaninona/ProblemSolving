#pragma once
#include <iostream>
using namespace std;

int main_23251() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int temp;
		cin >> temp;
		cout << temp * 23 << '\n';
	}
	return 0;
}