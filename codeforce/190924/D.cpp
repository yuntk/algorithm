//
// Created by qkdls on 2019-09-24.
//

#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
int n;
cin >> n;
long long q[7000];
long long skill[7000];
vector<set<int>> s(60);
int idx = 0, tmp;
    for (int i = 0; i < n; ++i) {
        cin >> q[i];
        tmp = q[i];
        idx = 0;
        while(tmp){
            if(tmp%2) s[idx].insert(i);
            idx++;
            tmp >> 1;
        }
    }
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> skill[i];
        sum += skill[i];
    }
    for(int i = 0; i < 60; ++i){
        if(s[i].size() == 1){

        }
    }




}