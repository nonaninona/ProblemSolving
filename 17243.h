#include <iostream>
#include <algorithm>
using namespace std;

int n, K;
int A[500];
int dp[501][501]; //dp[idx][K]

int DP(int idx, int k) {
	if (idx >= n || k > K)
		return 0;

	int &ret = dp[idx][k];
	if (ret != -1)
		return ret;

	
	int result = 1;
	for (int i = idx+1; i < n; i++) {
		if (A[idx] <= A[i])
			result = max(result, DP(i, k) + 1);
		else 
			result = max(result, DP(i, k+1) + 1);
	}
	ret = result;

	return result;
}

int main_17243() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	
	fill(&dp[0][0], &dp[500][501], -1);


	cin >> n;
	cin >> K;
	for (int i = 0; i < n; i++)
		cin >> A[i];

	cout << DP(0, 0);

	return 0;
}