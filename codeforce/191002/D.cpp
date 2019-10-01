#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q;
    string s;
    cin >> s;
    cin >> q;
    int type;
    int indxA,indxB;
    char c;
    int count = 0;
    int arr[100000];
    memset(arr,0,sizeof(arr));
    int check[26];
    for (int i = 0; i < q; ++i) {
        cin >> type;
        if(type == 1){
            cin >> indxA >> c;
            s[indxA - 1] = c;
        }else{
            memset(check,0,sizeof(check));
            count = 0;
            cin >> indxA >> indxB;
            for (int j = indxA - 1; j < indxB; ++j) {
                ++check[s[j] - 'a'];
            }
            for(int j = 0; j < 26; ++j){
                if(check[j]) ++count;
            }
            cout << count << "\n";

        }
    }
}