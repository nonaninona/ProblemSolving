#pragma once
#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
long long A[1000000];
long long B[1000000][3];

//처음으로 value보다 크거나 같은 index 리턴 or 처음으로 value보다 큰 index 리턴
int getPos(int type, long long value, int from, int to) {
	int index = 0;
	//처음으로 value보다 크거나 같은 친구가 나오는 index 리턴
	if (type == 0) {
		
		if (to < from) { //value가 배열에 없을 때
			if (to == -1)
				index = 0;
			else if (from == n)
				index = n;
			else
				index = (from + to) / 2 + 1;
		} 
		else { //value가 배열에 있고 찾았을 때(value의 index = from 또는 to)
			index = (from + to) / 2;
			int start = index;
			for (int i = start; i >= 0; i--) {
				if (A[i] < A[start]) {
					index = i + 1;
					break;
				}
				index = i;
			}
		}
		return index;
	} else if(type == 1){ //처음으로 value 보다 큰 친구가 나오는 index 리턴
		if (to < from) { //value가 배열에 없을 때
			if (to == -1)
				index = 0;
			else if (from == n)
				index = n;
			else
				index = (from + to) / 2 + 1;
		}
		else { //value가 배열에 있고 찾았을 때(value의 index = from 또는 to)
			index = (from + to) / 2;
			int start = index;
			for (int i = start; i < n; i++) {
				if (A[i] > A[start]) {
					index = i;
					break;
				}
				index = i + 1;
			}
		}
		return index;
	}
}


//이진탐색 돌림 range는 0-크거나 같다 1-크다 2-작거나 같다
int search(int from, int to, long long value, int type) {
	int mid = (from + to) / 2;
	int midValue = A[mid];
	if (midValue == value || to < from)
		return getPos(type, value, from, to);
	else if (midValue < value)
		return search(mid + 1, to, value, type);
	else if (midValue > value)
		return search(from, mid - 1, value, type);
}

//타입별로 이진탐색 돌려서 개수 구해 리턴
int typeSearch(int type, long long value1, long long value2) {
	if (type == 1)
		return n - search(0, n-1, value1, 0);
	else if (type == 2)
		return n - search(0, n-1, value1, 1);
	else if (type == 3)
		return search(0, n - 1, value2, 1) - search(0, n-1, value1, 0);
}

int main_26168() {
	cin >> n;
	cin >> m;
	for (int i = 0; i < n; i++)
		cin >> A[i];
	for (int i = 0; i < m; i++) {
		cin >> B[i][0];
		cin >> B[i][1];
		if (B[i][0] == 3)
			cin >> B[i][2];
	}


	sort(A, A + n);

	//타입에 따라 index 검색해서 개수 구하기
	//index 검색시 이진탐색 이용
	for (int i = 0; i < m; i++)
		cout << typeSearch(B[i][0], B[i][1], B[i][2]) << endl;

	return 0;
}