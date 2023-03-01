#pragma once
#include <iostream>
#include <climits>

using namespace std;
int N;
int A[1000000];

int main_24498() {
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];

	int MAX = INT_MIN;
	for (int i = 1; i < N - 1; i++) {
		int consume = min(A[i - 1], A[i + 1]);
		if (consume + A[i] > MAX)
			MAX = consume + A[i];
	}
	if (A[0] > MAX)
		MAX = A[0];
	if (A[N - 1] > MAX)
		MAX = A[N - 1];

	cout << MAX << endl;

	return 0;
}