#include <iostream>
#include <queue>
#include <tuple>
#include <string.h>
#include <vector>
#include <stdio.h>

using namespace std;
int Yl, Xl;
int graph[1000][1000];
int isVisit[1000][1000];
int isVisitBW[1000][1000];
int movey[] = { 1, -1, 0, 0 };
int movex[] = { 0, 0, 1, -1 };

queue<int> q;

void bfs(int y, int x, int step, int BW){
	if (y < 0 || x < 0 || y >= Yl || x >= Xl) return;
	if (BW == 0){//아직 벽 통과 x
		if (graph[y][x] == 1){
			if (isVisitBW[y][x] == -1){
				isVisitBW[y][x] = step;
				for (int i = 0; i < 4; ++i){
					q.push(y + movey[i]);
					q.push(x + movex[i]);
					q.push(step + 1);
					q.push(1);
				}
			}
			return;
		}
		else{
			if (isVisit[y][x] == -1){
				isVisit[y][x] = step;
				for (int i = 0; i < 4; ++i){
					q.push(y + movey[i]);
					q.push(x + movex[i]);
					q.push(step + 1);
					q.push(BW);
				}
			}
			return;
		}
	}
	else if(BW == 1){//이미 벽을 통과한 케이스
		if (graph[y][x] == 1) return;
		else if(isVisitBW[y][x] == -1){
			isVisitBW[y][x] = step;
			for (int i = 0; i < 4; ++i){
				q.push(y + movey[i]);
				q.push(x + movex[i]);
				q.push(step + 1);
				q.push(BW);
			}
		}
		return;

	}
}

int main(){
	memset(graph, -1, sizeof(graph));
	memset(isVisit, -1, sizeof(isVisit));
	memset(isVisitBW, -1, sizeof(isVisitBW));

	cin >> Yl >> Xl;
	for (int i = 0; i < Yl; ++i){
		for (int j = 0; j < Xl; ++j){
			scanf("%1d", &graph[i][j]);
		}
	}

	q.push(0);
	q.push(0);
	q.push(1);
	q.push(0);
	int x, y, step, BW;
	while (!q.empty()){
		y = q.front(); q.pop();
		x = q.front(); q.pop();
		step = q.front(); q.pop();
		BW = q.front(); q.pop();
		bfs(y, x, step, BW);

	}

	if (isVisit[Yl - 1][Xl - 1] == -1){
		cout << isVisitBW[Yl - 1][Xl - 1];
	}
	else if (isVisitBW[Yl - 1][Xl - 1] == -1){
		cout << isVisit[Yl - 1][Xl - 1];
	}
	else
		cout << ((isVisit[Yl - 1][Xl - 1] >= isVisitBW[Yl - 1][Xl - 1]) ? isVisitBW[Yl - 1][Xl - 1] : isVisit[Yl - 1][Xl - 1]);
}