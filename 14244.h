#include <iostream>
using namespace std;

int N, M;

int main_14244() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	cin >> M;
	for (int i = 0; i < M-1; i++)
		cout << i << " " << M-1 << "\n";
	for (int i = M-1; i < N-1; i++)
		cout << i << " " << i + 1 << "\n";

	return 0;
}