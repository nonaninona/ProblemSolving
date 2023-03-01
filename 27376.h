#pragma once
#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
using namespace std;

int n, k;
vector<tuple<int, int, int>> s = vector<tuple<int, int, int>>();

bool compare(tuple<int, int, int> a, tuple<int, int, int> b) {
	return get<0>(a) < get<0>(b);
}

int main_27376() {
	cin >> n;
	cin >> k;

	for (int i = 0; i < k; i++) {
		int a, b, c;
		cin >> a;
		cin >> b;
		cin >> c;
		s.push_back(tuple<int, int, int>(a, b, c));
	}

	sort(s.begin(), s.end(), compare);

	int pos = 0;
	long long time = 0;
	for(int i =0;i<s.size();i++){
		tuple<int, int, int> curS = s[i];
		int p = get<0>(curS);
		int delay = get<1>(curS);
		int start = get<2>(curS);
		
		time += (p - pos);
		pos = p;

		if (time < start)
			time = start;
		bool isGreen = (((time - start) / delay) % 2 == 0);
		if (!isGreen) 
			time += (delay - ((time - start) % delay));
	}

	time += (n - pos);
	cout << time << endl;

	return 0;
}