#pragma once
#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
long long A[1000000];
long long B[1000000][3];

//ó������ value���� ũ�ų� ���� index ���� or ó������ value���� ū index ����
int getPos(int type, long long value, int from, int to) {
	int index = 0;
	//ó������ value���� ũ�ų� ���� ģ���� ������ index ����
	if (type == 0) {
		
		if (to < from) { //value�� �迭�� ���� ��
			if (to == -1)
				index = 0;
			else if (from == n)
				index = n;
			else
				index = (from + to) / 2 + 1;
		} 
		else { //value�� �迭�� �ְ� ã���� ��(value�� index = from �Ǵ� to)
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
	} else if(type == 1){ //ó������ value ���� ū ģ���� ������ index ����
		if (to < from) { //value�� �迭�� ���� ��
			if (to == -1)
				index = 0;
			else if (from == n)
				index = n;
			else
				index = (from + to) / 2 + 1;
		}
		else { //value�� �迭�� �ְ� ã���� ��(value�� index = from �Ǵ� to)
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


//����Ž�� ���� range�� 0-ũ�ų� ���� 1-ũ�� 2-�۰ų� ����
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

//Ÿ�Ժ��� ����Ž�� ������ ���� ���� ����
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

	//Ÿ�Կ� ���� index �˻��ؼ� ���� ���ϱ�
	//index �˻��� ����Ž�� �̿�
	for (int i = 0; i < m; i++)
		cout << typeSearch(B[i][0], B[i][1], B[i][2]) << endl;

	return 0;
}