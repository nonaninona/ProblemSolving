#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>
#include <stack>
#include <list>
#define tmax(a, b, c) max(a, max(b,c))
#define ll long long
using namespace std;

int N, K;
int L[100000];

int binarySearch(int left, int right){
	int mid;
	while(left < right){
		mid = (left+right)/2;
		int sum = 0;
		for(int i=0;i<K;i++)
			sum += L[i]/mid;
		if(N < sum)
			left = mid+1;
		else
			right = mid;
	}

	return right;
}

int main_1654(){

	cin >> K;
	cin >> N;
	int MAXIMUM = INT_MIN;
	for(int i=0;i<K;i++){
		cin >> L[i];
		MAXIMUM = max(MAXIMUM, L[i]);
	}

	cout << binarySearch(1, MAXIMUM) << endl;
	



	return 0;
}