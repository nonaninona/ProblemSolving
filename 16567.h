#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int N;
int M;
int hall[1000000] = { 0, };
int wipe;

void flip(int point) {
	if (hall[point] == 1)
		return;
	hall[point] = 1;

	int count;
	if (point == 0)
		count = hall[point + 1];
	else if (point == N - 1)
		count = hall[point - 1];
	else
		count = hall[point - 1] + hall[point + 1];

	if (count == 0)
		wipe++;
	else if (count == 2)
		wipe--;

	return;
}

int main_16567() {

	wipe = 0;
	scanf("%d", &N);
	scanf("%d", &M);
	int input;
	int previous = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d", &input);
		hall[i] = input;

		if (input == 1 && previous == 0)
			wipe++;
		previous = input;
	}
	for (int i = 0; i < M; i++) {
		scanf("%d", &input);
		if (input == 0) {
			printf("%d\n", wipe);
		}
		else if (input == 1) {
			scanf("%d", &input);
			flip(input-1);
		}
	}

	return 0;
}