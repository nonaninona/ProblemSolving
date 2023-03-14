#include <iostream>
using namespace std;

int N, L;
int A[1000000];

int main_27496() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	cin >> L;
	int currentSum = 0;
	for (int i = 0; i < N; i++)
		cin >> A[i];

	int result = 0;
	for (int i = 0; i < N; i++) {
		currentSum += A[i];
		if (i >= L)
			currentSum -= A[i - L];

		if (129 <= currentSum && currentSum <= 138)
			result++;
	}

	cout << result << endl;

	return 0;
}