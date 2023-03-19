#include <iostream>
#include <stack>
#include <algorithm>
#include <climits>
using namespace std;

int N;
char A[200000];
stack<char> S;

int main_25918() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];

	int depth = 0;
	int MAX_DEPTH = INT_MIN;
	for (int i = 0; i < N; i++) {
		if (S.empty()) {
			S.push(A[i]);
			depth++;
			MAX_DEPTH = max(depth, MAX_DEPTH);
			continue;
		}
		int top = S.top();
		if (A[i] != top) {
			S.pop();
			depth--;
		}
		else {
			S.push(A[i]);
			depth++;
			MAX_DEPTH = max(depth, MAX_DEPTH);
		}
	}
	if (!S.empty()) {
		cout << -1 << endl;
		return 0;
	}
	cout << MAX_DEPTH << endl;



	return 0;
}