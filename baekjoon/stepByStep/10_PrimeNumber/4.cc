//베르트랑 공준
//https://www.acmicpc.net/problem/4948

#include <iostream>

using namespace std;
bool arr[123456*2+1];

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

    int tmp,n;
    int count = 0;
    while(true){
        cin >> tmp;
        if(tmp == 0) break;
        count = 0;
        for(n = tmp + 1; n <= tmp*2; ++n){
            if(arr[n]) ++count;
        }
        cout << count << "\n";
    }

}