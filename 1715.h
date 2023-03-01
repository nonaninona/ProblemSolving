#pragma once
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

int N;
int A[100000];


int main_1715() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];

	sort(A, A + N);

	ll ret = 0;
	ll currentDeck = 0;
	if (N == 1)
		ret = 0;
	else {
		ret = A[0] + A[1];
		currentDeck = ret;
	}

	for (int i = 2; i < N; i++) {
		currentDeck += A[i];
		ret += currentDeck;
	}

	cout << ret << endl;

	return 0;
}