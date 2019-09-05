//https://www.acmicpc.net/problem/1904

#include <iostream>

using namespace std;

int n;
int fir = 1,sec = 2;

int main(){
    cin >> n;
    if(n == 1) {
        cout << 1;
        return;
    }
    if(n == 2) {
        cout << 2;
        return;
    }
    for(int i = 3; i <= n; ++i){
        if(i%2 == 1){
            fir = (fir+sec) - (fir+sec)/15746;
        }else sec = (fir+sec) - (fir+sec)/15746;
    }
    cout << (n%2 == 1) ? fir : sec;

}