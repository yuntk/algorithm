#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q,n;
    string upper;
    string lower;
    bool upside = true;
    bool isVerticalward = false;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        cin >> n;
        cin >> upper >> lower;

        upside = true;
        isVerticalward = false;
        int j = 0;
        for (; j < n; ++j) {
            if(upside){
                if(upper[j]<='2'){
                    if(isVerticalward) break;
                }else{
                    if(isVerticalward){
                        upside = true;
                        isVerticalward = false;
                    }else{
                        upside = false;
                        isVerticalward = true;
                        --j;
                    }
                }
            }else{
                if(lower[j]<='2'){
                    if(isVerticalward) break;
                }else{
                    if(isVerticalward){
                        upside = false;
                        isVerticalward = false;
                    }else{
                        upside = true;
                        isVerticalward = true;
                        --j;
                    }
                }
            }
        }
        if(j == n && !upside) cout << "YES\n";
        else cout << "NO\n";
    }
}