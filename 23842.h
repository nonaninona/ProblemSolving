#pragma once
#include <iostream>
using namespace std;
int amount[10] = {6, 2, 5, 5, 4, 5, 6 , 3 ,7, 6};
int getAmount(int x) {
	return amount[x / 10] + amount[x % 10];
}
int N;

int main_23842() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;

	for (int i = 0; i < 99; i++) {
		for (int j = 0; j < 99; j++) {
			if (i + j < 100 && getAmount(i)+getAmount(j)+getAmount(i+j) == N-4) {
				cout << i / 10 << i % 10 << "+" << j / 10 << j % 10 << "=" << (i + j) / 10 << (i + j) % 10 << endl;
				return 0;
			}
		}
	}

	cout << "impossible" << endl;

	return 0;
}