//소수 찾기
//https://www.acmicpc.net/problem/1978

#include <iostream>

using namespace std;
int main()
{
    bool arr[1001];
    fill_n(arr,1001,true);
    arr[1] = false;
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int x;
    for(int i = 2; i < 501; ++i){
        if(!arr[i]) continue;
        x = i*2;
        while(x <= 1000){
            arr[x] = false;
            x += i;
        }
    }
    int count = 0;
    int tmp = 0;
    for(int i = 0; i < n; ++i){
        cin >> tmp;
        if(arr[tmp]) count++;
    }
    cout << count;
}
