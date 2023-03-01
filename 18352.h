#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N, M, K, X;
bool visited[500000];
int from, to;
int dist[500000] = { 0 };
vector<int> answer;
vector<vector<int>> e;

int BFS() {
	int ret = 0;

	queue<int> q;
	q.push(X-1);
	dist[X-1] = 0;
	visited[X - 1] = true;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		if (dist[cur] > K)
			break;
		if (dist[cur] == K) {
			ret++;
			answer.push_back(cur);
		}

		vector<int> curV = e[cur];
		for (int i = 0; i < curV.size(); i++) {
			int dest = curV[i];
			if (!visited[dest]) {
				q.push(dest);
				visited[dest] = true;
				dist[dest] = dist[cur] + 1;
			}
		}
	}

	if (ret == 0) return -1;
	return ret;
}

int main_18352() {
	cin >> N;
	fill_n(visited, N, false);
	e = vector<vector<int>>(N, vector<int>(0));
	answer = vector<int>();
	cin >> M;
	cin >> K;
	cin >> X;
	for (int i = 0; i < M; i++) {
		cin >> from;
		cin >> to;
		e[from-1].push_back(to-1);
	}

	if (BFS() == -1) {
		cout << -1 << endl;
		return 0;
	}

	sort(answer.begin(), answer.end());

	for (int i = 0; i < answer.size(); i++)
		cout << answer[i]+1 << endl;

	return 0;
}