//https://www.acmicpc.net/problem/2178

#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <utility>
#include <string.h>

using namespace std;
int maze[100][100];
int dist[100][100];
int ysize, xsize;
queue<pair<int,int>> q;

void bfs(int y, int x, int distance) {
	if (x < 0 || y < 0 || x >= xsize || y >= ysize) return;
	if (dist[y][x] == 0 && maze[y][x] == 1) {
		dist[y][x] = distance + 1;
		q.push(make_pair(y, x));
	}
	return;
}

int main() {
	memset(maze, 0, sizeof(maze));
	memset(dist, 0, sizeof(dist));
	cin >> ysize >> xsize;
	for (int i = 0; i < ysize; ++i) {
		for (int j = 0; j < xsize; ++j) {
			scanf("%1d", &maze[i][j]);
		}
	}

	q.push(make_pair(0, 0));
	dist[0][0] = 1;
	while (!q.empty())
	{
		bfs(q.front().first - 1, q.front().second, dist[q.front().first][q.front().second]);
		bfs(q.front().first + 1, q.front().second, dist[q.front().first][q.front().second]);
		bfs(q.front().first, q.front().second -1, dist[q.front().first][q.front().second]);
		bfs(q.front().first, q.front().second +1, dist[q.front().first][q.front().second]);
		q.pop();
	}
	cout << dist[ysize - 1][xsize - 1];

}