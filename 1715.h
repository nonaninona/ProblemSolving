#include <iostream>
#include <queue>
#define ll long long
using namespace std;

struct cmp {
	bool operator()(int a, int b) {
		return b < a;
	}
};
int N;
priority_queue<int, vector<int>, cmp> Q;



int main_1715() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		Q.push(temp);
	}

	ll ret = 0;
	
	if (N == 1) {
		cout << 0 << endl;
		return 0;
	}

	while (!Q.empty()) {
		int first = Q.top();
		Q.pop();
		int second = Q.top();
		Q.pop();
		int sum = first + second;
		ret += sum;
		if (Q.empty())
			break;
		Q.push(sum);
	}

	cout << ret << endl;

	return 0;
}