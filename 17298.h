#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int N;
int A[1'000'000];
stack<int> S;
vector<int> V;

int main_17298() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];

	for (int i = N - 1; i >= 0; i--) {
		if (S.empty()) {
			V.push_back(-1);
			S.push(A[i]);
		}
		else {
			int t = S.top();
			if (A[i] < t) {
				S.push(A[i]);
				V.push_back(t);
			}
			else {
				while (A[i] >= t) {
					S.pop();
					if (S.empty())
						break;
					t = S.top();
				}
				if (S.empty()) {
					V.push_back(-1);
					S.push(A[i]);
				}
				else {
					S.push(A[i]);
					V.push_back(t);
				}
			}
		}
	}
	
	int s = V.size();
	for (int i = s - 1; i >= 0; i--)
		cout << V[i] << " ";

	return 0;
}