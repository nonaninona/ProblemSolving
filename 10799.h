#include <iostream>
#include <stack>
using namespace std;

string str;
stack<char> S;

int main_10799() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    cin >> str;
    int s = str.size();
    int stickCount = 0;
    int total = 0;
    for(int i=0;i<s;i++){
        if(S.empty()){
            S.push(str[i]);
            stickCount++;
            continue;
        }
        char t = S.top();
        if(t == '(' && str[i] == ')'){
            stickCount--;
            S.pop();
            if(str[i-1] == '(')
                total += stickCount;
            else
                total++;
        } else {
            S.push(str[i]);
            stickCount++;
        }
    }

    cout << total << endl;

	return 0;
}