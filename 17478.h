#include <iostream>
#include <string>
using namespace std;

string S;

int main_17478() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	getline(cin, S);
	int s = S.size();
	int otherKey = 0;
	for (int i = 0; i < s; i++) {
		int cur = S[i];
		if ((41 <= cur && cur <= 90) || cur == ' ') {
			if(cur  != ' ')
				S[i] = cur + 32;
			otherKey++;
		}
	}
	int right = 0;
	int left = 0;
	for (int i = 0; i < s; i++) {
		int cur = S[i];
		if (cur == ' ')
			continue;
		switch (cur) {
		case 'u':
		case 'i':
		case 'o':
		case 'p':
		case 'h':
		case 'j':
		case 'k':
		case 'l':
		case 'n':
		case 'm': right++; break;
		default: left++; break;
		}
	}

	for (int i = 0; i < otherKey; i++) {
		if (left <= right)
			left++;
		else
			right++;
	}

	cout << left << " " << right << endl;

	return 0;
}