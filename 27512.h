#include <iostream>
using namespace std;

int n, m;

int main_27512() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	cin >> m;
	int result;
	if (n % 2 && m % 2)
		result = n * m - 1;
	else
		result = n * m;

	cout << result << endl;

	return 0;
}