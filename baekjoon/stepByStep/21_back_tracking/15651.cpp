/*
 * https://www.acmicpc.net/problem/15651
 * 자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.
 *
 * 1부터 N까지 자연수 중에서 M개를 중복 허용하여 고른 수열
 * 고른 수열은 오름차순이어야 한다. 사전순
 *
 * : dfs, backtracking
 */

#include <iostream>
#include <vector>

using namespace std;

int N, M;

void dfs(int pos, int remain, vector<int> &list) {
    if (remain == 0) {
        for (int i : list) cout << i + 1 << ' ';
        cout << "\n";
        return;
    }
    for (int i = 0; i < N; ++i) {
        list.push_back(i);
        dfs(i , remain - 1, list);
        list.pop_back();
    }
}

int main() {
    cin >> N >> M;
    vector<int> list;
    dfs(0, M, list);
}