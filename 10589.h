#pragma once
#include <iostream>
#include <algorithm>
using namespace std;

int n, m;

int main_10589() {
	cin >> n;
	cin >> m;

	int lastN = n - (n % 2);
	int lastM = m - (m % 2);

	cout << n / 2 + m / 2 << endl;


	for(int i=1;i<n+1;i++){
		if (i % 2 == 1)
			continue;
		cout << i << " " << 1 << " " << i << " " << m << endl;
	}
	for (int i = 1; i < m + 1; i++) {
		if (i % 2 == 1)
			continue;
		cout << 1 << " " << i << " " << n << " " << i << endl;
	}

	return 0;
}