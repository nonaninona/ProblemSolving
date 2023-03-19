#include <iostream>
using namespace std;

int N;
int H[200000];
int DP[200000];

int main_25706() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> H[i];

	for (int i = N - 1; i >= 0; i--) {
		if (i + 1 + H[i] >= N)
			DP[i] = 1;
		else
			DP[i] = DP[i + H[i] + 1] + 1;
	}

	for (int i = 0; i < N; i++)
		cout << DP[i] << '\n';

	return 0;
}