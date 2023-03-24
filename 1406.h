#include <iostream>
#include <queue>
using namespace std;

deque<char> D;
string str;
int M;

int main_1406() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    cin >> str;
    int s = str.size();
    for(int i=0;i<s;i++)
        D.push_back(str[i]);
    cin >> M;
    D.push_front('.');

    for(int i=0;i<M;i++){
        char command;
        cin >> command;
        if(command =='L'){
            if(D.back() != '.'){
                D.push_front(D.back());
                D.pop_back();
            }
        }else if(command == 'D'){
            if(D.front() != '.'){
                D.push_back(D.front());
                D.pop_front();
            }
        }else if(command == 'B'){
            if(D.back() != '.'){
                D.pop_back();
            }
        }else if(command == 'P'){
            char c;
            cin >> c;
            D.push_back(c);
        }
    }

    s = D.size();
    int cursorPos = -1;
    for(int i=0;i<s;i++){
        if(D[i] == '.'){
            cursorPos = i;
            break;
        }
    }
    for(int i=cursorPos+1;i<s;i++)
        cout << D[i];
    for(int i = 0;i<cursorPos;i++)
        cout << D[i];
    cout << endl;

	return 0;
}