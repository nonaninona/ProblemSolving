#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
int P[100];
vector<int> V;

int main_27446() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	cin >> M;
	for (int i = 0; i < M; i++)
		cin >> P[i];

	sort(P, P + M);
	int j = 1;
	for (int i = 0; i < M; i++) {
		for (j; j < P[i]; j++)
			V.push_back(j);
		j = P[i]+1;
	}
	for (j; j < N + 1; j++)
		V.push_back(j);

	int s = V.size();
	int total = 0;
	for (int i = 0; i < s; i++) {
		if (i < 1) {
			total += 5 + 2;
			continue;
		}

		if (V[i] - V[i - 1] < 4)
			total += 2 * (V[i]-V[i-1]);
		else
			total += 5 + 2;
	}

	cout << total << endl;

	return 0;
}