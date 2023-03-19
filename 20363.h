#include <iostream>
using namespace std;

int X, Y;

int main_20363() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> X;
	cin >> Y;
	if (X < Y) {
		int temp = X;
		X = Y;
		Y = temp;
	}
	cout << X + Y / 10 + Y << '\n';

	return 0;
}