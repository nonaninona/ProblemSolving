#include <iostream>
#include <climits>
using namespace std;

int N;

int main_2846() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	int input = -3;
	int previous = INT_MAX;
	bool isElevating = false;
	int start = 0;
	int end = 0;
	int MAXIMUM = INT_MIN;
	for (int i = 0; i < N; i++) {
		cin >> input;
		if (input > previous) {
			if (!isElevating) {
				start = previous;
				isElevating = true;
			}
			end = input;
		}
		else {
			isElevating = false;
			if (MAXIMUM < end - start)
				MAXIMUM = end - start;
		}
		previous = input;
	}

	if (MAXIMUM < end - start)
		MAXIMUM = end - start;
	cout << MAXIMUM << endl;

	return 0;
}