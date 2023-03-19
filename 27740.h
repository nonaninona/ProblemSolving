#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>
#define tmax(a, b, c) max(a, max(b,c))
#define ll long long
using namespace std;

int N;
int A[300'000];

int main_27740() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];

	int leftLen = 0;
	int rightLen = 0;
	for (int i = 0; i < N / 2; i++) {
		if (A[i] == 1)
			leftLen = (i + 1);
		int j = N - 1 - i;
		if (A[j] == 1)
			rightLen = (i + 1);
	}



	return 0;
}