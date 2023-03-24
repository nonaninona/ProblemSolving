#include <iostream>
#include <stack>
using namespace std;

string str;
stack<char> S;

int main_16120() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    cin >> str;
    int s = str.size();
    for(int i=0;i<s;i++){
        S.push(str[i]);
        if(S.size() >= 4){
            char a0 = S.top(); S.pop();
            char a1 = S.top(); S.pop();
            char a2 = S.top(); S.pop();
            char a3 = S.top(); S.pop();
            if(a3 == 'P'
            && a2 == 'P'
            && a1 == 'A'
            && a0 == 'P'){
                S.push('P');
            }
            else{
                S.push(a3);
                S.push(a2);
                S.push(a1);
                S.push(a0);
            }
        }
    }


    if(S.size() == 1 && S.top() == 'P')
        cout << "PPAP";
    else
        cout << "NP";


	return 0;
}