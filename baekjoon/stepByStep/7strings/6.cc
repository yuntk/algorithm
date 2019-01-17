//상수
//https://www.acmicpc.net/problem/2908
#include <iostream>

using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    string a,b;
    int n_a, n_b;
    cin >> a >> b;
    n_a = (a[2]-'0')*100 + (a[1]-'0')*10 + (a[0]-'0');
    n_b = (b[2]-'0')*100 + (b[1]-'0')*10 + (b[0]-'0');
    cout << (n_a > n_b ? n_a : n_b);
    
}
