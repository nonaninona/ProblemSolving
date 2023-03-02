#pragma once
#include <iostream>
using namespace std;

string str;
string bombStr;

int main_9935() {
	cin >> str;
	cin >> bombStr;

	int s = str.size();
	int j = 0;
	for (int i = 0; i < s; i++) {
		if (str[i] == bombStr[j]) {
			j++;
			if (j == bombStr.size()) {
				str.erase(i - j, j+1);
				i = i - j;
				s = str.size();

				int m = i - 1;
				int n, temp;
				if (m >= 0) {
					int n = bombStr.find(str[m]);
					temp = n;
				}
				else {
					j = 0;
					continue;
				}

				bool isCon = true;
				for (int k = m; k >= 0; k--) {
					if (n < 0)
						break;
					if (str[k] != bombStr[n]) {
						isCon = false;
						break;
					}
					n--;
				}
				if (n >= 0)
					isCon = false;

				if (isCon)
					j = temp;
			}
		}
	}

}