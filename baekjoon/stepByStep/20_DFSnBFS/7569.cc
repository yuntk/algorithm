//https://www.acmicpc.net/problem/7569

#include <iostream>
#include <stdio.h>
#include <list>
#include <utility>
#include <string.h>
#include <tuple>

using namespace std;

int arr[100][100][100];
int dist[100][100][100];
int zL, yL, xL;
int mDay = 0;
int numOfZero = 0;

list<tuple<int,int,int>> q;

void bfs(int z, int y, int x, int pdist) {
	if (z < 0 || y < 0 || x < 0 || z >= zL || y >= yL || x >= xL) return;
	if (arr[z][y][x] == 1 || arr[z][y][x]== -1) return;
	q.push_back(make_tuple(z, y, x));
	arr[z][y][x] = 1;
	dist[z][y][x] = pdist + 1;
	if (pdist + 1 > mDay) mDay = pdist + 1;
	numOfZero--;
}

int main() {
	memset(arr, 0, sizeof(arr));
	memset(dist, 0, sizeof(dist));
	cin >> xL >> yL >> zL;
	for (int i = 0; i < zL; ++i) {
		for (int j = 0; j < yL; ++j) {
			for (int k = 0; k < xL; ++k) {
				cin >> arr[i][j][k];
				if (arr[i][j][k] == 1)q.push_back(make_tuple(i,j,k));
				else if (arr[i][j][k] == 0) numOfZero++;
			}
		}
	}

	if (numOfZero == 0) {
		cout << 0;
		return 0 ;
	}

	while (!q.empty())
	{
		bfs(get<0>(q.front()) - 1, get<1>(q.front()), get<2>(q.front()), dist[get<0>(q.front())][get<1>(q.front())][get<2>(q.front())]);
		bfs(get<0>(q.front()) +1, get<1>(q.front()), get<2>(q.front()), dist[get<0>(q.front())][get<1>(q.front())][get<2>(q.front())]);
		bfs(get<0>(q.front()), get<1>(q.front())-1, get<2>(q.front()), dist[get<0>(q.front())][get<1>(q.front())][get<2>(q.front())]);
		bfs(get<0>(q.front()), get<1>(q.front())+1, get<2>(q.front()), dist[get<0>(q.front())][get<1>(q.front())][get<2>(q.front())]);
		bfs(get<0>(q.front()), get<1>(q.front()), get<2>(q.front())-1, dist[get<0>(q.front())][get<1>(q.front())][get<2>(q.front())]);
		bfs(get<0>(q.front()), get<1>(q.front()), get<2>(q.front())+1, dist[get<0>(q.front())][get<1>(q.front())][get<2>(q.front())]);
		q.pop_front();

	}
	if (numOfZero > 0) {
		cout << -1;
	}
	else cout << mDay;
}