#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int A[100000];

int binarySearch(int start, int end, int value){
	int left  = start;
	int right = end;
	int mid;
	while(left <= right){
		mid = (left+right)/2;
        if(value == A[mid])
            return 1;
		else if(value > A[mid])
			left = mid+1;
		else	
			right = mid-1;
	}
    return 0;
}

int main_1920() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for(int i=0;i<N;i++)
		cin >> A[i];
x`
    sort(A, A+N);

	cin >> M;
	int input;
	for(int i=0;i<M;i++){
		cin >> input;
		cout << binarySearch(0, N-1, input) << '\n';
	}


	return 0;
}