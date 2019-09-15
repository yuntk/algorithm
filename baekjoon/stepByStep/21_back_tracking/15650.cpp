/*
 * https://www.acmicpc.net/problem/15650
 * 자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.
 *
 * 1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열
 * 고른 수열은 오름차순이어야 한다.
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
    }
    for (int i = pos; i < N; ++i) {
        list.push_back(i);
        dfs(i + 1, remain - 1, list);
        list.pop_back();
    }
}

int main() {
    cin >> N >> M;
    vector<int> list;
    dfs(0, M, list);
}