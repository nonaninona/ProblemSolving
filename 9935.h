#include <iostream>
#include <vector>
using namespace std;

string str;
string bombStr;
vector<char> V = vector<char>();

int main_9935() {
	cin >> str;
	cin >> bombStr;
	
	int s = str.size();
	for (int i = 0; i < s; i++) {
		V.push_back(str[i]);
		if (V.size() >= bombStr.size()) {
			bool erase = true;
			for (int j = 0; j < bombStr.size(); j++) {
				if (V[V.size() - bombStr.size() + j] != bombStr[j]) {
					erase = false;
					break;

				}
			}
			if (erase) {
				for (int i = 0; i < bombStr.size(); i++)
					V.pop_back();
			}
		}
	}

	if (V.size() == 0) {
		cout << "FRULA" << endl;
		return 0;
	}

	for (int i = 0; i < V.size(); i++)
		cout << V[i];
	cout << endl;

	return 0;
}