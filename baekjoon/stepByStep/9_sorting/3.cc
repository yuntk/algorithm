//수 정렬하기3
//https://www.acmicpc.net/problem/10989

#include <iostream>

int arr[10001] = {0,};
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int n,tmp;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> tmp;
        arr[tmp]++;
    }
    tmp = 1;
    for(int i = 0; i < n; ++i){
        if(arr[tmp] > 0) {
            cout << tmp << '\n';
            --arr[tmp];
        }else{
            --i;
            ++tmp;
        }
    }
}