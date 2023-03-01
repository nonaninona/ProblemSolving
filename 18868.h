#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>
#define tmax(a, b, c) max(a, max(b,c))
#define ll long long
using namespace std;

int M, N;
int P[10][100];
bool isEquivalent = true;
int total = 0;

int main_18868() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> M;
	cin >> N;
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			cin >> P[i][j];

	for (int i = 0; i < M; i++) {
		for (int j = i + 1; j < M; j++) {
			//i, j -> 비교하는 우주
			isEquivalent = true;
			for (int m = 0; m < N; m++) {
				for (int n = m+1; n < N; n++) {
					//m, n -> 비교하는 행성
					bool result = 
						(P[i][m] > P[i][n] && P[j][m] > P[j][n]) ||
						(P[i][m] == P[i][n] && P[j][m] == P[j][n]) ||
						(P[i][m] < P[i][n] && P[j][m] < P[j][n]);
					if (!result) {
						isEquivalent = false;
						m = N;
						break;
					}
				}
			}
			if (isEquivalent)
				total++;
		}
	}

	cout << total << endl;

	return 0;
}