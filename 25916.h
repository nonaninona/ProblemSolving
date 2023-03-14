#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

int N, M;
int A[500'000];
ll S[500'001];	//S[i] = A[0] ~ A[i-1]까지의 합

int main_25916() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	cin >> M;
	S[0] = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		S[i + 1] = A[i] + S[i];
	}

	ll MAX_COVERING_VOLUME = 0;
	
	int e = 1;
	for (int s = 0; s < N; s++) {
		while (S[e] - S[s] <= M) {
			MAX_COVERING_VOLUME = max(MAX_COVERING_VOLUME, S[e] - S[s]);
			if (e >= N)
				break; 
			if(e < N)
				e++;
		}
	}

	cout << MAX_COVERING_VOLUME;
	

	return 0;
}