#pragma once
#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;
int T, N;
string G[32];

int calcDist(string s1, string s2, string s3) {
	int dist = 0;
	for (int i = 0; i < 4; i++)
		if (s1[i] != s2[i])
			dist++;

	for (int i = 0; i < 4; i++)
		if (s2[i] != s3[i])
			dist++;

	for (int i = 0; i < 4; i++)
		if (s3[i] != s1[i])
			dist++;

	return dist;
}

int main_20529() {
	cin >> T;
	string temp;
	for (int a = 0; a < T; a++) {
		cin >> N;
		if (N > 32) {
			for (int i = 0; i < N; i++)
				cin >> temp;
			cout << 0 << endl;
			continue;
		}

		for (int i = 0; i < N; i++) {
			cin >> temp;
			G[i] = temp;
		}
		int minimum = INT_MAX;
		for (int i = 0; i < N; i++)
			for (int j = i + 1; j < N; j++)
				for (int k = j + 1; k < N; k++)
					minimum = min(minimum, calcDist(G[i], G[j], G[k]));
		cout << minimum << endl;
	}
	return 0;
}