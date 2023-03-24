#include <iostream>
#include <climits>
#include <algorithm>
#include <queue>
using namespace std;

int N, L;
deque< pair<int, int> > D;

int main_11003() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    cin >> N;
    cin >> L;
    int input;
    int min_val = INT_MAX;
    for(int i=0;i<N;i++){
        cin >> input;
        pair<int, int> p = pair<int,int> (input, i);
        if(D.empty()){
            D.push_back(p);
            min_val = p.first;
            cout << min_val << " ";
            continue;
        }
        
        pair<int, int> b = D.back();
        if(b.first <= p.first){
            D.push_back(p);
        } else {
            while(b.first > p.first){
                D.pop_back();
                if(D.empty())
                    break;
                b = D.back();
            }
            D.push_back(p);
        }

        pair<int, int> f = D.front();
        if(f.second <= i - L)
            D.pop_front();

        min_val = D.front().first;
        cout << min_val << " ";
    }
    cout << endl;

	return 0;
}