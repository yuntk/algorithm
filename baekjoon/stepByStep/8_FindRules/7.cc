//부녀회장이 될테야
//https://www.acmicpc.net/problem/2775
#include <iostream>

using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int a[15][15] = {{0,},};
    int n;
    cin >> n;
    int K,N;
    for(int i = 1; i < 15; ++i) a[0][i] = i;
    for(int i = 1; i < 15; ++i){
        for(int j = 1; j < 15; ++j){
            a[i][j] = a[i-1][j] + a[i][j-1];
        }
    }
    for(int i = 0; i < n; ++i){
        cin >> K >> N;
        cout << a[K][N] << endl;
    }
}