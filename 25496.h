#include <iostream>
#include <algorithm>
using namespace std;

int P, N;
int A[1000];

int main_25496() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> P;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];

	sort(A, A + N);

	int total = 0;
	for (int i = 0; i < N; i++) {
		if (P >= 200)
			break;
		P += A[i];
		total++;
	}

	cout << total << endl;


	return 0;
}