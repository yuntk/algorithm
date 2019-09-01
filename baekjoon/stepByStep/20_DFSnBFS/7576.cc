//https://www.acmicpc.net/problem/7576

#include <iostream>
#include <stdio.h>
#include <list>
#include <utility>
#include <string.h>

int numOfZero = 0;
int mday = 0;
int arr[1000][1000];
int day[1000][1000];
int ysize, xsize;
using namespace std;
list<pair<int,int>> q;

void bfs(pair<int, int> pos, int pday) {
	if (pos.first < 0 || pos.second < 0 || pos.first >= ysize || pos.second >= xsize) return;
	if (arr[pos.first][pos.second] == -1 || arr[pos.first][pos.second] == 1) return;
	q.push_back(pos);
	arr[pos.first][pos.second] = 1;
	day[pos.first][pos.second] = pday + 1;
	numOfZero--;
	if (pday + 1 > mday) mday = pday + 1;
}

int main() {
	cin >> xsize >> ysize;
	memset(arr, 0, sizeof(arr));
	memset(day, 0, sizeof(day));
	for (int i = 0; i < ysize; ++i) {
		for (int j = 0; j < xsize; ++j) {
			cin >> arr[i][j];
			if (arr[i][j] == 0) numOfZero++;
			else if (arr[i][j] == 1) {
				q.push_back(make_pair(i, j));
			}
		}
	}
	if (numOfZero == 0) {
		cout << 0;
		return 0;
	}
	while (!q.empty())
	{
		bfs(make_pair(q.front().first - 1, q.front().second), day[q.front().first][q.front().second]);
		bfs(make_pair(q.front().first + 1, q.front().second), day[q.front().first][q.front().second]);
		bfs(make_pair(q.front().first, q.front().second - 1), day[q.front().first][q.front().second]);
		bfs(make_pair(q.front().first, q.front().second + 1), day[q.front().first][q.front().second]);
		q.pop_front();
	}
	if (numOfZero > 0) {
		cout << -1;
		return 0;
	}
	else cout << mday;
}