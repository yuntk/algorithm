//골드바흐의 추측
//https://www.acmicpc.net/problem/9020

#include <iostream>

using namespace std;
bool arr[10001];

int main()
{
    ios::sync_with_stdio(false);

    fill_n(arr,sizeof(arr)/sizeof(bool),true);
    arr[1] = false;
    for(int i = 2; i < sizeof(arr)/sizeof(bool); i++){
        if(arr[i]){
            for(int j = 2; i*j < sizeof(arr)/sizeof(bool); j++){
                arr[i*j] = false;
            }
        }
    }

    int n, tmp;
    cin >> n;
    int count = 0;
    int rst_fir, rst_sec;
    for(int i = 0; i < n; ++i){
        cin >> tmp;
        for(int j = 2; j <= tmp/2; ++j){
            if(arr[j] && arr[tmp - j]) {
                rst_fir = j;
                rst_sec = tmp-j;
            }
        }
        cout << rst_fir << " " << rst_sec << "\n";
    }
}