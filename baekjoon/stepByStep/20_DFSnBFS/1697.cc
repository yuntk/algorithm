//https://www.acmicpc.net/problem/1697

#include <iostream>
#include <queue>
#include <tuple>
#include <string.h>

using namespace std;
int N, K;
int arr[100001];
queue<tuple<int,int>> q; //pos,step
int result = -1;

void BFS(int pos, int step){
	if (pos < 0 || pos > 100000) return;
	else if (pos == K){
		result = step;
	} else if (arr[pos] == -1){
		arr[pos] = step;
		q.push(make_tuple(pos + 1, step + 1));
		q.push(make_tuple( pos * 2, step + 1));
		q.push(make_tuple(pos -1, step + 1));
	}
}

int main(){
	memset(arr, -1, sizeof(arr));
	cin >> N >> K;
	q.push(make_tuple(N, 0));
	while (result == -1 && !q.empty())
	{
		BFS(get<0>(q.front()), get<1>(q.front()));
		q.pop();
	}
	cout << result;
}