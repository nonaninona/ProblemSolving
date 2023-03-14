#include <iostream>
#define ll long long
#define MOD 1000000007
using namespace std;

int N;
ll dp[100000 / 2+1];

int main_17358() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	dp[0] = 1;

	for (int i = 1; i < N/2; i++) {
		int cur = (i + 1) * 2;
		dp[i] = (dp[i - 1] * (cur - 1)) % MOD;
	}

	cout << dp[(N - 1) / 2] << endl;


	return 0;
}