#include <iostream>
#include <algorithm>
using namespace std;

int N;
int A[1000];
bool visited[1000];

bool isVisited() {
	bool result = true;
	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			result = false;
			break;
		}
	}
	return result;
}

int main_25631() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	int input;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	sort(A, A + N);
	fill_n(visited, 1000, false);

	int result = 0;
	while (!isVisited()) {
		int previous = -1;
		for (int i = 0; i < N; i++) {
			if (!visited[i]) {
				if (previous == -1)
					previous = i;
				else {
					if (A[previous] < A[i]) {
						visited[previous] = true;
						previous = i;
					}
				}
			}
		}
		visited[previous] = true;
		result++;
	}


	cout << result << endl;

	return 0;
}