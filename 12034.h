#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>
#define tmax(a, b, c) max(a, max(b,c))
#define ll long long
using namespace std;

int T, N;
int A[200];
bool checked[200];

int main_12034() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		fill_n(checked, N, false);
		for (int j = 0; j < 2 * N; j++)
			cin >> A[j];
		for(int j=0)
	}

	return 0;
}