#include <iostream>
#include <queue>
using namespace std;

struct compare {
	bool operator()(pair<int, int>& a, pair<int, int>& b) {
		return a.first < b.first;
	}
};

int N, K;
int result[300000];
priority_queue<pair<int, int>, vector<pair<int, int>>, compare> Q;
vector<pair<int, int>> temp;

int main_20311() {
	cin >> N;
	cin >> K;
	for (int i = 0; i < K; i++) {
		int val;
		cin >> val;
		Q.push(pair<int, int>(val, i));
	}

	bool canBeCompleted = true;
	for (int i = 0; i < N; i++) {
		if (Q.empty()) {
			canBeCompleted = false;
			break;
		}
		pair<int, int> p = Q.top();
		Q.pop();
		int val = p.first;
		int idx = p.second;
		result[i] = idx + 1;
		val--;
		if (!temp.empty()) {
			Q.push(temp[0]);
			temp.pop_back();
		}
		if(val > 0)
			temp.push_back(pair<int, int>(val, idx));
	}
	if (!canBeCompleted) {
		cout << -1 << endl;
		return 0;
	}
	
	for (int i = 0; i < N; i++)
		cout << result[i] << " ";
	cout << endl;

	return 0;
}