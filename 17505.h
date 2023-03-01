#pragma once
#include <iostream>
#define ll long long
using namespace std;
int N;
ll K;
int A[314159];

void p(int from) {
	if (K >= N) {
		A[from] = N;
		N--;
		K = K - N;
		from++;
		p(from); 
	}
	else {
		int number = 1;
		for (int i = 0; i < N; i++) {
			if (i == N - 1 - K) {
				A[i+from] = N;
				continue;
			}
			A[i+from] = number;
			number++;
		}
	}
}

int main_17505() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	int initialN = N;
	cin >> K;
	
	p(0);

	for (int i = 0; i < initialN; i++)
		cout << A[i] << " ";

	return 0;
}