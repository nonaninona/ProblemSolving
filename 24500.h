#include <iostream>
#define ll long long
using namespace std;

ll N;

int main_24500() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;

	ll total = 1;
	while (total <= N)
		total *= 2;
	if (total - 1 == N) {
		cout << 1 << '\n' << N << '\n';
		return 0;
	}

	total /= 2;
	ll k = N - total;
	cout << 2 << '\n' << total - k - 1 << '\n' << N << '\n';

	return 0;
}