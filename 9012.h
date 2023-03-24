#include <iostream>
#include <stack>
using namespace std;

int T;
string str;
stack<char> S;

int main_9012() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    cin >> T;
    for(int i=0;i<T;i++){
        cin >> str;
        int s = str.size();
        for(int j=0;j<s;j++){
            if(S.empty()){
                S.push(str[j]);
                continue;
            }
            char t = S.top();
            if(t == '(' && str[j] == ')')
                S.pop();
            else
                S.push(str[j]);
        }
        
        if(S.empty())
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';

        while(!S.empty())
            S.pop();
    }

	return 0;
}