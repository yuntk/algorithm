//벌집
//https://www.acmicpc.net/problem/2292
#include <iostream>

using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    unsigned int n;
    cin >> n;
    unsigned int sum = 1;
    for(int i = 0; i <= 1000000000; ++i){
        sum += i*6;
        if(n <= sum){
            cout << i+1;
            return 0;
        }
    }
}