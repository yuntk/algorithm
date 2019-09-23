//
// Created by qkdls on 2019-09-23.
//

#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a[4];
    for (int i = 0; i < 4; ++i) {
        cin >> a[i];
    }
    bool ans = false;
    int sum;
    for (int i = 0; i < 4; ++i) {
        sum = 0;
        for (int j = 0; j < 4; ++j) {
            if(i != j){
                sum += a[j];
            }
        }
        if(a[i] == sum){
            ans = true;
            break;
        }
    }
    int b[6];
    int idx = 0;
    for (int i = 0; i < 4; ++i) {
        for(int j = i+1; j < 4; ++j){
            b[idx] = a[i]+a[j];
            idx++;
        }
    }
    for(int i = 0 ; i < 6; i++){
        for(int j = 0 ; j < 6; j++){
            if(i!=j){
                if(b[j] == b[i]){
                    ans = true;
                    break;
                }
            }
        }
    }
    if(ans) cout << "YES";
    else cout << "NO";

}