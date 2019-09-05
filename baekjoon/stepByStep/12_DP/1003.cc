#include <iostream>
#include <string.h>

using namespace std;
int memo[41];
int memoone[41];
int main(){
    memset(memo,0,sizeof(memo));
    int tcn,n;
    cin >> tcn;
    memo[0] = 1;
    memoone[0] = 0;
    memo[1] = 0;
    memoone[1] = 1;
    for(int i = 2; i <41; ++i){
        memo[i] = memo[i-1] + memo[i-2];
        memoone[i] = memoone[i-1] + memoone[i-2];
    }
    for(int i = 0; i < tcn; ++i){
        cin >> n;
        cout << memo[n] << " " << memoone[n] << "\n";
    }
}