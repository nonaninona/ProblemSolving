#include <iostream>
using namespace std;

int N;
int board[100][100];

int main_25595() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	int input;
	int x, y;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> input;
			board[i][j] = input;
			if (input == 2) {
				x = i;
				y = j;
			}
		}
	}

	bool isEven = (x + y) % 2 ? false : true;
	bool isClear = true;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			bool isEvenBox = (i + j) % 2 ? false : true;
			if (isEven == isEvenBox && board[i][j] == 1) {
				isClear = false;
				i = N;
				break;
			}
		}
	}

	if (isClear)
		cout << "Lena";
	else
		cout << "Kiriya";

	return 0;
}