#pragma once
#include <iostream>
using namespace std;
int N;
char skill[200000];

int main_25497() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		char temp;
		cin >> temp;
		skill[i] = temp;
	}

	int L = 0;
	int S = 0;
	int count = 0;
	for (int i = 0; i < N; i++) {
		char current = skill[i];
		if (current == 'L')
			L++;
		else if (current == 'S')
			S++;
		else if (current == 'R') {
			if (L >= 1) {
				L--;
				count++;
			}
			else {
				break;
			}
		}
		else if (current == 'K') {
			if (S >= 1) {
				S--;
				count++;
			}
			else {
				break;
			}
		}
		else {
			count++;
		}
	}

	cout << count << endl;

	return 0;
}