#pragma once
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<vector<int>> books = vector<vector<int>>();
int bookAmount[200000];
int N, M;

bool isSorted(vector<int> v) {
	if (v.empty())
		return true;
	bool ret = true;
	int previous = INT_MAX;
	for (int i = 0; i < v.size(); i++) {
		if (previous < v[i]) {
			ret = false;
			break;
		}
		previous = v[i];
	}
	return ret;
}

int main_23253() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int input;
		cin >> input;
		bookAmount[i] = input;
		books.push_back(vector<int>());
		for (int j = 0; j < bookAmount[i]; j++) {
			cin >> input;
			books[i].push_back(input);
		}
	}
	
	bool isOk = true;

	for(int i = 0; i < M; i++) { //i는 책번호
		if (!isSorted(books[i])) {
			isOk = false;
			break;
		}
	}

	string answer = isOk ? "Yes" : "No";

	cout << answer << endl;

	return 0;
}