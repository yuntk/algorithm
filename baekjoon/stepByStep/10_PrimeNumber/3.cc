//소수구하기
//https://www.acmicpc.net/problem/1929

#include <iostream>

using namespace std;
bool arr[1000001];

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

    int n,m;
    cin >> n >> m;

    int sum = 0;
    for(;n <= m; n++){
        if(arr[n]) cout << n << "\n";
    }
}