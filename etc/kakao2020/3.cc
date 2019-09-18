#include <string>
#include <vector>

#include <iostream>
using namespace std;

int getkeyval(vector<vector<int>>& key, int movey, int movex, int y,int x) { //열쇠 움직이고 자물쇠 좌표 y,x로 받았을 때 해당하는 열쇠 값
	int size = key.size();
	int newy = movey + y;
	int newx = movex + x;
	if (newy < 0 || newx < 0 || newy >= size || newx >= size) return 0;
	else return key[newy][newx];
}

vector<vector<int>> rotatekey(vector<vector<int>> key) {
	int MAX = key[0].size();
	for (int i = 0; i < MAX / 2; i++)
		for (int j = i; j < MAX - 1 - i; j++)
		{
			int Top = key[i][j];
			key[i][j] = key[MAX - 1 - j][i];
			key[MAX - 1 - j][i] = key[MAX - 1 - i][MAX - 1 - j];
			key[MAX - 1 - i][MAX - 1 - j] = key[j][MAX - 1 - i];
			key[j][MAX - 1 - i] = Top;
		}
	return key;
}


bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	vector<vector<int>> keyone = rotatekey(key);
	vector<vector<int>> keytwo = rotatekey(keyone);
	vector<vector<int>> keythr = rotatekey(keytwo);
	int keysize = key.size();
	int locksize = lock.size();

	bool test = false;
	for (int i = -locksize; i < keysize; ++i) {
		for (int j = -locksize; j < keysize; ++j) {

			test = true;
			for (int y = 0; y < locksize; ++y) {
				for (int x = 0; x < locksize; ++x) {
					if ((getkeyval(key, i, j, y, x) + lock[y][x]) == 1);
					else test = false;
				}
			}
			if (test) return true;
		}
	}

	for (int i = -locksize; i < keysize; ++i) {
		for (int j = -locksize; j < keysize; ++j) {

			test = true;
			for (int y = 0; y < locksize; ++y) {
				for (int x = 0; x < locksize; ++x) {
					if ((getkeyval(keytwo, i, j, y, x) + lock[y][x]) == 1);
					else test = false;
				}
			}
			if (test) return true;
		}
	}


	for (int i = -locksize; i < keysize; ++i) {
		for (int j = -locksize; j < keysize; ++j) {

			test = true;
			for (int y = 0; y < locksize; ++y) {
				for (int x = 0; x < locksize; ++x) {
					if ((getkeyval(keyone, i, j, y, x) + lock[y][x]) == 1);
					else test = false;
				}
			}
			if (test) return true;
		}
	}

	for (int i = -locksize; i < keysize; ++i) {
		for (int j = -locksize; j < keysize; ++j) {

			test = true;
			for (int y = 0; y < locksize; ++y) {
				for (int x = 0; x < locksize; ++x) {
					if ((getkeyval(keythr, i, j, y, x) + lock[y][x]) == 1);
					else test = false;
				}
			}
			if (test) return true;
		}
	}


	return false;
}

/*
int main() {
	
	vector<vector<int>> key = {{0, 0, 0}, {1, 0, 0}, {0, 1, 1}};
	vector<vector<int>> lock = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
	
	bool ans = solution(key,lock);
	cout << ans;

}*/