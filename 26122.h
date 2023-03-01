#pragma once
#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;
int K;
char Kstr[300000];

int main_26122() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> K;
	for (int i = 0; i < K; i++)
		cin >> Kstr[i];

	int previousStreak = 0;
	int currentStreak = 0;
	char currentChar = Kstr[0];
	int maximum = INT_MIN;
	for (int i = 0; i < K; i++) {
		if (Kstr[i] != currentChar) {
			maximum = max( maximum, min(previousStreak, currentStreak) * 2);
			previousStreak = currentStreak;
			currentStreak = 1;
			currentChar = Kstr[i];
		}
		else {
			currentStreak++;
		}
	}
	maximum = max(maximum, min(previousStreak, currentStreak) * 2);

	cout << maximum << endl;

	return 0;
}