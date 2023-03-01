#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N;
int A[500000];
int L[500000];

bool compare(pair<int, int> F, pair <int, int> S) {
	return F.first < S.first;
}

int main_25972() {
	cin >> N;
	vector<pair<int, int>> v;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		cin >> L[i];
		v.push_back(pair<int, int>(A[i], L[i]));
	}
	sort(v.begin(), v.end(), compare);

	int ret = 0;
	int to = 0;
	for (int i = 0; i < N; i++) {
		if (v[i].first > to)
			ret++;

		to = v[i].first + v[i].second;
	}

	cout << ret << endl;
	return 0;
}