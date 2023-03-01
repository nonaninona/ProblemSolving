#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int N, X;
int curTime = -1;
int direction = 1;
string YesOrNo = "NO";
string S;

int main_27161() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> S;
		cin >> X;

		
		curTime += direction;
		curTime %= 12;
		if (curTime < 0)
			curTime += 12;
		
		if (S == "HOURGLASS" && (curTime + 1) != X) {
			direction *= -1;
			YesOrNo = "NO";
		}
		else if(S != "HOURGLASS" && (curTime+1) == X)
			YesOrNo = "YES";
		else
			YesOrNo = "NO";

		cout << (curTime+1) << " " << YesOrNo << endl;
	}

	return 0;
}