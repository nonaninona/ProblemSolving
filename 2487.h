#pragma once
#include <iostream>
#include <vector>
using namespace std;

int n;
vector<pair<int, bool>> A = vector<pair<int, bool>>();
vector<int> N = vector<int>();


int Euclid(int a, int b) {
	if (a % b == 0)
		return b;
	return Euclid(b, a % b);
}


int main_2487() {
	cin >> n;
	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		A.push_back(pair<int, bool>(temp-1, false));
	}

	for (int i = 0; i < n; i++) {
		if (!A[i].second) {
			A[i].second = true;
			int j = i;
			int jump = 1;
			
			while (1) {
				A[j].second = true;
				if (A[j].first == i)
					break;
				j = A[j].first;
				jump++;
			}
			N.push_back(jump);
		}
	}

	long long ret = 1;
	for (int i = 0; i < N.size(); i++) {
		int d;
		if (ret > N[i])
			d = Euclid(ret, N[i]);
		else
			d = Euclid(N[i], ret);
		ret *= N[i];
		ret /= d;
	}


	cout << ret << endl;

	return 0;
}