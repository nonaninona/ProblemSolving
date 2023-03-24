#include <iostream>
#include <math.h>
#define ll long long
using namespace std;

ll N;

ll binarySearch(ll left, ll right, ll v){
    ll mid;
    while(left < right){
        mid = (left+right)/2;
        if(mid * mid < N)
            left = mid + 1;
        else
            right = mid;
    }
    return right;
}


int main_2417(){

    cin >> N;
    ll end = 3037000500;
    cout << binarySearch(0LL, end, N) << endl;


	return 0;
}