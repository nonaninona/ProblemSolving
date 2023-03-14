#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>
#define tmax(a, b, c) max(a, max(b,c))
#define ll long long
using namespace std;

int N, M;
int house[2][100];
int chickenHouse[2][13];
int dist[100][13];	//i번째 집에서 j번째 치킨집까지의 거리

int main_15686() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	cin >> M;
	int input;
	int h = 0;
	int ch = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> input;
			if (input == 1) {
				house[0][h] = i;
				house[1][h] = j;
				h++;
			}
			else if (input == 2) {
				chickenHouse[0][ch] = i;
				chickenHouse[1][ch] = j;
				ch++;
			}
		}
	}

	for (int i = 0; i < h; i++)
		for (int j = 0; j < ch; j++)
			dist[i][j] = abs(house[0][i] - chickenHouse[0][j]) + abs(house[1][i] - chickenHouse[1][j]);





	return 0;
}