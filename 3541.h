#pragma once
#include <iostream>
#include <climits>
using namespace std;
int N, M;
int u[2000];
int d[2000];

int search(int idx) {
	int start = 0;
	int end = N;
	int mid = (start + end) / 2;
	int ret = INT_MAX;
	while (start <= end) {

		mid = (start + end) / 2;
		int result = u[idx] * mid - d[idx] * (N - mid);
		
		if (result < 1)
			start = mid+1;
		else if (result > 1) {
			end = mid - 1;
			ret = min(result, ret);
		}
		else {
			break;
			ret = min(result, ret);
		}
	}
	return ret;
}


int main_3541() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> u[i];
		cin >> d[i];
	}
	int ret = INT_MAX;
	for(int i=0;i<M;i++)
		ret = min(ret, search(i));

	cout << ret << endl;

	return 0;
}
