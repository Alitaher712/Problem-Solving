#include<iostream>
using namespace std;
int A[8][8];
int R[8][8];
int B[9];
int cnt = 0;

bool checkSatis(int x, int y, int k) {
	int count = 1;
	for (int i = 0; i < 8; i++) 
	{
		if (A[x][i] == k || A[i][y] == k)
			return false;
	}
	int a = x / 4, b = y / 4;
	for (int i = a * 4; i < a * 4 + 4; i++)
		for (int j = b * 4; j < b * 4 + 4; j++)
			if (A[i][j] == k)
				count++;

	if (count > 2)
	{
		return false;
	}
	return true;
}
void resetMatric() {
	for (int i = 0; i < 9; i++)
		B[i] = 0;
}
bool checkMatric() {
	bool ans = true;
	for (int i = 0; i < 8; i++) {//row
		resetMatric();
		for (int j = 0; j < 8; j++) {
			if (A[i][j] > 0) {
				B[A[i][j]]++;
				if (B[A[i][j]] > 1) {
					return false;
				}
			}
		}
	}
	for (int i = 0; i < 8; i++) {//col
		resetMatric();
		for (int j = 0; j < 8; j++) {
			if (A[j][i] > 0) {
				B[A[j][i]]++;
				if (B[A[j][i]] > 1)
					return false;
			}
		}
	}
	resetMatric();
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (A[i][j] > 0) {
				B[A[i][j]]++;
				if (B[A[j][i]] > 2)
					return false;
			}
	resetMatric();
	for (int i = 0; i < 4; i++)
		for (int j = 4; j < 8; j++)
			if (A[i][j] > 0) {
				B[A[i][j]]++;
				if (B[A[j][i]] > 2)
					return false;
			}
	resetMatric();
	for (int i = 4; i < 8; i++)
		for (int j = 0; j < 4; j++)
			if (A[i][j] > 0) {
				B[A[i][j]]++;
				if (B[A[j][i]] > 2)
					return false;
			}
	resetMatric();
	for (int i = 4; i < 8; i++)
		for (int j = 4; j < 8; j++)
			if (A[i][j] > 0) {
				B[A[i][j]]++;
				if (B[A[j][i]] > 2)
					return false;
			}
	return true;
}
bool rec(int x, int y) {
	if (cnt == 0) {
		if (y == 8) {
			if (x == 7) {
				cnt++;
				for (int i = 0; i < 8; i++) {
					for (int j = 0; j < 8; j++) {
						R[i][j] = A[i][j];
					}
				}
			}
			else {
				rec(x + 1, 0);
			}
		}
		else if (A[x][y] == 0) {
			for (int k = 1; k < 9; k++)
				if (checkSatis(x, y, k)) {
					A[x][y] = k;
					rec(x, y + 1);
					A[x][y] = 0;
				}
		}
		else if (A[x][y] != 0) {
			rec(x, y + 1);
		}
	}
	return (cnt > 0) ? true : false;
}
int tc=0;
void Weka() {
	tc++;
	cnt = 0;
	for (int i = 0; i < 64; i++) {
		int c;
		cin >> c;
		A[i / 8][i % 8] = c;
	}
	if (checkMatric()) {
		if (rec(0, 0)) {
			cout << "Test case #" << tc << ": YES" << endl;
			for (int i = 0; i < 8; i++) {
				for (int j = 0; j < 8; j++)
					cout << R[i][j] << " ";
				cout << endl;
			}
		}
		else
			cout << "Test case #" << tc << ": NO" << endl;
	}
	else
		cout << "Test case #" << tc << ": NO" << endl;
}
int main() {
	int t=1;
	cin >> t;
	while(t--) {
		Weka();
	}
	return 0;
}