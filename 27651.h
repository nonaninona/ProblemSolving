#include <iostream>
#define ll long long
using namespace std;

int N;
int A[100000];
ll S[100001];

int bSearch(ll head, int left, int right) {
	int mid = (left + right) / 2;
	if (left >= right)
		return mid;
	ll chest = S[mid] - head;
	ll belly = S[N] - S[mid];
	if (chest <= belly)
		return bSearch(head, mid + 1, right);
	else
		return bSearch(head, left, mid);
}

int bSearch2(ll head, int left, int right) {
	int mid = (left + right) / 2;
	if (left >= right)
		return mid;
	ll belly = S[N] - S[mid];
	if (belly <= head)
		return bSearch2(head, left, mid);
	else
		return bSearch2(head, mid + 1, right);
}
 
int main_27651() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	S[0] = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		S[i + 1] = S[i] + A[i];
	}

	ll total = 0;
	for (int i = 1; i < N - 1; i++) {
		ll head = S[i];
		int bellyStart = bSearch(S[i], i, N);
		int bellyEnd = bSearch2(S[i], i, N);
		if(bellyEnd - bellyStart > 0)
			total += bellyEnd - bellyStart;
	}

	cout << total << endl;

	return 0;
}