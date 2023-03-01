#pragma once
#include <iostream>
#include <vector>
using namespace std;

int n;
char type[1000];
int cost[1000];
vector<vector<int>> e;
bool visited[1000];

bool DFS(int room, int money) {
	if (visited[room])
		return false;

	if (type[room] =='L') {
		if (money < cost[room])
			money = cost[room];
	}
	else if (type[room] == 'T') {
		if (money >= cost[room])
			money -= cost[room];
		else
			return false;
	}
	visited[room] = true;
	if (room == n - 1)
		return true;
	int s = e[room].size();
	for (int i = 0; i < s; i++)
		if (DFS(e[room][i], money))
			return true;

	return false;
}

int main_2310() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	while (1) {
		cin >> n;
		if (n == 0)
			break;
		fill_n(visited, n, false);
		e = vector<vector<int>>(n, vector<int>());
		for (int i = 0; i < n; i++) {
			cin >> type[i];
			cin >> cost[i];
			while (1) {
				int temp;
				cin >> temp;
				if (temp == 0)
					break;
				temp--;
				e[i].push_back(temp);
			}
		}
		bool result = DFS(0, 0);
		if (result)
			cout << "Yes" << "\n";
		else
			cout << "No" << "\n";

		for (int i = 0; i < n; i++)
			e[i].clear();
		e.clear();
	}

	return 0;
}