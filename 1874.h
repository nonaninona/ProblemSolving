#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>
#include <stack>
#define tmax(a, b, c) max(a, max(b,c))
#define ll long long
using namespace std;

int N;
int A[100'000];
stack<int> S;
vector<char> V;

int main_1874() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];

	int cur = 1;
	for (int i = 0; i < N; i++) {
		if (S.empty()) {
			S.push(cur);
			V.push_back('+');
			cur++;
		}
		int t = S.top();
		
		while (t < A[i]) {
			S.push(cur);
			cur++;
			V.push_back('+');
		}
		if (t == A[i]) {
			S.pop();
			V.push_back('-');
		}
	}



	return 0;
}