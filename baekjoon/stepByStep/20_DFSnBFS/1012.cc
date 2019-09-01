//https://www.acmicpc.net/problem/1012

#include <iostream>

using namespace std;
int testnum, xsize, ysize, casenum, x, y;
int v[50][50];
int isVisit[50][50];
int result;
int dfs(int y, int x) {
	if (x < 0 || y < 0 || x >= xsize || y >= ysize) return 0;
	if (isVisit[y][x] == 1 || v[y][x] == 0) return 0;

	isVisit[y][x] = 1;
	return 1 + dfs(y - 1, x) + dfs(y + 1, x) + dfs(y, x - 1) + dfs(y, x + 1);
}
int main() {
	cin >> testnum;

	for (int i = 0; i < testnum; ++i) {
		cin >> xsize >> ysize >> casenum;
		result = 0;
		for (int j = 0; j < ysize; ++j) {
			for (int k = 0; k < xsize; ++k) {
				v[j][k] = 0;
				isVisit[j][k] = 0;
			}
		}

		for (int j = 0; j < casenum; ++j) {
			cin >> x >> y;
			v[y][x] = 1;
		}
		for (int j = 0; j < ysize; ++j) {
			for (int k = 0; k < xsize; ++k) {
				if (dfs(j, k) > 0) result++;
			}
		}
		cout << result << "\n";
	}
}