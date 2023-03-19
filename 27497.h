#include <iostream>
#include <stack>
#include <list>
using namespace std;

int N;
list<char> L;
stack<int> S;//0이면 앞쪽 1이면 뒷쪽

int main_27497() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int input;
		char c;
		cin >> input;
		if (input == 1) {
			S.push(1);
			cin >> c;
			L.push_back(c);
		}
		else if (input == 2) {
			S.push(0);
			cin >> c;
			L.push_front(c);
		}
		else if (input == 3) {
			if (L.empty())
				continue;
			int previous = S.top();
			S.pop();
			if (previous == 0)
				L.pop_front();
			else if (previous == 1)
				L.pop_back();
		}
	}

	if (L.empty()) {
		cout << 0 << endl;
		return 0;
	}

	while (!L.empty()) {
		cout << L.front();
		L.pop_front();
	}

	return 0;
}