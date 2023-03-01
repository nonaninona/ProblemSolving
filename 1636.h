#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
int N;
int S[100000], E[100000];
int firstS, firstE;
vector<int> path = vector<int>();
vector<int> minPath = vector<int>();

int main_1636() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	scanf("%d", &N);
	scanf("%d", &firstS);
	scanf("%d", &firstE);
	for (int i = 0; i < N - 1; i++) {
		scanf("%d", &S[i]);
		scanf("%d", &E[i]);
	}
	int minimum = INT_MAX;
	int pos;
	for (int j = firstS; j < firstE + 1; j++) {
		int ret = 0;
		pos = j;
		path.push_back(pos);
		for (int i = 0; i < N-1; i++) {
			if (S[i] <= pos && pos <= E[i]) {
				path.push_back(pos);
				continue;
			}
			
			int a = abs(S[i] - pos);
			int b = abs(E[i] - pos);
			if (b < a) {
				ret += b;
				pos = E[i];
				path.push_back(pos);
			}
			else {
				ret += a;
				pos = S[i];
				path.push_back(pos);
			}
		}
		if (ret < minimum) {
			minimum = ret;
			minPath.clear();
			minPath.assign(path.begin(), path.end());
		}
		path.clear();
	}

	cout << minimum << endl;
	for (int i = 0; i < minPath.size(); i++)
		printf("%d\n", minPath[i]);
	

	return 0;
}