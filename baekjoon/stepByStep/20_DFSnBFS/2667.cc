//https://www.acmicpc.net/problem/2667

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

int n;
int map[25][25];
int isVisit[25][25];
vector<int> result;

int search(int y, int x) {
	if (y < 0 || x < 0 || x >= n || y >= n) return 0;
	if (map[y][x] == 1 && isVisit[y][x] == 0) {
		isVisit[y][x] = 1;
		return 1 + search(y - 1, x) + search(y + 1, x) + search(y, x - 1) + search(y, x + 1);
	}
	return 0;
}

int main() {

	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%1d", &map[i][j]);
			isVisit[i][j] = 0;
		}
	}
	int tmp = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (map[i][j] == 1 && isVisit[i][j] == 0) {
				if ((tmp = search(i, j)) != 0) result.push_back(tmp);
			}
		}
	}
	sort(result.begin(), result.end());
	cout << result.size() << "\n";
	for (int i = 0; i < result.size(); ++i) cout << result[i] << "\n";

}

