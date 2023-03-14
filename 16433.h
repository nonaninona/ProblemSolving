#include <iostream>
using namespace std;

int N, R, C;

int main_16433() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	cin >> R;
	cin >> C;

	bool isEven = (R + C) % 2 ? false : true;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			bool isEvenBox = (i + j) % 2 ? false : true;
			if (isEven == isEvenBox) cout << 'v';
			else cout << '.';
		}
		cout << '\n';
	}

	return 0;
}