#pragma once
#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int N, K;
int C[300000];

int main_20311() {
	cin >> N;
	cin >> K;
	int MAX = INT_MIN;
	int MAX_INDEX = -1;
	int SECOND_MAX = INT_MIN;
	int SECOND_MAX_INDEX = -1;

	for (int i = 0; i < K; i++) {
		cin >> C[i];
		if (SECOND_MAX > C[i]) {
			SECOND_MAX = C[i];
			if (MAX > SECOND_MAX) {
				int temp;
				temp = MAX;
				MAX = SECOND_MAX;
				SECOND_MAX = temp;
			}
		}
	}
	


	return 0;
}