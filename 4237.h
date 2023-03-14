#include <iostream>
using namespace std;

int T, N;
int A[30'000];
int B[29'999];

int main_4237() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		int previous;
		for (int j = 0; j < N; j++) {
			cin >> A[j];

			if (j != 0) {
				if (previous > A[j])
					B[j - 1] = 0;
				else if (previous < A[j])
					B[j - 1] = 1;
				previous = A[j];
			}
			else {
				previous = A[j];
			}
		}
		int length = 0;
		int previousCmp = 1;
		for (int j = 0; j < N - 1; j++) {
			if (previousCmp != B[j]) {
				length++;
				previousCmp = !previousCmp;
			}
		}
		cout << length+1 << '\n';
	}

	return 0;
}