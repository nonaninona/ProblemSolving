#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int w[100000];

int main_20044() {
	cin >> n;
	for (int i = 0; i < 2*n; i++)
		cin >> w[i];

	sort(w, w + 2 * n);

	int minimum = 200001;
	for (int i = 0; i < n; i++) {
		int sum = w[i] + w[2 * n - 1 - i];
		minimum = min(minimum, sum);
	}
	
	cout << minimum << endl;

	return 0;
}