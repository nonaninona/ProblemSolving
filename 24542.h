#include <iostream>
#include <algorithm>
#include <vector>
#define MOD 1000000007
using namespace std;

int n, m;
vector<vector<int>> e;//e[i] -> i번째 학생과 연결된 모든 학생 목록을 담은 벡터
vector<bool> visited;//visited[i] -> i번째 학생 방문여부
vector<int> group = vector<int>();

void DFS(int i, int g) {
    if (visited[i])
        return;
    group[g]++;
    visited[i] = true;

    for (int j = 0; j < e[i].size(); j++)
        DFS(e[i][j], g);

    return;
}

int main_24542()
{
    cin >> n;
    e = vector<vector<int>>(n + 1, vector<int>());
    visited = vector<bool>(n + 1, false);
    cin >> m;

    int first, second;
    for (int i = 0; i < m; i++) {
        cin >> first;
        cin >> second;
        e[first].push_back(second);
        e[second].push_back(first);
    }

    int g = 0;
    for (int i = 1; i < n + 1; i++) {
        if (visited[i])
            continue;
        group.push_back(0);
        DFS(i, g);
        g++;
    }

    long long ret = 1;
    for (int i = 0; i < group.size(); i++) {
        ret *= group[i];
        ret %= MOD;
    }

    cout << ret << endl;

    return 0;
}
