#pragma once
#include <iostream>
#include <vector>
using namespace std;

int N;
vector<string> S = vector<string>();

bool check(string s, char c) {
	if (s.front() == c && s.back() == c)
		return true;
	return false;
}

int main_20528() {
	cin >> N;
	string input;
	for (int i = 0; i < N; i++) {
		cin >> input;
		S.push_back(input);
	}
	input = S[0];
	char start = input.front();

	for (int i = 1; i < N; i++) {
		if (!check(S[i], start)) {
			cout << 0 << endl;
			return 0;
		}
	}

	cout << 1 << endl;
	return 0;
}