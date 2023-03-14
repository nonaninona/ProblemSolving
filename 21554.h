#include <iostream>
using namespace std;

int N;
int A[100];
int R[2][100];
int swapCount = 0;

void swap(int left, int right) {
	int temp[100];
	for (int i = left; i < right + 1; i++)
		temp[i] = A[i];

	for (int i = 0; i < right - left + 1; i++)
		A[right - i] = temp[left + i];

	R[0][swapCount] = left+1;
	R[1][swapCount] = right+1;
	swapCount++;
}

bool isSorted() {
	bool result = true;
	for (int i = 0; i < N; i++) {
		if (A[i] != i + 1) {
			result = false;
			break;
		}
	}

	return result;
}

int main_21554() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];

	int count = 0;
	bool canbeSorted = true;
	for (int i = 0; i < N; i++) {
		if (A[i] != i + 1) {
			for (int j = i + 1; j < N; j++)
				if (A[j] == i + 1) {
					swap(i, j);
					count++;
				}
		}
		if (isSorted())
			break;
		if (count > 100) {
			canbeSorted = false;
			break;
		}
	}

	if (!canbeSorted) {
		cout << -1 << endl;
		return 0;
	}

	cout << count << endl;
	for (int i = 0; i < count; i++)
		cout << R[0][i] << " " << R[1][i] << endl;

	return 0;
}