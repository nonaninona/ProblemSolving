#include <iostream>
#include <vector>
using namespace std;

int N, M;
string S;
char vowel[5] = { 'A', 'E', 'I', 'O', 'U' };
vector<char> V;

int main_27466() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
		
	cin >> N;
	cin >> M;
	cin >> S;

	int s = S.size();
	int stage = 0;
	int aCount = 0;
	for (int i = s - 1; i >= 0; i--) {
		if (stage == 0) {
			bool isVowel = false;
			for (int j = 0; j < 5; j++) {
				if (S[i] == vowel[j]) {
					isVowel = true;
					break;
				}
			}
			if (!isVowel) {
				V.push_back(S[i]);
				stage++;
			}
		}
		else if (stage == 1) {
			if (S[i] == 'A') {
				V.push_back('A');
				aCount++;
			}
			if (aCount == 2)
				stage++;
		}
		else if (stage == 2) {
			if (V.size() < M)
				V.push_back(S[i]);
			else
				break;
		}
	}

	if (V.size() < M) {
		cout << "NO" << '\n';
		return 0;
	}

	cout << "YES" << '\n';
	for (int i = V.size() - 1; i >= 0; i--)
		cout << V[i];
	return 0;
}