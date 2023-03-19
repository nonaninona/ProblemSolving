#include <iostream>
#define ll long long
#define MOD 1'000'000'007
using namespace std;

int N;
string S;
ll DP[3][1'000'000] = { 0, }; //DP[k][idx] -> S[idx..N) 중에서 KCOR와 k개 일치하는 부분열의 개수 

ll squareTwo(int n) {
	ll total = 1;
	if (n < 30)
		return (total << n);

	if (n % 2)
		return ((squareTwo(n / 2) * squareTwo(n / 2) * 2) % MOD);
	else
		return ((squareTwo(n / 2) * squareTwo(n / 2)) % MOD);
}

int main_26156() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	cin >> S;

	DP[2][N - 1] = 0;
	DP[1][N - 1] = 0;
	if (S[N - 1] == 'K')
		DP[0][N - 1] = 1;
	else
		DP[0][N - 1] = 0;

	for (int i = N - 2; i >= 0; i--) {
		if (S[i] == 'K')
			DP[0][i] = ((DP[0][i + 1] + 1) % MOD);
		else 
			DP[0][i] = DP[0][i + 1];

		if (S[i] == 'C')
			DP[1][i] = ((DP[1][i + 1] + DP[0][i + 1]) % MOD);
		else
			DP[1][i] = DP[1][i + 1];

		if (S[i] == 'O')
			DP[2][i] = ((DP[2][i + 1] + DP[1][i + 1]) % MOD);                                                     
		else
			DP[2][i] = DP[2][i + 1];
	}

	
	ll total = 0;
	for (int i = N - 1; i >= 0; i--) {
		if (S[i] == 'R') {
			total += ((squareTwo(i) * DP[2][i]) % MOD);
			total %= MOD;
		}
	}

	cout << total << '\n';

	return 0;
}