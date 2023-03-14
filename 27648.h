#include <iostream>
using namespace std;

int N, M, K;

int main_27648() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	cin >> M;
	cin >> K;
	if (K < M + N - 1) {
		cout << "NO" << '\n';
		return 0;
	}

	cout << "YES" << '\n';
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < M + i + 1; j++)
			cout << j << " ";
		cout << '\n';
	}

	return 0;
}