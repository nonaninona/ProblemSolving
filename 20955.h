#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<vector<int>> E;
bool visited[100000];
int groupCount = 0;
int root[100000];
int depth[100000];
int cycleEdgeCount = 0;

void DFS(int n, bool isFirstAccess) {
	if (visited[n])
		return;

	visited[n] = true;
	int s = E[n].size();
	for (int i = 0; i < s; i++)
		DFS(E[n][i], false);

	if (isFirstAccess)
		groupCount++;

	return;
}

int unionSet() {
	for (int i = 0; i < N; i++) {
		root[i] = i;
		depth[i] = 1;
	}

	return 0;
}

int unionFind(int n) {
	if (root[n] == n)
		return n;
	else
		return root[n] = unionFind(root[n]);
}

int unionOperation(int a, int b) {
	int x = unionFind(a);
	int y = unionFind(b);

	if (x == y)
		return 0;

	if (depth[x] > depth[y])
		root[y] = x;
	else if (depth[x] < depth[y])
		root[x] = y;
	else {
		depth[y]++;
		root[x] = y;
	}
	
	return 0;
}

int main_20955() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	scanf("%d", &N);
	fill_n(visited, N, false);
	scanf("%d", &M);
	E = vector<vector<int>>(N, vector<int>());

	unionSet();
	int a, b;
	for (int i = 0; i < M; i++) {
		scanf("%d", &a);
		a--;
		scanf("%d", &b);
		b--;
		if (unionFind(a) == unionFind(b))
			cycleEdgeCount++;
		else 
			unionOperation(a, b);

		E[a].push_back(b);
		E[b].push_back(a);
	}

	for (int i = 0; i < N; i++)
		DFS(i, true);

	printf("%d", groupCount - 1 + cycleEdgeCount);

	

	return 0;
}