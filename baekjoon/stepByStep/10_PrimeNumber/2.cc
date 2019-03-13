//소수
//https://www.acmicpc.net/problem/2581

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
    int result = -1;
    int sum = 0;
    for(;n <= m; n++){
        if(arr[n] && result == -1) result = n;
        if(arr[n]) sum += n;
    }
    if(result != -1) cout << sum << endl << result;
    else cout << -1;

}
