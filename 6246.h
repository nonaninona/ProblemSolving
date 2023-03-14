#include <iostream>
using namespace std;

int N, Q;
bool isSet[10000];

int main_6246() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	cin >> Q;
	fill_n(isSet, N, false);

	int start, dist;
	for(int i=0;i<Q;i++){
		cin >> start;
		cin >> dist;
		for (int j = start - 1; j < N; j += dist)
			isSet[j] = true;
	}

	int ret = 0;
	for (int i = 0; i < N; i++) {
		if (!isSet[i])
			ret++;
	}

	cout << ret;


	return 0;
}