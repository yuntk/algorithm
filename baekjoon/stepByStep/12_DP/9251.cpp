//LCS(https://www.acmicpc.net/problem/9251)
//LCS(Longest Common Subsequence, 최장 공통 부분 수열)문제는 두 수열이 주어졌을 때, 모두의 부분 수열이 되는 수열 중 가장 긴 것을 찾는 문제이다.
//
//예를 들어, ACAYKP와 CAPCAK의 LCS는 ACAK가 된다.
//메모이제이션을 하긴했는데 콜스택이 계속 길어짐, 가장 긴 부분을 저장해가면서 찾아야됨

#include <iostream>
#include <cstring>

using namespace std;

string fs, ss;
int fsize,ssize;
int cache[1000][1000];

int DP(int first,int second){
    if(first >= fsize || second >= ssize)return 0;
    int &ret = cache[first][second];
    if(ret != 0) return ret;

    if(fs[first] == ss[second]) ret = (1+DP(first+1,second+1));
    return ret = max(ret,max(DP(first+1,second) , DP(first,second+1)));
}

int main(){
    cin >> fs >> ss;
    fsize = fs.size();
    ssize = ss.size();
    memset(cache,0,sizeof(cache));
    DP(0,0);
    cout << cache[0][0];
}