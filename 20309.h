#include <iostream>
using namespace std;

int N;
int A[300000];

int main_20309() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];

	bool isClear = true;
	for (int i = 0; i < N; i++) {
		if ((A[i] % 2) != ((i + 1) % 2)) {
			isClear = false;
			break;
		}
	}

	if (isClear)
		cout << "YES";
	else
		cout << "NO";

	return 0;
}