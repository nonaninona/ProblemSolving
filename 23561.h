#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int N;
int A[300000];

int main_23561() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < 3*N; i++)
		cin >> A[i];

	sort(A, A + 3*N);
	
	int MINIMUM = A[2 * N - 1] - A[N];

	cout << MINIMUM << endl;

	return 0;
}