//분수찾기
//https://www.acmicpc.net/problem/1193

#include <iostream>

using namespace std;
int main()
{
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    int sum = 0;
    for(int i = 1; i <= 5000; ++i){
        sum += i;
        if(n <= sum){
            if(i%2 == 0){
                cout << n-sum+i << "/" << sum - n + 1;
                break;
            }else{
                cout << sum - n + 1 << "/" << n-sum+i;
                break;
            }
        }
    }
}