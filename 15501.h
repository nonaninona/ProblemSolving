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
int A[1000000];
int B[1000000];

int main_15501() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	int startA = 0;
	for (int i = 0; i < N; i++)
		cin >> A[i];

	int startB;
	for (int i = 0; i < N; i++) {
		cin >> B[i];
		if (A[startA] == B[i])
			startB = i;
	}

	int direction = (A[(startA + 1) % N] == B[(startB + 1) % N]) ? 1 : -1;
	bool isGood = true;
	while (true) {
		if (A[startA] != B[startB]) {
			isGood = false;
			break;
		}
		startA++;
		if (startA == N)
			break;
		startA%= N;
		startB += direction;
		if (startB < 0)
			startB += N;
		startB%= N;
	}

	if (isGood)
		cout << "good puzzle";
	else
		cout << "bad puzzle";

	return 0;
}