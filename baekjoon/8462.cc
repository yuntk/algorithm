//TODO : 시간초과 mo's algorithm을 적용시켜야함

#include <iostream>
#include <cstring>

using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int n,t;
    int arr[100000];
    int pool[1000001];
    cin >> n >> t;
    for(int i = 0; i < n; ++i) cin >> arr[i];
    int begin,end;
    long long result;
    for(int i = 0; i < t; ++i) {
        cin >> begin >> end;
        memset(pool, 0, sizeof(pool));
        for(int j = begin-1; j < end; ++j) {
            ++pool[arr[j]];
        }
        result = 0;
        for(int j = 0; j < 1000001; ++j){
            result += pool[j] * pool[j] * j;
        }
        cout << result << '\n';
    }
}