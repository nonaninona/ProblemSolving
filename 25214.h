#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int N;
int A[200000];

int main_25214() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];

	int minVal = INT_MAX;
	int maxResult = 0;
	for (int i = 0; i < N; i++) {
		maxResult = max(maxResult, A[i] - minVal);
		minVal = min(minVal, A[i]);
		cout << maxResult << " ";
	}


	return 0;
}