/*
 *
 */
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;



 //first is dist, second is dest
int dist[801];

void shortest_path(int start,priority_queue<pair<int, short>> &pq, vector<vector<pair<short, short>>> &graph) {
    for (auto v : graph[start]) {
        if (dist[v.first] == -1 || dist[v.first] > dist[start] + v.second) {
            dist[v.first] = dist[start] + v.second;
            pq.push(make_pair(-dist[v.first], v.first));
        }
    }
}

int main() {
    priority_queue<pair<int, short>> pq;
    vector<vector<pair<short, short>>> graph;
    int vertex_num, edge_num;
    cin >> vertex_num >> edge_num;
    int a, b, c;
    graph.resize(vertex_num + 1);
    for (int i = 0; i < edge_num; ++i) {
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(b, c));//first is dest, second is dist
        graph[b].push_back(make_pair(a, c));
    }
    int destA, destB;
    cin >> destA >> destB;
    memset(dist, -1, sizeof(dist));
    pq.push(make_pair(0, 1));
    dist[1] = 0;
    while (!pq.empty()) {
        if (-pq.top().first <= dist[pq.top().second]) shortest_path(pq.top().second, pq, graph);
        pq.pop();
    }

    int stoA = dist[destA];
    int stoB = dist[destB];


    memset(dist, -1, sizeof(dist));
    pq.push(make_pair(0, destA));
    dist[destA] = 0;
    while (!pq.empty()) {
        if (-pq.top().first <= dist[pq.top().second]) shortest_path(pq.top().second, pq, graph);
        pq.pop();
    }
    int atob = dist[destB];
    int atof = dist[vertex_num];


    memset(dist, -1, sizeof(dist));
    pq.push(make_pair(0, destB));
    dist[destB] = 0;
    while (!pq.empty()) {
        if (-pq.top().first <= dist[pq.top().second]) shortest_path(pq.top().second, pq, graph);
        pq.pop();
    }
    int btoa = dist[destA];
    int btof = dist[vertex_num];

    long long abf = 80000000;
    long long baf = 80000000;
    if (stoA != -1 && atob != -1 && btof != -1) abf = stoA + atob + btof;
    if (stoB != -1 && btoa != -1 && atof != -1) baf = stoB + btoa + atof;
    if (abf == 80000000 && baf == 80000000) {
        cout << -1;
    } else {
        cout << min(abf, baf);
    }

}