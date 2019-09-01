//https://www.acmicpc.net/problem/2606

#include <vector>
#include <iostream>


using namespace std;

void dfs(int index, vector<vector<int>>& graph);
int isVisit[101];
    
int main(){
    vector<vector<int>> graph;
    int nOfComputer, nOfPair;
    int v1,v2;
    cin >> nOfComputer;
    cin >> nOfPair;
    fill_n(isVisit,101,0);
    graph.resize(nOfComputer+1);
    for(int i = 0; i < nOfPair; ++i){
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    dfs(1,graph);
    int count = 0;
    for(int a : isVisit){
        count += a;
    }
    cout << count - 1;

}

void dfs(int index, vector<vector<int>>& graph){
    if(isVisit[index] != 0) return;
    isVisit[index] = 1;
    for(int i = 0; i < graph[index].size(); ++i){
        dfs(graph[index][i], graph);
    }
    
}