//ACM호텔
//https://www.acmicpc.net/problem/10250

#include <iostream>

using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int W,H,N;
    for(int i = 0; i < n; ++i){
        cin >> H >> W >> N;
        if((N-1)/H+1 < 10) cout << (N-1)%H+1 << '0' << (N-1)/H+1 << endl;
        else cout << (N-1)%H+1 << (N-1)/H+1 << endl;
    }
}