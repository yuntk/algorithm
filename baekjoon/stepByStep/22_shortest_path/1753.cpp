/*
 * https://www.acmicpc.net/problem/1753
 * 방향그래프가 주어지면 주어진 시작점에서 다른 모든 정점으로의 최단 경로를 구하는 프로그램을 작성하시오. 단, 모든 간선의 가중치는 10 이하의 자연수이다.
 * 다익스트라 알고리즘(Dijkstra Algorithm)의 가장 기본적인 문제 우선순위 큐를 사용하지 않고 DP를 이용한 dfs방식으로 구현하면 시간초과가 생긴다.
 * 가장 거리가 먼 간선부터 검색을 시작하는 경우 다음간선에서 또 검색을 해야하고 이런 상황이 반복되면 최악의 경우 O(E^2)의 시간복잡도를 가지기 때문이다.
 * 이 부분이 가중치가 없이 bfs로 최단거리를 찾는 문제와 다른점이다. 이미 탐색을 마친부분이 낮은 가중치의 경우 다시 탐색을 하게 된다는 것
 * 따라서 우선순위 큐를 이용하여 시작점으로부터 가장 짧은 정점부터 탐색을 계속 이어가는 방법을 사용한다. 이렇게 하면 갱신이 일어나지 않도록 할 수 있다.
 *
 */

#include <iostream>
#include <vector>
#include <cstring>
#include <set>

using namespace std;

int vertexnum, edgenum, startnum;
int check[20000];
set<pair<int,int>> q;
vector<vector<pair<int,int>>> vertex;

void make_dist(int start){
    for(pair<int,int> v : vertex[start]){
        if(check[v.first] == -1 || (check[v.first] > (check[start] + v.second))){
            check[v.first] = check[start] + v.second;
            q.insert(make_pair(check[start] + v.second,v.first));
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin >> vertexnum >> edgenum >> startnum;
    memset(check,-1,sizeof(check));
    vertex.resize(vertexnum);
    int u, v, w;
    for (int i = 0; i < edgenum; ++i) {
        cin >> u >> v >> w;
        vertex[u-1].push_back(make_pair(v-1,w));
    }
    check[startnum-1] = 0;
    q.insert(make_pair(0,startnum-1));
    int index, dist;
    while(!q.empty()){
        dist = (*q.begin()).first;
        index = (*q.begin()).second;
        q.erase(q.begin());
        if(check[index] >= dist){
            check[index] = dist;
            make_dist(index);
        }
    }
    for (int i = 0; i < vertexnum; ++i) {
        if(check[i] == -1) cout << "INF\n";
        else cout << check[i] << "\n";
    }
}