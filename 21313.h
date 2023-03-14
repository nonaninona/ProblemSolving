#include <iostream>
using namespace std;

int N;

int main_21313() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	int s = N - N % 2;
	bool isEven = N % 2 ? false : true;
	for (int i = 0; i < s ; i++)
		cout << i % 2 + 1 << " ";
	if (!isEven)
		cout << 3;

	return 0;
}