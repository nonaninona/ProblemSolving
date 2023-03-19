#include <iostream>
using namespace std;

int N, M;
int A[10'000];
int total = 0;

int main_2003() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	cin >> M;
	for (int i = 0; i < N; i++)
		cin >> A[i];

	int ret = 0;
	int start = 0;
	for (int i = 0; i < N; i++) {
		total += A[i];
		while (total > M) {
			total -= A[start];
			start++;
		}
		if (total == M)
			ret++;
	}

	cout << ret << '\n';

	return 0;
}