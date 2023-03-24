#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

int N, Q, k;
int input[2][100000];
deque<int> D;

int main_26086() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    
    cin >> N;
    cin >> Q;
    cin >> k;
    int lastSort = -1;
    for(int i=0;i<Q;i++){
        cin >> input[0][i];
        if(input[0][i] == 0)
            cin >> input[1][i];
        if(input[0][i] == 1)
            lastSort = i;
    }
    
    int command;
    int uniqueN;
    bool isForward = true;
    for(int i=0;i<Q;i++){
        command = input[0][i];
        if(command == 0){
            uniqueN = input[1][i];
            if(isForward)
                D.push_front(uniqueN);
            else
                D.push_back(uniqueN);
        }
        else if(command == 1){
            if(i == lastSort){
                if(isForward)
                    sort(D.begin(), D.end());
                else
                    sort(D.begin(), D.end(), greater<int>());
            }
        }
        else if(command == 2){
            isForward = !isForward;
        }
    }

    if(isForward)
        cout << D[k-1] << endl;
    else
        cout << D[D.size()-k] << endl;
    
	return 0;
}